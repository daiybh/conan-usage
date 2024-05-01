function conan_buildLib {
    echo "buildLibs..."
    conan create . -s build_type=Debug
    if($lastExitCode -eq 0){
        conan create . -s build_type=Release        
    }        
    echo $lastExitCode
}

function conan_buildApp{
    echo "buildApps..."
    rmdir build -Recurse -Force
    conan install . --output-folder=build --build=missing -s build_type=Debug
    if($lastExitCode -ne 0){
        return
    }
    conan install . --output-folder=build --build=missing -s build_type=Release
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

function buildOne {
    param ($path,$isApp)
    pushd .
    cd $path
    if($isApp){
        conan_buildApp
    }else {
        conan_buildLib
    }
    popd
}

function buildAll{
    param($isApp)
    pushd .
    if($isApp){
        cd .\Apps
    }
    else {
        cd .\Libraries
    }
    ##遍历子目录
    $allSubdirs = Get-ChildItem -Directory
     foreach ($currentItemName in $allSubdirs) {
        echo "build [$currentItemName]..."
        buildOne $currentItemName $isApp;
        if($lastExitCode -ne 0){
            echo "****************************"
            echo "build [$currentItemName] failed. code: $lastExitCode"            
            echo "****************************"
            break
        }     
    }     
    echo "buildLibs over."
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