enable_testing()
find_package(GTest REQUIRED)
file(GLOB_RECURSE TEST_SOURCES ${CMAKE_SOURCE_DIR}/tests/*.cpp)
include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(ArmSpaceTests ${TEST_SOURCES})
target_link_libraries(ArmSpaceTests PRIVATE
    GTest::GTest
    GTest::Main
    Eigen3::Eigen
    nlohmann_json::nlohmann_json
    validator_lib
)
add_test(NAME ArmSpaceTests COMMAND ArmSpaceTests)
