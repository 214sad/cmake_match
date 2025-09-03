set_target_properties(test PROPERTIES INSTALL_RPATH "../lib" )  
//这是可执行文件的路径


打开2025_student.txt 2025_teacher.txt 文件的路径不是manage.cpp路径而是可执行文件路径
要么复制这两个文件在INSTALL 要么修改manage.cpp代码 ofs("../../2025_student.txt")
