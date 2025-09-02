cmake_minimum_required(VERSION 3.0)

project(demo)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC)
#collect .cpp
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
#search .h
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(main ${SRC})
#.exe
find_library(M_SHARED match_shared ${CMAKE_CURRENT_SOURCE_DIR}/LIB)
find_library(M_STATIC match_static ${CMAKE_CURRENT_SOURCE_DIR}/LIB)
set_target_properties(main PROPERTIES LINK_FLAGS "-Wl,-rpath='${CMAKE_CURRENT_SOURCE_DIR}/LIB'" )
target_link_libraries(main ${M_SHARED})
install(TARGETS main 
        RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/INSTALL/bin
)
install()        









