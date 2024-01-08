cmake_minimum_required(VERSION 3.10)
project(Oblivion)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenSSL REQUIRED)

add_executable(Oblivion main.cpp blockchain.cpp block.cpp crypto/sha256.cpp launch.cpp transaction.cpp utils/isBlockValid.cpp utils/isTransactionValid.cpp)

target_include_directories(Oblivion PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Oblivion OpenSSL::SSL)

add_custom_target(run
   COMMAND Oblivion
   DEPENDS Oblivion
   WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)