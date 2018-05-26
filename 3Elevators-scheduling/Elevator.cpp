#include<bits/stdc++.h> 
#include"Elevator.h"
using namespace std;
extern int nowtime;
extern int flag; 
void Elevator::stop(int time, int floor, int n,int argc, char * argv[]) {
	if (n == 1) {
		if(flag==1){
			freopen("output1.txt", "a", stdout);
		}else{
			freopen(argv[2], "a", stdout);
		}
		
		/*ofstream outfile1(argv[2], ios::app);
		if (!outfile1)//判断文件打开是否成功
		{
			cerr << "open outfile wrong!\n";
			exit(1);
		}
		*/
		cout << time << " " << floor << endl;
		fclose(stdout);
	}
	if (n == 2) {
		if(flag==1){
			freopen("output2.txt", "a", stdout);
		}else{
			freopen(argv[3], "a", stdout);
		}
		/*ofstream outfile2(argv[3], ios::app);
		if (!outfile2)//判断文件打开是否成功
		{
			cerr << "open outfile wrong!\n";
			exit(1);
		}
		*/
		cout << time << " " << floor << endl;
		fclose(stdout);
	}
	if (n == 3) {
		if(flag==1){
			freopen("output3.txt", "a", stdout);
		}else{
			freopen(argv[4], "a", stdout);
		}
		
		/*ofstream outfile3(argv[4], ios::app);
		if (!outfile3)//判断文件打开是否成功
		{
			cerr << "open outfile wrong!\n";
			exit(1);
		}
		*/
		cout << time << " " << floor << endl;
		fclose(stdout);
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
