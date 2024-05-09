function conan_buildLib() {
    echo "buildLibs... $(pwd)"
    conan create . -s build_type=Debug
    if [ $? -eq 0 ]; then
        conan create . -s build_type=Release
    fi
}
function conan_buildApp() {
    echo "buildApps...  $PWD"
    rm -rf build
    conan install . --output-folder=build/linux --build=missing -s build_type=Debug
    if [ $? -ne 0 ]; then
        return
    fi
    conan install . --output-folder=build/linux --build=missing -s build_type=Release
    if [ $? -ne 0 ]; then
        return
    fi
    cmake --preset conan-debug
    if [ $? -eq 0 ]; then
        cmake --build . --preset="conan-debug"    
        if [ $? -ne 0 ]; then
            return
        fi    
    fi
    
    
    cmake --preset conan-release
    if [ $? -ne 0 ]; then
        return
    fi
    cmake --build . --preset="conan-release"
}

function buildAll() {
    local isApp=$1
    pushd .
    local destFolder="./Libraries"

    if [ "$isApp" = "true" ]; then
        destFolder="./Apps"
    fi

    # 遍历子目录
    for currentItemName in $(ls -d $destFolder/*/); do
        echo "build [$currentItemName]..."

        pushd .
        cd $currentItemName
        if [ "$isApp" = "true" ]; then
            conan_buildApp
        else
            conan_buildLib
        fi
        popd

        if [ $? -ne 0 ]; then
            echo "****************************"
            echo "build [$currentItemName] failed. code: $?"
            echo "****************************"
            break
        fi
    done
    echo "build $destFolder over."
    popd
}

pushd .
b=$1
if [[ "$b" == "lib" || "$b" == "all" ]]; then
    buildAll false
fi
if [[ "$b" == "app" || "$b" == "all" ]]; then
    buildAll true
fi
popd