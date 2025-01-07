#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student
{
public:

	Student();

	Student(std::string n, int a, char g, float gr) :
		m_Name(n), m_Age(a), m_Gender(g), m_Grade(gr) {};

	const std::string getName() const { return m_Name; }
	const int getAge() const { return m_Age; }
	const char getGendedr() const { return m_Gender; }
	const float getGrade() const { return m_Grade; }

	void setName(std::string name) { m_Name = name; }
	void setAge(int age) { m_Age = age; }
	void setGendedr(char gender) { m_Gender = gender; }
	void setGrade(float grade) { m_Grade = grade; }

private:
	std::string m_Name;
	int			m_Age;
	char		m_Gender;
	float		m_Grade;
};