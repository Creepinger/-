#include "Management.h"
#include<iostream>
using namespace std;
void Management::run()
{    
	//��ȡ�˵��ķ���ֵ
	int op = Menu;
	
	while (true)
	{
			op = menu();
			switch (op)
			{
			case Management::Display:
				display();
				break;
			case Management::Add:
				add();
				break;
			case Management::Erase:
				erase();
				break;
			case Management::Modify:
				modify();
				break;
			case Management::Search:
				search();
				break;
			default:
				break;
			}

	}
	
	}

int Management::menu()
{
	//���ݰ�ť�ĵ�������ز���
	
	cout << "menu" << endl;
	int op = 0;
	cin >> op;
	return op;
}

void Management::display()
{
	cout << "display" << endl;
}

void Management::add()
{
	cout << "add" << endl;
}

void Management::erase()
{
	cout << "erase" << endl;
}

/*��3��	�ṩÿ�ſγ̵ĳɼ�������
 �����š������С����񡢲�����5���ȼ�����
 ����ͳ�ơ���������ӡ�ɼ�������*/

void Management::simple_sort(float score,Grade &g)
{
	int A=0, B=0, C=0, D=0, E=0;
	if (score > 100 || score < 0) cout << "��������д���" << endl;
	if (score >= 90 && score <= 100) { cout << "��" <<endl; g.A++; }
	if (score >= 80 && score < 90) { cout << "��" << endl; g.B++;}
	if (score >= 70 && score < 80) { cout << "��" << endl; g.C++; }
	if (score >= 60 && score < 70) { cout << "����" << endl; g.D++; }
	if (score >= 0 && score < 60) { cout << "������" << endl; g.E++; }

}
/*idea:���ܻ���Ҫ��һ��ͳ�Ʋ�ͬ�ȵ��������࣬
Ȼ�����¿�һ�������������*/
void Management::analyse(Grade g)
{
	cout << "���š�������" << g.A << endl;
	cout << "������������" << g.B << endl;
	cout << "���С�������" << g.C << endl;
	cout << "����������������" << g.D << endl;
	cout << "������������������" << g.E << endl;
}

void Management::modify()
{
	cout << "modify" << endl;
}

void Management::search()
{
	cout << "search" << endl;
}
void Management::statisticsStudent()
{
	//ͳ��ѧ��������
	/*  Node* curNode=list->front
	while(currNode!=NULL)
	{
	count++;
	curNode=curNode->N
	}*/
}