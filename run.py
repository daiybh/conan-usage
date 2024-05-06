import os
import subprocess
import shutil
from contextlib import contextmanager
import time
import sys

def run(cmd, error=False):
    print("Running: {}".format(cmd))
    start_time = time.time()

    process = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, shell=True, text=True)

    output = ''
    stdout,stderr= process.communicate()
    print(stdout)

    
    
    #for line in iter(process.stdout.readline, ''):
    #    print(line, end='', flush=True)
    #    output += line

    ret = process.wait()
    end_time = time.time()
    
    elapsed_time = end_time - start_time
    print(f"Elapsed time: {elapsed_time:.2f} seconds")

    if ret != 0 and not error:
        raise Exception(f"Failed cmd: {cmd}\n{output}")
    if ret == 0 and error:
        raise Exception(f"Cmd succeeded (failure expected): {cmd}\n{output}")

    return output


def conan_buildLib():
    run("conan create . -s build_type=Debug")
    run("conan create . -s build_type=Release")

def conan_buildApp():
    run("rmdir build -Recurse -Force")
    run("conan install . --output-folder=build --build=missing -s build_type=Debug")
    run("conan install . --output-folder=build --build=missing -s build_type=Release")
    run("cmake --preset conan-default")
    run("cmake --build --preset=\"conan-debug\"")
    run("cmake --build --preset=\"conan-release\"")





def run_main():
    #如果传入参数是 lib  那么就遍历libraries 目录,只遍历到第一级目录
    #如果传入参数是 app  那么就遍历Apps 目录,只遍历到第一级目录
    # 进入到每个子目录执行 conan_buildLib
    if len(sys.argv) == 1:        
        cmd_out = run("conan list \"*\"")
        print(cmd_out)

    if len(sys.argv) == 2:
        enumDirs=""

        if sys.argv[1] == "lib":
            enumDirs = "libraries"
        elif sys.argv[1] == "app":
            enumDirs = "Apps"
        original_dir = os.getcwd()

        for item in os.listdir(enumDirs):
            item_path = os.path.join(enumDirs, item)
            print(item_path)            
            os.chdir(item_path)
            conan_buildLib()
            os.chdir(original_dir)
                
if __name__ == "__main__":
    run_main()