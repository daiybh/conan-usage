function conan_buildLib {
    echo "buildLibs... $PWD"
    conan create . -s build_type=Debug
    if($lastExitCode -eq 0){
        conan create . -s build_type=Release        
    }            
}

function conan_buildApp{
    echo "buildApps...  $PWD"
    rmdir build -Recurse -Force
    conan install . --output-folder=build\win --build=missing -s build_type=Debug
    if($lastExitCode -ne 0){
        return
    }
    conan install . --output-folder=build\win --build=missing -s build_type=Release
    if($lastExitCode -ne 0){
        return
    }
    cmake --preset conan-default
    if($lastExitCode -ne 0){
        return
    }
    cmake --build --preset="conan-debug"
    if($lastExitCode -ne 0){
        return
    }    
    cmake --build --preset="conan-release"    
}


function buildAll{
    param($isApp)
    pushd .
    $destFolder = ".\Libraries"

    if($isApp){
        $destFolder = ".\Apps"
    }
    
    ##遍历子目录
    $allSubdirs = Get-ChildItem -path $destFolder  -Directory
     foreach ($currentItemName in $allSubdirs) {
        echo "build [$currentItemName]..."

        pushd .
        cd $currentItemName
        if($isApp){
            conan_buildApp
        }else {
            conan_buildLib
        }
        popd
        
        if($lastExitCode -ne 0){
            echo "****************************"
            echo "build [$currentItemName] failed. code: $lastExitCode"            
            echo "****************************"
            break
        }     
    }     
    echo "build $destFolder  over."
    popd
}

cls
write-host "build type: $args"

pushd .
$b=$args[0]
if($b -eq "lib" -or $b -eq "all"){
    buildAll($false)
}
if($b -eq "app" -or $b -eq "all"){
    buildAll($true)
}
popd