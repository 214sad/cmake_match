cmake_minimum_required(VERSION 3.0)
project(demo)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/INSTALL)

#aux_source_directory(src SRC)

include_directories(include)

add_library(match_shared SHARED src/manage.cpp src/student.cpp src/teacher.cpp)

add_executable(test src/main.cpp )
#test.exe

set_target_properties(test PROPERTIES INSTALL_RPATH "../lib" )

target_link_libraries(test match_shared)

install(TARGETS test match_shared 
     RUNTIME DESTINATION bin
     LIBRARY DESTINATION lib
)
install(FILES
      ${PROJECT_SOURCE_DIR}/2025_student.txt 
      ${PROJECT_SOURCE_DIR}/2025_teacher.txt
      DESTINATION bin
)






