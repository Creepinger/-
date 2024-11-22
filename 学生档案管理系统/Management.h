#pragma once
#define ERROR 0;

//学生信息结构
typedef struct Student
{
	char name[32];
	unsigned long long num;
	float Math;
	float Physics;
	float DataStructure;
	float Object_Oriented;


}Student;
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

	//5.按要求排序
	void simple_sort(float score,Grade& g);
	//6.统计
	void analyse(Grade g);
	//7.修改
	void modify();
	//8.查找
	void search();
	void statisticsStudent();


};


