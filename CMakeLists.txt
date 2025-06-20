cmake_minimum_required(VERSION 3.20)
project(ArmSpace LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/usr/local/lib/cmake")
find_package(nlohmann_json_schema_validator REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(Eigen3 QUIET)


add_subdirectory(libs/errors)
#add_subdirectory(libs/parser)
#add_subdirectory(libs/writer)
#add_subdirectory(libs/engine)
add_subdirectory(libs/validator)
add_subdirectory(cli)
add_subdirectory(tests)

enable_testing()
