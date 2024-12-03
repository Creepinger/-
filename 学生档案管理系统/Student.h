#pragma once
#include"Configure.h"
using namespace std;
using uint32 = unsigned int;
#pragma once
#include<string>
#include<vector>
class Student
{
public:
	Student() :number(0), hm(0), ds(0), english(0) {}//无参数的构造函数允许创建一个对象而不需要提供任何初始值
	Student(unsigned int num, std::string n, std::string c, float h, float d, float e) :
		number(num), name(n), class_name(c), hm(h), ds(d), english(e) {}
public:
	unsigned int number;//学号小于(2^32-1)时使用，比string节省内存空间
	std::string name;
	std::string class_name;
	float hm;
	float ds;
	float english;
};
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

