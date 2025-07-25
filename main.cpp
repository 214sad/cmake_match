#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "manage.h"
#include "student.h"
#include "teacher.h"
#include <sstream>
#include <iomanip>
int main()
{
    Manage m;
    std::vector<Student> stu;
    std::vector<Teacher> teac;
    // Read student and teacher data from files
    m.StuReadFile(stu);
    m.TeaReadFile(teac);
    // Match students with teachers based on their major
    m.Match(stu, teac);
    // Write the matched data to a file
    std::ofstream ofs("2025_matched_data03.txt", std::ios::out);
    if (!ofs.is_open())
    {
        std::cout << "文件打开失败" << std::endl;
        return 1;
    }
    for (auto &teacher : teac)
    {
        if (!teacher.GetStudents().empty())
        {
            //ofs << "----------------教师信息----------------" << std::endl;
            ofs<<std::left <<std::setw(16)<< teacher.GetId() <<std::setw(16) << teacher.GetName() << std::setw(16) << teacher.GetMajor() << std::setw(16)<<teacher.GetNumber() << std::endl;
            ofs << teacher.GetName()<<"老师招收的学生信息:" << std::endl;
            for (auto &student : teacher.GetStudents())
            {
                ofs <<std::left<<std::setw(16)<< student.GetId() << std::setw(16) << student.GetName() << std::setw(16) << student.GetMajor() << std::setw(16)
                    << student.GetScore() << std::endl;
            }
            ofs << "****************************************" << std::endl;
        }  
    }
    // 导师名额信息
    ofs << "----------------教师名额信息----------------" << std::endl;
    for (auto &teacher : teac)
    {
        int cc;
        cc = teacher.GetNumber() - teacher.GetStudents().size();
        if (cc)

            if (cc > 0)
                ofs << teacher.GetName() << "还有" << cc << "个名额" << std::endl;
    }
    if (!stu.empty())
    {
        ofs << "----------------剩余学生信息----------------" << std::endl;
        for (auto &student : stu)
        {
            ofs<<std::left<<std::setw(16)
                << student.GetId() << std::setw(16)
                << student.GetName()  << std::setw(16)
                << student.GetMajor() << std::setw(16)
                << student.GetScore() 
                << std::endl;
        }
    }
    ofs.close();

    return 0;
}