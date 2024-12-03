//摸摸这只小猫能保佑你代码不报错
// 快说谢谢小猫
//　　　　 　　 ＿＿
//　　　 　　／＞　　フ
//　　　 　　| 　_　 _ l
//　 　　 　／` ミ＿xノ
//　　 　 /　　　 　 |
//　　　 /　 ヽ　　 ?
//　 　 │　　|　|　|
//　／￣|　　 |　|　|
//　| (￣ヽ＿_ヽ_)__)
//　＼二つ 
#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include <iomanip>
#include "Student.h"
#define OK 1
#define OVERFLOW -2
#define ERROR 0;


/*C++ STL中 fstream 是一种用于文件读写的流类，
它可以方便地对文件进行输入输出操作*/
using namespace std;
typedef int Status;



class Management
{
	//利用enum（枚举）类型制作按钮
	enum Operator
	{
		Display,
		Add,
		Erase,
		Modify,
		Search,
		Menu=66
	};


		
		

	//学生信息

	/*
	//学生成绩等第人数统计
	typedef struct Grade
	{
		int A, B, C, D, E;
	}Grade;
	//学生信息汇总表
	typedef struct StudentList
	{
		Student stu;
		struct StudentList* next;//指向下一个结点的指针

	}StudentList;
	*/
		
public:

	//启动“管理”类
	void run();

	//菜单
	int menu();
	//1.显示所有的学生
	void display();
	
	//2.添加学生
	void add();

	/*3.添加学生成绩*/

	//4.删除学生
	void erase();

	//补：读取文档内学生信息
	void readFile(const string& fileName);
	//5.按要求排序
	void writeFile(const string& fileName, int numStudents);
	void simple_sort(float score,Grade& g);
	//6.统计
	Status get_score();
	Status analysis(Status numStudents, Status numCourses, Status courseIndex);
	//7.修改
	void modify();
	//8.查找
	void search();
	void statisticsStudent();

	// 重载 << 运算符
	friend ostream& operator<<(ostream& os, const Student& stu)
	{
		// 输出 Student 信息，格式为 name, Math, Physics
		os << stu.name << "," << stu.Math << "," << stu.Physics;
		return os;
	}

};


class Student
{
public:
	Student() :number(0), hm(0), ds(0), english(0) {}//无参数的构造函数允许创建一个对象而不需要提供任何初始值
	Student(unsigned int num, std::string n, std::string c, float h, float d, float e) :
		number(num), name(n), class_name(c), hm(h), ds(d), english(e) {}

	unsigned int number;//学号小于(2^32-1)时使用，比string节省内存空间
	string name;
	string class_name;
	float Math;
	float Physics;
	float DataStructure;
	float Object_Oriented;
};