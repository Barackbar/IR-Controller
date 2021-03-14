cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(IR_Controller VERSION 0.1)

configure_file(config/config.hh.in include/config/config.hh)

# Add Utils library to eventually link the executable against
add_library(${PROJECT_NAME}-Utils
            src/utils/utils.cpp)
# Point the Utils library to its corresponding include directory
target_include_directories(${PROJECT_NAME}-Utils PUBLIC
                           include/utils)

# Create our executable from the main source file
add_executable(${PROJECT_NAME}.out
               src/main.cpp)
# Link this executable against our utils library
target_link_libraries(${PROJECT_NAME}.out PUBLIC
                      ${PROJECT_NAME}-Utils)
# Point this executable to all the includes
target_include_directories(${PROJECT_NAME}.out PUBLIC
                           ${PROJECT_BINARY_DIR}
                           include)
