@echo off
chcp 65001 > nul

setlocal
set BUILD_DIR=build
set SOURCE_DIR=project

echo [1/4] otchistka staroi sborki...
if exist "%BUILD_DIR%" rmdir /s /q "%BUILD_DIR%"

echo [2/4] generacia projecta...
cmake -B "%BUILD_DIR%" -G Ninja -S "%SOURCE_DIR%"
if %errorlevel% neq 0 (
    echo ERROR: CMake generation failed
    pause
    exit /b 1
)

echo [3/4] sborka projecta...
cmake --build "%BUILD_DIR%"
if %errorlevel% neq 0 (
    echo ERROR: Build failed
    pause
    exit /b 1
)

echo [4/4] zapusk projecta...
cd "%BUILD_DIR%"
ctest --output-on-failure
if %errorlevel% neq 0 (
    echo ERROR: Tests failed
    pause
    exit /b 1
)

echo SUCCESS: All stages completed
pause
endlocal