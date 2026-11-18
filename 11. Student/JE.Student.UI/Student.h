#pragma once
#include <string>
#include <iostream>

class Student
{
private:
	//attributes
	std::string m_name;
	float m_gpa;

public:
	//Default Constructor
	Student() : m_name("Unknown"), m_gpa(0.0f) {}
	Student(const std::string& name, float gpa) : m_name(name), m_gpa(gpa) {}

	//Mutators
	void setName(const std::string& name)
	{
		m_name = name;
	}

	void setGPA(float gpa)
	{
		m_gpa = gpa;
	}

	//Accessors
	std::string getName() const
	{
		return m_name;
	}

	float getGpa() const
	{
		return m_gpa;
	}

	void display() const
	{
		std::cout << "Name: " << m_name;
		std::cout << "\nGPA: " << m_gpa;
	}

};