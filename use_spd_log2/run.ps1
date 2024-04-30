function buildMylib{
    cd myloglib
    conan create . -s build_type=Debug
    conan create . -s build_type=Release
    cd ..
}

function buildApp{
   
cd use_myloglib
conan install . --output-folder=build --build=missing -s build_type=Debug

cmake --preset conan-default

cmake --build --preset="conan-debug"
cd ..
}

write-host "build type: $args"


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