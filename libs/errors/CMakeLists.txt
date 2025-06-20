file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS *.h *.hpp)

add_library(errors_lib ${SRC_FILES} ${HEADER_FILES})

target_include_directories(errors_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})