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
	Student() :number(0), hm(0), ds(0), english(0) {}//�޲����Ĺ��캯��������һ�����������Ҫ�ṩ�κγ�ʼֵ
	Student(unsigned int num, std::string n, std::string c, float h, float d, float e) :
		number(num), name(n), class_name(c), hm(h), ds(d), english(e) {}
public:
	unsigned int number;//ѧ��С��(2^32-1)ʱʹ�ã���string��ʡ�ڴ�ռ�
	std::string name;
	std::string class_name;
	float hm;
	float ds;
	float english;
};
class Student
{
public:
	//�ع�
	//ѧ����Ϣ��ѧ�� ���� �༶
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

