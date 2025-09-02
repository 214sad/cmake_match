#pragma once
#include <iostream>
#include "person.h"
#include "vector"
class Student : public Person
{
private:
    int m_score;
    std::string m_tutor1;
    std::string m_tutor2;
    std::string m_tutor3;

public:
    int GetScore();
    void SetScore(int score);
    void SetTutor1( std::string &tutor1) ;
    std::string GetTutor1() ;
    void SetTutor2( std::string &tutor2) ;
    std::string GetTutor2() ;
    //std::string GetTutor1();
    //有参构造函数
    void SetTutror3(std::string &tutor3);
    std::string GetTutor3();
    Student(int id, std::string name, std::string major, int score, std::string tutor1, std::string tutor2,std::string tutor3);
    Student();
};
