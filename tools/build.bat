
conan install . --output-folder=build --build=missing -pr=default
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE="$(Get-Location)\conan_toolchain.cmake" -DCMAKE_BUILD_TYPE=Debug
cmake --build . --config Debug


D:\dev-env\Python\Python311\Lib\site-packages\cmake\data\bin\cmake.EXE -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_INSTALL_PREFIX:STRING=d:/code/TodoCalen/install -DCMAKE_PREFIX_PATH:STRING=D:/dev-env/Qt/6.8.3/msvc2022_64/lib/cmake -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE --no-warn-unused-cli -S D:/code/TodoCalen -B d:/code/TodoCalen/build -G Ninja