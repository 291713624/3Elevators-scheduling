#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<cmath>
#include"Elevator.h"
using namespace std;
extern int nowtime;
void Elevator::stop(int time, int floor, int n) {
	if (n == 1) {
		ofstream outfile1("./output1.txt", ios::app);
		if (!outfile1)//判断文件打开是否成功
		{
			cerr << "open outfile wrong!\n";
			exit(1);
		}
		outfile1 << time << " " << floor << endl;
	}
	if (n == 2) {
		ofstream outfile2("./output2.txt", ios::app);
		if (!outfile2)//判断文件打开是否成功
		{
			cerr << "open outfile wrong!\n";
			exit(1);
		}
		outfile2 << time << " " << floor << endl;
	}
	if (n == 3) {
		ofstream outfile3("./output3.txt", ios::app);
		if (!outfile3)//判断文件打开是否成功
		{
			cerr << "open outfile wrong!\n";
			exit(1);
		}
		outfile3 << time << " " << floor << endl;
	}

}


Elevator::Elevator() {
	nowtime = sumtime = nowman = 0;
	nowfloor = 1;
	indicator = 0;
}

Elevator:: ~Elevator() {

}

void Elevator::gotofloor(int askfloor) {
	nowtime += fabs(nowfloor - askfloor);
	nowfloor = askfloor;
}

void Elevator::show(int nowfloor) {
	cout << "nowfloor：" << nowfloor << endl;
}


man::man()
{
}

man::~man()
{
}