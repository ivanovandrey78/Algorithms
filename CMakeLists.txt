# Корневой CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указание исходных файлов
set(SOURCES
    src/main.cpp
    src/functions.cpp
    src/sorts.cpp
    src/pyramid.cpp
)

# Указание заголовочных файлов
set(HEADERS
    include/functions.h
    include/sorts.h
    include/pyramid.hpp
)

# Создание исполняемого файла
add_executable(app ${SOURCES} ${HEADERS})

# Включение директории с заголовками
target_include_directories(app PRIVATE include)

# Установка выходной директории (опционально)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)