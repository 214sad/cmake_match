#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "manage.h"
#include "student.h"
#include "teacher.h"
#include <sstream>
#include <iomanip>
// Function to read student data from file
void Manage::StuReadFile(std::vector<Student> &stu)
{
    std::ifstream ifs;
    ifs.open("2025_student.txt", std::ios::in); // Read file
    if (!ifs.is_open())
    {
        std::cout << "文件打开失败" << std::endl;
        return;
    }
    std::string line;
     getline(ifs, line);
    while (getline(ifs, line))
    {   
        std::istringstream ss(line);
       // Student s;
        int id;
        int score;
        std::string name;
        std::string major;
        std::string tutor1;
        std::string tutor2;
        std::string tutor3; // Assuming tutor3 is also part of the input

       if(ss>> id >> name >> major >> score >> tutor1 >> tutor2 >> tutor3)
        {

       Student s(id, name, major, score, tutor1, tutor2, tutor3);//想一下，
       stu.push_back(s);
        } 
        

    }
    ifs.close();
    
     std::ofstream ofs;
    ofs.open("student_test.txt", std::ios::out);
    //测试学生信息
       for(std::vector<Student>::iterator it = stu.begin(); it != stu.end(); it++)
       {
        ofs<<std::left<<it->GetId()<<std::left <<std::setw(16)<< it->GetName() << std::setw(16)<<std::left << it->GetMajor()<<std::setw(16)
                <<std::left << it->GetScore() <<std::setw(16) << it->GetTutor1()<<std::setw(16)<<std::left << it->GetTutor2() <<std::setw(16)<<std::left<<it->GetTutor3()<<std::endl;
       }
       ofs.close();
    
   
}
// Function to read teacher data from file
void Manage::TeaReadFile(std::vector<Teacher> &teac)
{
    std::ifstream ifs;
    ifs.open("2025_teacher.txt", std::ios::in); // Read file
    if (!ifs.is_open())
    {
        std::cout << "文件打开失败" << std::endl;
        return;
    }
    std::string line;
    getline(ifs, line);
    while (getline(ifs, line))
    {
        std::stringstream ss(line);
       
        int id;
        int number;
        std::string name;
        std::string major;
         ss >> id >> name >> major >> number;
        Teacher te(id, name, major, number); // Create a Teacher object with an empty vector of students
        teac.push_back(te);
    }
    ifs.close();
    
    std::ofstream ofs;
    ofs.open("teacher_test.txt", std::ios::out);
    //测试教师信息
    for (std::vector<Teacher>::iterator it = teac.begin(); it != teac.end(); it++)
    {
        ofs <<std::setw(8) << it->GetId()<<" " <<std::setw(8) << it->GetName()<<" " << std::setw(8)  << it->GetMajor() <<" "<< std::setw(8) 
            << it->GetNumber() << std::endl;
    }
    ofs.close();
    
    
}
void Manage::Match(std::vector<Student> &stu, std::vector<Teacher> &teac)
{
    std::vector<Student> Fir;
    // int count=0;
    std::sort(stu.begin(), stu.end(), []( Student &a,  Student &b)
              {
                  return a.GetScore() > b.GetScore(); // 按照分数降序排列
              });
    // std::ofstream ofs;

    // same major
    for (std::vector<Teacher>::iterator it = teac.begin(); it != teac.end(); it++)
    {
        for (std::vector<Student>::iterator j = stu.begin(); j != stu.end(); j++)
        {
            if (it->GetName()==j->GetTutor1())
            {
                if (it->Has() == false)
                {
                    break;
                }
                it->GetStudents().push_back(*j);
              //  it->m_students.push_back(*j);
                Fir.push_back(*j);
                stu.erase(j);
                j--;
                // count++;
            }
        }
    }
    for (std::vector<Teacher>::iterator it = teac.begin(); it != teac.end(); it++)
    {
        for (std::vector<Student>::iterator j = stu.begin(); j != stu.end(); j++)
        {
            if (it->GetName()==j->GetTutor2())
            {
                if (it->Has() == false)
                {
                    break;
                }
                it->GetStudents().push_back(*j);
              //  it->m_students.push_back(*j);
                Fir.push_back(*j);
                stu.erase(j);
                j--;
                // count++;
            }
        }
    }
    for (std::vector<Teacher>::iterator it = teac.begin(); it != teac.end(); it++)
    {
        for (std::vector<Student>::iterator j = stu.begin(); j != stu.end(); j++)
        {
            if (it->GetName()==j->GetTutor3())
            {
                if (it->Has() == false)
                {
                    break;
                }
                it->GetStudents().push_back(*j);
              //  it->m_students.push_back(*j);
                Fir.push_back(*j);
                stu.erase(j);
                j--;
                // count++;
            }
        }
    }

    // different major
    /*
    for (std::vector<Teacher>::iterator it = teac.begin(); it != teac.end(); it++)
    {
        for (std::vector<Student>::iterator j = stu.begin(); j != stu.end(); j++)
        {
                if (it->Has() == false)
                {
                    break;
                }
                it->GetStudents().push_back(*j);
               // it->m_students.push_back(*j);
                Fir.push_back(*j);
                stu.erase(j);
                j--;
                // count++;
            
        }
    }

    */
    
    //------------------------------------------------------//
    /*
 std::ofstream ofs;
    ofs.open("01student.txt", std::ios::out);
    if (!ofs.is_open())
    {
        std::cout << "文件打开失败" << std::endl;
        return;
    }
    else
    {
        for (std::vector<Teacher>::iterator it = teac.begin(); it != teac.end(); it++)
        {
            ofs << "----------------教师信息----------------" << std::endl;
            ofs << it->m_id << " " << it->m_name << " " << it->m_major << " " << it->m_number << std::endl;
            ofs << "----------------学生信息----------------" << std::endl;

            for (std::vector<Student>::iterator j=it->m_students.begin();j!=it->m_students.end(); j++)
            {
                ofs << j->m_id << " " << j->m_name << " " << j->m_major << " " << j->m_score << " " << j->m_tutor1 << " " << j->m_tutor2 << std::endl;
            }
        }
    }
    if (!stu.empty())
    {
        ofs << "----------------剩余学生信息----------------" << std::endl;
        for (std::vector<Student>::iterator j = stu.begin(); j != stu.end(); j++)
        {
            ofs << j->m_id << " " << j->m_name << " " << j->m_major << " " << j->m_score << " " << j->m_tutor1 << " " << j->m_tutor2 << std::endl;
        }
    }
    ofs.close();
    */
   
}
