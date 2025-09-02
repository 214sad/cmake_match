cmake_minimum_required(VERSION 3.0)

project(demo)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(main ${SRC})
install(TARGETS  main
         RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/INSTALL
   )

