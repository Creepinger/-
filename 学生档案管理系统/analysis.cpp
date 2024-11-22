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

    // 输入学生成绩
    for (int i = 0; i < numStudents; ++i) {
        cout << "请输入学生 " << (i + 1) << " 的成绩: ";
        for (int j = 0; j < numCourses; ++j) {
            cin >> grades[i][j];//有几个课程就要输入几个成绩
            //调试输出
            cout << "已输入学生 " << (i + 1) << " 的课程 " << (j + 1) << " 成绩: " << grades[i][j] << endl;
        }
    }

    // 统计各等级人数
    vector<int> count(5, 0); // 0: 不及格, 1: 及格, 2: 中, 3: 良, 4: 优
    for (int i = 0; i < numStudents; ++i) {
        for (int j = 0; j < numCourses; ++j) {
            double grade = grades[i][courseIndex];//获取指定课程的成绩
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

    // 打印成绩分析表
    cout << fixed << setprecision(2);
    cout << "\n成绩分析表:\n";
    cout << "等级\t人数\n";
    cout << "不及格\t" << count[0] << endl;
    cout << "及格\t" << count[1] << endl;
    cout << "中\t" << count[2] << endl;
    cout << "良\t" << count[3] << endl;
    cout << "优\t" << count[4] << endl;

    return 0;
}

Status get_score()
{
   
    Status numStudents, numCourses, courseIndex;

    cout << "请输入学生人数: ";
    cin >> numStudents;

    cout << "请输入课程数量: ";
    cin >> numCourses;

    cout << "请输入要查看的课程索引 (例如：0为面向对象课程，1为数据结构，依此类推): ";
    cin >> courseIndex;

    if (courseIndex<0 || courseIndex > numCourses)
    {
        cout << "该课程不存在" << endl;
        return ERROR;
    }
    //统计学生成绩情况
    analysis(numStudents, numCourses, courseIndex);
    return OK;
}