#include "Management.h"
#include<iostream>
#include<string>
#include<limits>
#include<vector>
/*numeric_limits 是定义在 <limits> 头文件中的，因此，如果没有包含该头文件，编译器会报错，
因为无法识别 numeric_limits<streamsize>::max()。*/

using namespace std;
void Management::run()
{    
	//获取菜单的返回值
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
	//根据按钮的点击，返回操作
	
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

/*（3）	提供每门课程的成绩分析表，
 即按优、良、中、及格、不及格5个等级进行
 人数统计、分析并打印成绩分析表。*/

void Management::readFile(const string& fileName)
{
	fstream read(fileName, ios::in);//用“(ios::in)只读模式”打开指定路径和文件名的文件进行读取操作
	if (!read.is_open())
	{
		cerr << fileName << "open failed" << endl;
		return;

	}//需要读取的文件打开失败
	string line;
	cout << "File content of " << fileName << ":\n";

	// 逐行读取文件内容并输出
	while (getline(read, line)) {
		cout << line << endl;  // 输出每一行的内容
	}
	read.close();//文件关闭

}//文件读取（打开）

void Management::writeFile(const string& fileName,int numStudents)
{
	fstream outfile(fileName, ios::app);//ios::app 是追加模式
	if (!outfile.is_open())
	{
		cerr << fileName << "open failed" << endl;
		return ;
	}//需要改写的文件打开失败
	
	
	

	// 获取学生数据
	for (int i = 0; i < numStudents; ++i) {
		Student stu;
		cout << "Enter details for student " << i + 1 << " (name,Math score,Physics score): ";
		cin >> stu.name >> stu.Math >> stu.Physics;

		while (stu.Math || stu.Physics)
		{
			cout << "Invalid input for Math score. Please enter an integer: ";
			cin.clear();  // 清除错误标志
			cin.ignore(numeric_limits<streamsize>::max(),'\n'); // 忽略当前行的剩余输入
		}
		// 将学生信息写入文件
		outfile << stu << endl;//这里调用了重载的 << 运算符
	}


	outfile.close(); // 关闭文件
	cout << "Data written to " << fileName << " successfully." << endl;
}
		
		


void Management::simple_sort(float score,Grade &g)
{
	int A=0, B=0, C=0, D=0, E=0;
	if (score > 100 || score < 0) cout << "输入分数有错误" << endl;
	if (score >= 90 && score <= 100) { cout << "优" <<endl; g.A++; }
	if (score >= 80 && score < 90) { cout << "良" << endl; g.B++;}
	if (score >= 70 && score < 80) { cout << "中" << endl; g.C++; }
	if (score >= 60 && score < 70) { cout << "及格" << endl; g.D++; }
	if (score >= 0 && score < 60) { cout << "不及格" << endl; g.E++; }

}
/*idea:可能还需要加一个统计不同等第人数的类，
然后再新开一个函数输出人数*/

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
	//统计学生总人数
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
Status Management::analysis(Status numStudents, Status numCourses, Status courseIndex)
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

	
}

