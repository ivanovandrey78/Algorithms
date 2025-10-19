file(GLOB_RECURSE ALG_SOURCES "*.cpp")
file(GLOB_RECURSE ALG_HEADERS "*.h" "*.hpp")

add_library(algorithms_lib ${ALG_SOURCES} ${ALG_HEADERS})
target_include_directories(algorithms_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})