#pragma once
#include"Configure.h"
using namespace std;
using uint32 = unsigned int;
class Student
{
public:
	//重构
	//学生信息：学号 姓名 班级
	Student(uint32 number, const std::string& name, 
		const std::string& grade, float Math, float Physics,
		float DataStructure,float Object_Oriented);
public:
	uint32 number;
	string name;
	string grade;
	float Math;
	float Physics;
	float DataStructure;
	float Object_Oriented;

};

