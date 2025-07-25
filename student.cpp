#include <iostream>
#include "person.h"
#include "student.h"
#include <vector>
#include <fstream>
#include<algorithm>
#include <sstream>
void Student::SetScore(int score) {
    m_score = score;
}
int Student::GetScore() {
    return m_score;
}
void Student::SetTutor1( std::string &tutor1) {
    m_tutor1 = tutor1;
}
std::string Student::GetTutor1()  {
    return m_tutor1;
}
void Student::SetTutor2( std::string &tutor2) {
    m_tutor2 = tutor2;
}
std::string Student::GetTutor2()  {
    return m_tutor2;
}
void Student::SetTutror3(std::string &tutor3) {
    m_tutor3 = tutor3;
}
std::string Student::GetTutor3() {
    return m_tutor3;
}
Student::Student(int id, std::string name, std::string major, int score, std::string tutor1, std::string tutor2, std::string tutor3)
{
    
    Person::SetId(id);//
    Person::SetName(name);
    Person::SetMajor(major);
    m_score = score;
    m_tutor1 = tutor1;
    m_tutor2 = tutor2;
    m_tutor3 = tutor3;
    //在类的成员函数内部（比如构造函数），你可以直接调用同类的其他成员函数，不需要加类名前缀。这是 C++ 的基本规则
    
}   
Student::Student()
{
}

