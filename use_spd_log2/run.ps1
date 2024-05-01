function buildMylib{
    cd myloglib
    conan create . -s build_type=Debug
    echo $lastExitCode
    if($lastExitCode -ne 0){
        cd ..
        return
    }
    conan create . -s build_type=Release
    echo $lastExitCode
    cd ..
}

function buildApp{   
    cd use_myloglib
    conan install . --output-folder=build --build=missing -s build_type=Debug
    cmake --preset conan-default
    cmake --build --preset="conan-debug"
    cd ..
}
cls
write-host "build type: $args"

pushd .
$b=$args[0]

if($b -eq "lib"){
    buildMylib
}

if($b -eq "app"){
    buildApp
}

if($b -eq "all"){
    buildMylib
    buildApp
}

popd