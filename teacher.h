#pragma once
#include <iostream>
#include "person.h"
#include"student.h"
#include <vector>
class Teacher:public Person
{
private:
    std::vector<Student> m_students; // 存储学生信息
    int m_number;
public:
    bool Has();
    void SetNumber(int number);
    int GetNumber();
    std::vector<Student> &GetStudents() ;
    void SetStudents( std::vector<Student> &students);
    // 有参构造函数
    Teacher(int id,std::string name, std::string major, int number);
    Teacher();
};
    
    
    