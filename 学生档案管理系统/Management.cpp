#include "Management.h"
#include<iostream>
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
void Management::analyse(Grade g)
{
	cout << "“优”人数：" << g.A << endl;
	cout << "“良”人数：" << g.B << endl;
	cout << "“中”人数：" << g.C << endl;
	cout << "“及格”优秀人数：" << g.D << endl;
	cout << "“不及格”优秀人数：" << g.E << endl;
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
	//统计学生总人数
	/*  Node* curNode=list->front
	while(currNode!=NULL)
	{
	count++;
	curNode=curNode->N
	}*/
}