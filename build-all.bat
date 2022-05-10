@echo off

pushd engine
call build-engine.bat
popd

if %ERRORLEVEL% NEQ 0 (
    echo error build engine: %ERRORLEVEL% && exit
)

pushd sandbox
call build-sandbox.bat
popd

if %ERRORLEVEL% NEQ 0 (
    echo error build sandbox: %ERRORLEVEL% && exit
)

echo "Build all OK"
