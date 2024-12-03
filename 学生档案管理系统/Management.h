//������ֻСè�ܱ�������벻����
// ��˵ллСè
//�������� ���� �ߣ�
//������ ��������������
//������ ����| ��_�� _ l
//�� ���� ����` �ߣ�x��
//���� �� /������ �� |
//������ /�� �c���� ?
//�� �� ������|��|��|
//������|���� |��|��|
//��| (���c��_�c_)__)
//���ܶ��� 
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


/*C++ STL�� fstream ��һ�������ļ���д�����࣬
�����Է���ض��ļ����������������*/
using namespace std;
typedef int Status;



class Management
{
	//����enum��ö�٣�����������ť
	enum Operator
	{
		Display,
		Add,
		Erase,
		Modify,
		Search,
		Menu=66
	};


		
		

	//ѧ����Ϣ

	/*
	//ѧ���ɼ��ȵ�����ͳ��
	typedef struct Grade
	{
		int A, B, C, D, E;
	}Grade;
	//ѧ����Ϣ���ܱ�
	typedef struct StudentList
	{
		Student stu;
		struct StudentList* next;//ָ����һ������ָ��

	}StudentList;
	*/
		
public:

	//������������
	void run();

	//�˵�
	int menu();
	//1.��ʾ���е�ѧ��
	void display();
	
	//2.���ѧ��
	void add();

	/*3.���ѧ���ɼ�*/

	//4.ɾ��ѧ��
	void erase();

	//������ȡ�ĵ���ѧ����Ϣ
	void readFile(const string& fileName);
	//5.��Ҫ������
	void writeFile(const string& fileName, int numStudents);
	void simple_sort(float score,Grade& g);
	//6.ͳ��
	Status get_score();
	Status analysis(Status numStudents, Status numCourses, Status courseIndex);
	//7.�޸�
	void modify();
	//8.����
	void search();
	void statisticsStudent();

	// ���� << �����
	friend ostream& operator<<(ostream& os, const Student& stu)
	{
		// ��� Student ��Ϣ����ʽΪ name, Math, Physics
		os << stu.name << "," << stu.Math << "," << stu.Physics;
		return os;
	}

};


class Student
{
public:
	Student() :number(0), hm(0), ds(0), english(0) {}//�޲����Ĺ��캯��������һ�����������Ҫ�ṩ�κγ�ʼֵ
	Student(unsigned int num, std::string n, std::string c, float h, float d, float e) :
		number(num), name(n), class_name(c), hm(h), ds(d), english(e) {}

	unsigned int number;//ѧ��С��(2^32-1)ʱʹ�ã���string��ʡ�ڴ�ռ�
	string name;
	string class_name;
	float Math;
	float Physics;
	float DataStructure;
	float Object_Oriented;
};