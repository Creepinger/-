#include "Management.h"
#include<iostream>
#include<string>
#include<limits>
#include<vector>
/*numeric_limits �Ƕ����� <limits> ͷ�ļ��еģ���ˣ����û�а�����ͷ�ļ����������ᱨ��
��Ϊ�޷�ʶ�� numeric_limits<streamsize>::max()��*/

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

void Management::readFile(const string& fileName)
{
	fstream read(fileName, ios::in);//�á�(ios::in)ֻ��ģʽ����ָ��·�����ļ������ļ����ж�ȡ����
	if (!read.is_open())
	{
		cerr << fileName << "open failed" << endl;
		return;

	}//��Ҫ��ȡ���ļ���ʧ��
	string line;
	cout << "File content of " << fileName << ":\n";

	// ���ж�ȡ�ļ����ݲ����
	while (getline(read, line)) {
		cout << line << endl;  // ���ÿһ�е�����
	}
	read.close();//�ļ��ر�

}//�ļ���ȡ���򿪣�

void Management::writeFile(const string& fileName,int numStudents)
{
	fstream outfile(fileName, ios::app);//ios::app ��׷��ģʽ
	if (!outfile.is_open())
	{
		cerr << fileName << "open failed" << endl;
		return ;
	}//��Ҫ��д���ļ���ʧ��
	
	
	

	// ��ȡѧ������
	for (int i = 0; i < numStudents; ++i) {
		Student stu;
		cout << "Enter details for student " << i + 1 << " (name,Math score,Physics score): ";
		cin >> stu.name >> stu.Math >> stu.Physics;

		while (stu.Math || stu.Physics)
		{
			cout << "Invalid input for Math score. Please enter an integer: ";
			cin.clear();  // ��������־
			cin.ignore(numeric_limits<streamsize>::max(),'\n'); // ���Ե�ǰ�е�ʣ������
		}
		// ��ѧ����Ϣд���ļ�
		outfile << stu << endl;//������������ص� << �����
	}


	outfile.close(); // �ر��ļ�
	cout << "Data written to " << fileName << " successfully." << endl;
}
		
		


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
Status Management:: get_score()
{

	Status numStudents, numCourses, courseIndex;

	cout << "������ѧ������: ";
	cin >> numStudents;

	cout << "������γ�����: ";
	cin >> numCourses;

	cout << "������Ҫ�鿴�Ŀγ����� (���磺0Ϊ�������γ̣�1Ϊ���ݽṹ����������): ";
	cin >> courseIndex;

	if (courseIndex<0 || courseIndex > numCourses)
	{
		cout << "�ÿγ̲�����" << endl;
		return ERROR;
	}
	//ͳ��ѧ���ɼ����
	analysis(numStudents, numCourses, courseIndex);
	return OK;
}
Status Management::analysis(Status numStudents, Status numCourses, Status courseIndex)
{
	vector<vector<double>> grades(numStudents, vector<double>(numCourses));

	// ����ѧ���ɼ�
	for (int i = 0; i < numStudents; ++i) {
		cout << "������ѧ�� " << (i + 1) << " �ĳɼ�: ";
		for (int j = 0; j < numCourses; ++j) {
			cin >> grades[i][j];//�м����γ̾�Ҫ���뼸���ɼ�
			//�������
			cout << "������ѧ�� " << (i + 1) << " �Ŀγ� " << (j + 1) << " �ɼ�: " << grades[i][j] << endl;
		}
	}

	// ͳ�Ƹ��ȼ�����
	vector<int> count(5, 0); // 0: ������, 1: ����, 2: ��, 3: ��, 4: ��
	for (int i = 0; i < numStudents; ++i) {
		for (int j = 0; j < numCourses; ++j) {
			double grade = grades[i][courseIndex];//��ȡָ���γ̵ĳɼ�
			if (grade < 60) {
				count[0]++;
			}
			else if (grade < 70) {
				count[1]++;
			}
			else if (grade < 80) {
				count[2]++;
			}
			else if (grade < 90) {
				count[3]++;
			}
			else {
				count[4]++;
			}
		}
	}

	// ��ӡ�ɼ�������
	cout << fixed << setprecision(2);
	cout << "\n�ɼ�������:\n";
	cout << "�ȼ�\t����\n";
	cout << "������\t" << count[0] << endl;
	cout << "����\t" << count[1] << endl;
	cout << "��\t" << count[2] << endl;
	cout << "��\t" << count[3] << endl;
	cout << "��\t" << count[4] << endl;

	
}

