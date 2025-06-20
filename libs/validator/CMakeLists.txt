file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS *.h *.hpp)

add_library(validator_lib ${SRC_FILES} ${HEADER_FILES})

target_link_directories(validator_lib PUBLIC
    /usr/local/lib
)
add_library(nlohmann_json_schema_validator STATIC IMPORTED)
set_target_properties(nlohmann_json_schema_validator PROPERTIES
    IMPORTED_LOCATION_DEBUG /usr/local/lib/libnlohmann_json_schema_validator.a
    IMPORTED_LOCATION_RELEASE /usr/local/lib/libnlohmann_json_schema_validator.a
    IMPORTED_LOCATION_RELWITHDEBINFO /usr/local/lib/libnlohmann_json_schema_validator.a
    IMPORTED_LOCATION_MINSIZEREL /usr/local/lib/libnlohmann_json_schema_validator.a
    INTERFACE_INCLUDE_DIRECTORIES /usr/local/include
)

target_include_directories(validator_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(validator_lib PUBLIC
    nlohmann_json::nlohmann_json
    errors_lib
    nlohmann_json_schema_validator
)
