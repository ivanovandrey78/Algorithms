file(GLOB_RECURSE STRUCT_SOURCES "*.cpp")
file(GLOB_RECURSE STRUCT_HEADERS "*.h" "*.hpp")

add_library(structures_lib ${STRUCT_SOURCES} ${STRUCT_HEADERS})
target_include_directories(structures_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})