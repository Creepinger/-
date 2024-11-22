#pragma once
#define ERROR 0;

//ѧ����Ϣ�ṹ
typedef struct Student
{
	char name[32];
	unsigned long long num;
	float Math;
	float Physics;
	float DataStructure;
	float Object_Oriented;


}Student;
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

	//5.��Ҫ������
	void simple_sort(float score,Grade& g);
	//6.ͳ��
	void analyse(Grade g);
	//7.�޸�
	void modify();
	//8.����
	void search();
	void statisticsStudent();


};


