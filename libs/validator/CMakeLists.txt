file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS *.h *.hpp)

#find_package(nlohmann_json_schema_validator REQUIRED)

add_library(validator_lib ${SRC_FILES} ${HEADER_FILES})

target_include_directories(validator_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    /usr/local/include
)
add_library(nlohmann_json_schema_validator STATIC IMPORTED GLOBAL)

set_target_properties(nlohmann_json_schema_validator PROPERTIES
    IMPORTED_LOCATION "/usr/local/lib/libnlohmann_json_schema_validator.a"
    INTERFACE_INCLUDE_DIRECTORIES "/usr/local/include"
)

target_link_libraries(validator_lib PUBLIC
    nlohmann_json::nlohmann_json
    nlohmann_json_schema_validator
    errors_lib
)
