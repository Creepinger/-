#include "analysis.h"
#include <iostream>
#include <vector>
#include <iomanip>

#define OK 1;
#define OVERFLOW -2;
#define ERROR 0;
using namespace std;




Status analysis(Status numStudents, Status numCourses,Status courseIndex)
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

    return 0;
}

Status get_score()
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