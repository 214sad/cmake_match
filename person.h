#pragma once
#include <iostream>
class Person
{
private:
    int m_id;
    std::string m_name;
    std::string m_major;
    public:
    void SetId(int id) {
        m_id = id;
    }
    void SetName(std::string name) {
        m_name = name;
    }
    void SetMajor(std::string major) {
        m_major = major;
    }
    int GetId() {
        return m_id;
    }
    std::string GetName() {
        return m_name;
    }
    std::string GetMajor() {
        return m_major;
    }
};