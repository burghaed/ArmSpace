file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS *.h *.hpp)

set(SCHEMES_DIR ${CMAKE_SOURCE_DIR}/schemes)
file(GLOB SCHEMA_FILES "${SCHEMES_DIR}/*.json")
set(GENERATED_DIR ${CMAKE_BINARY_DIR}/generated_schemas)
message(STATUS "GENERATED_DIR = ${GENERATED_DIR}")
foreach(SCHEMA_FILE ${SCHEMA_FILES})
    message(STATUS "SCHEMA_FILES = ${SCHEMA_FILES}")
    get_filename_component(SCHEMA_NAME ${SCHEMA_FILE} NAME_WE)
    set(OUT_HEADER "${GENERATED_DIR}/${SCHEMA_NAME}.h")
    message(STATUS "OUT_HEADER = ${OUT_HEADER}")
    add_custom_command(
        OUTPUT ${OUT_HEADER}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${GENERATED_DIR}
        COMMAND xxd -i ${SCHEMA_FILE} > ${OUT_HEADER}
                DEPENDS ${SCHEMA_FILE}
        COMMENT "Embedding ${SCHEMA_NAME}.json as ${OUT_HEADER}"
    )

    list(APPEND EMBEDDED_HEADERS ${OUT_HEADER})
endforeach()

add_library(validator_lib ${SRC_FILES} ${HEADER_FILES} ${EMBEDDED_HEADERS})

add_custom_target(embed_schemas DEPENDS ${EMBEDDED_HEADERS})
add_dependencies(validator_lib embed_schemas)

target_include_directories(validator_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${GENERATED_DIR}
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
