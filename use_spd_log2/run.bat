
set BASEDIR=%~dp0

:buildMyLogLib
PUSHD %BASEDIR%
cd myloglib
conan create . -s build_type=Debug

popd
goto:eof


cd ../use_myloglib
conan install . --output-folder=build --build=missing -s build_type=Debug

cmake --preset conan-default

cmake --build --preset="conan-debug"

popd