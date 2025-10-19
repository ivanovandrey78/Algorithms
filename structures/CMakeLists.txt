file(GLOB_RECURSE STRUCT_SOURCES "*.cpp") 
file(GLOB_RECURSE STRUCT_HEADERS "*.h")

add_library(structures_lib ${STRUCT_SOURCES} ${STRUCT_HEADERS})

target_include_directories(structures_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}  
)

add_library(structures ALIAS structures_lib)