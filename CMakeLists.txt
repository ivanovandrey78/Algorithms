cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включаем поддиректории
add_subdirectory(algorithms)
add_subdirectory(structures)

# Главный исполняемый файл
add_executable(app main.cpp)

# Линкуем с нашими библиотеками
target_link_libraries(app PRIVATE algorithms_lib structures_lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)