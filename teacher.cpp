#include <iostream>
#include "teacher.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
bool Teacher::Has()
{
   
    return m_students.size()< m_number; // 检查学生数量是否小于允许的数量
}
void Teacher::SetNumber(int number) {
    m_number = number;
}
int Teacher::GetNumber() {
    return m_number;
}
std::vector<Student> &Teacher::GetStudents() {
    return m_students;
}
void Teacher::SetStudents( std::vector<Student> &students) {
    m_students = students;
}
Teacher::Teacher(int id, std::string name, std::string major, int number) {
    SetId(id);
    SetName(name);
    SetMajor(major);
    m_number = number;
   // m_students = students; // Initialize the vector of students
}
Teacher::Teacher() {
   
}

