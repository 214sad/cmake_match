#pragma once
#include <iostream>
#include <vector>
#include "student.h"
#include "teacher.h"
class Manage
{
public:
    std::vector<Student> stu;
    std::vector<Teacher> teac;
    Student s1;
    Teacher tt;
    void StuReadFile(std::vector<Student> &stu);
    void TeaReadFile(std::vector<Teacher> &teac);
    void Match(std::vector<Student> &stu, std::vector<Teacher> &teac);
};