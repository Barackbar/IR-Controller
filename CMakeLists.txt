cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(IR-Controller VERSION 0.1)

configure_file(${PROJECT_NAME}-Config.hh.in include/config/config.hh)

# Add Utils library to eventually link the executable against
add_library(${PROJECT_NAME}-Utils
            src/utils/utils.cpp)
# Point the Utils library to its corresponding include directory
target_include_directories(${PROJECT_NAME}-Utils PUBLIC
                           include/utils)

# Create our executable from the main source file
add_executable(${PROJECT_NAME}
               src/main.cpp)
# Link this executable against our utils library
target_link_libraries(${PROJECT_NAME} PUBLIC
                      ${PROJECT_NAME}-Utils)
# Point this executable to all the includes
target_include_directories(${PROJECT_NAME} PUBLIC
                           include)
