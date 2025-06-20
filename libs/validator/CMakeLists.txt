file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS *.h *.hpp)

add_library(validator_lib ${SRC_FILES} ${HEADER_FILES})

target_include_directories(validator_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
   /usr/local/include/
)

target_link_directories(validator_lib PUBLIC
    /usr/local/lib
)

target_link_libraries(validator_lib PUBLIC
    nlohmann_json::nlohmann_json
    errors_lib
    libnlohmann_json_schema_validator.a
)