cmake_minimum_required(VERSION 3.14)
project(ArmSpaceProject VERSION 0.1.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Eigen3 REQUIRED)
find_package(nlohmann_json REQUIRED)

add_subdirectory(src)
add_subdirectory(tests)

enable_testing()
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS ArmSpaceTests
)
