#include<bits/stdc++.h> 
#include"Elevator.h"
using namespace std;
int N, i, j, l, num, distime;//设置全局变量；
Elevator e1, e2, e3;
man people[100006];
int nowtime = 0;
int flag=0; 
void uplift(int i,int argc, char * argv[])//判断该乘客是否符合上电梯条件
{
	if (nowtime >= people[i].asktime&&people[i].now == -1) {
		if (people[i].n == 1) {//如果乘客可以乘坐1号电梯
			if (e1.nowfloor == people[i].askfloor && e2.nowfloor == people[i].askfloor) {//如果1号电梯和2号电梯都在该楼层
				if (people[i].askspace > people[i].askfloor) {
					if (e2.indicator == 1) {
						e2.stop(nowtime, e2.nowfloor, 2,argc,argv);
						e2.nowman++;
						people[i].now = 0;
						nowtime++;
						return;
					}
					if (e1.indicator == 1) {
						e1.stop(nowtime, e1.nowfloor, 1,argc,argv);
						e1.nowman++;
						people[i].now = 0;
						nowtime++;
						return;
					}
					e2.stop(nowtime, e2.nowfloor, 2,argc,argv);
					e2.nowman++;
					people[i].now = 0;
					nowtime++;
					return;
				}
				if (people[i].askspace < people[i].askfloor) {
					if (e2.indicator == -1) {
						e2.stop(nowtime, e2.nowfloor, 2,argc,argv);
						e2.nowman++;
						people[i].now = 0;
						nowtime++;
						return;
					}
					if (e1.indicator == -1) {
						e1.stop(nowtime, e1.nowfloor, 1,argc,argv);
						e1.nowman++;
						people[i].now = 0;
						nowtime++;
						return;
					}
					e2.stop(nowtime, e2.nowfloor, 2,argc,argv);
					e2.nowman++;
					people[i].now = 0;
					nowtime++;
					return;
				}
			}
			else if (e2.nowfloor == people[i].askfloor) {
				e2.stop(nowtime, e2.nowfloor, 2,argc,argv);
				e2.nowman++;
				people[i].now = 0;
				nowtime++;
				return;
			}
			else if (e1.nowfloor == people[i].askfloor) {
				e1.stop(nowtime, e1.nowfloor, 1,argc,argv);
				e1.nowman++;
				people[i].now = 0;
				nowtime++;
				return;
			}
			else {
				if (people[i].askfloor > e1.nowfloor &&e1.nowman == 0) e1.indicator = 1;
				if (people[i].askfloor < e1.nowfloor &&e1.nowman == 0) e1.indicator = -1;
			}
		}
		if (people[i].n == 3) {//如果乘客可以乘坐3号电梯
			if (e3.nowfloor == people[i].askfloor && e2.nowfloor == people[i].askfloor) {//如果3号电梯和2号电梯都在该楼层
				if (people[i].askspace > people[i].askfloor) {
					if (e2.indicator == 1) {
						e2.stop(nowtime, e2.nowfloor, 2,argc,argv);
						e2.nowman++;
						people[i].now = 0;
						nowtime++;
						return;
					}
					if (e3.indicator == 1) {
						e3.stop(nowtime, e3.nowfloor, 3,argc,argv);
						e3.nowman++;
						people[i].now = 0;
						nowtime++;
						return;
					}
					e2.stop(nowtime, e2.nowfloor, 2,argc,argv);
					e2.nowman++;
					people[i].now = 0;
					nowtime++;
					return;
				}
				if (people[i].askspace < people[i].askfloor) {
					if (e2.indicator == -1) {
						e2.stop(nowtime, e2.nowfloor, 2,argc,argv);
						e2.nowman++;
						people[i].now = 0;
						nowtime++;
						return;
					}
					if (e3.indicator == -1) {
						e3.stop(nowtime, e3.nowfloor, 3,argc,argv);
						e3.nowman++;
						people[i].now = 0;
						nowtime++;
						return;
					}
					e2.stop(nowtime, e2.nowfloor, 2,argc,argv);
					e2.nowman++;
					people[i].now = 0;
					nowtime++;
					return;
				}
			}
			else if (e2.nowfloor == people[i].askfloor) {
				e2.stop(nowtime, e2.nowfloor, 2,argc,argv);
				e2.nowman++;
				people[i].now = 0;
				nowtime++;
				return;
			}
			else if (e3.nowfloor == people[i].askfloor) {
				e3.stop(nowtime, e3.nowfloor, 3,argc,argv);
				e3.nowman++;
				people[i].now = 0;
				nowtime++;
				return;
			}
			else {
				if (people[i].askfloor > e3.nowfloor &&e3.nowman == 0) e3.indicator = 1;
				if (people[i].askfloor < e3.nowfloor &&e3.nowman == 0) e3.indicator = -1;
			}
		}
		if (people[i].n == 2) {//如果乘客只能乘坐2号电梯
				
			if (e2.nowfloor == people[i].askfloor) {
				e2.stop(nowtime, e2.nowfloor, 2,argc,argv);
				e2.nowman++;
				people[i].now = 0;
				nowtime++;
				return;
			}
			else {
				if (people[i].askfloor > e2.nowfloor &&e2.nowman==0) e2.indicator = 1;
				if(people[i].askfloor < e2.nowfloor &&e2.nowman == 0) e2.indicator = -1;
			}
		}
	}
}

void downlift(int i,int argc, char * argv[])//判断该乘客是否到达目的地
{
	if (people[i].now == 1) {
		if (people[i].askspace == e1.nowfloor) {
			e1.stop(nowtime, e1.nowfloor, 1,argc,argv);
			e1.nowman--;
			people[i].now = 0;
			nowtime++;
			num--;
			return;
		}
	}//如果乘客在1电梯里
	if (people[i].now == 2) {
		if (people[i].askspace == e2.nowfloor) {
			e2.stop(nowtime, e2.nowfloor, 2,argc,argv);
			e2.nowman--;
			people[i].now = 0;
			nowtime++;
			num--;
			return;
		}
	}//如果乘客在2电梯里
	if (people[i].now == 3) {
		if (people[i].askspace == e3.nowfloor) {
			e3.stop(nowtime, e3.nowfloor, 3,argc,argv);
			e3.nowman--;
			people[i].now = 0;
			nowtime++;
			num--;
			return;
		}
	}//如果乘客在3电梯里
}



int main(int argc, char * argv[]) {
	/*ifstream infile(argv[1], ios::in);
	if (!infile)
	{
		cerr << "open infile wrong!\n";
		exit(1);
	}
	ofstream outfile4(argv[2], ios::app);
	if (!outfile4)//判断文件打开是否成功
	{
		cerr << "open outfile wrong!\n";
		exit(1);
	}
	ofstream outfile5(argv[3], ios::app);
	if (!outfile5)//判断文件打开是否成功
	{
		cerr << "open outfile wrong!\n";
		exit(1);
	}
	ofstream outfile6(argv[4], ios::app);
	if (!outfile6)//判断文件打开是否成功
	{
		cerr << "open outfile wrong!\n";
		exit(1);
	}
	*/
	if(argc<2){
		cout<<"您输入的参数过少"<<endl;
		return 0; 
	} 
	if(argc>5){
		cout<<"您输入的参数过多"<<endl;
		return 0; 
	}
	if(argc>2&&argc<5){
		cout<<"output文件数量与本题不符"<<endl;
		return 0; 
	}
	if(argc==5){
		if(strstr(argv[1],"input")==NULL){
			cout<<"input文件地址非法"<<endl; 
			return 0;
		}
		if(strstr(argv[2],"output")==NULL || strstr(argv[3],"output")==NULL || strstr(argv[4],"output")==NULL){
			cout<<"output文件地址非法"<<endl;
			return 0; 
		}
	}
	if(argc==2){
		if(strstr(argv[1],"input")!=NULL){
			flag=1;
		}else{
			cout<<"input文件地址非法"<<endl; 
			return 0;
		}
	}
	if(flag==1){
		freopen("output1.txt", "a", stdout);
		freopen("output2.txt", "a", stdout);
		freopen("output3.txt", "a", stdout);
	}else{
		freopen(argv[2], "a", stdout);
		freopen(argv[3], "a", stdout);
		freopen(argv[4], "a", stdout);
	}
	freopen(argv[1], "r", stdin);
	cin >> N;
	num = N;
	for (i = 1; i <= N; i++) {
		cin >> people[i].asktime >> people[i].askfloor >> people[i].askspace;
		people[i].usetime = 0;
		people[i].now = -1;
		if ((people[i].askspace % 2 == 0 || people[i].askspace == 1)
			&& (people[i].askfloor % 2 == 0 || people[i].askfloor == 1)) {
			people[i].n = 3;
		}
		else if ((people[i].askspace % 2 != 0)
			&& (people[i].askfloor % 2 != 0)) {
			people[i].n = 1;
		}
		else {
			people[i].n = 2;
		}
	}//读取N个请求；
	j = 1;
	nowtime = people[1].asktime;//电梯等待至接收到第一条请求
	if (people[1].askfloor == 1) {
		e2.indicator = 1;
		e2.nowman++;
		people[j].now = 2;
		nowtime++;
		j++;
		while (people[j].askfloor == 1 && j <= N) {
			if (people[j].n == 1&&nowtime>=people[j].asktime) {
				e1.indicator = 1;
				e1.nowman++;
				people[j].now = 1;
				if (people[j].asktime != nowtime - 1) {
					nowtime++;
				}
				j++;
			}
			else if (people[j].n == 3 && nowtime >= people[j].asktime) {
				e3.indicator = 1;
				e3.nowman++;
				people[j].now = 3;
				if (people[j].asktime != nowtime - 1) {
					nowtime++;
				}
				j++;
			}
			else if (people[j].n == 2 && nowtime >= people[j].asktime) {
				e2.indicator = 1;
				e2.nowman++;
				people[j].now = 2;
				if (people[j].asktime != nowtime - 1) {
					nowtime++;
				}
				j++;
			}
		}
		while (people[j].asktime <= nowtime && j<=N) {
			if (people[j].n == 1) {
				e1.indicator = 1;
				if (e1.nowfloor == people[j].askfloor) {
					if (people[j].askfloor == 1) {
						e1.nowman++;
						people[j].now = 1;
						j++;
					}
					else {
						e1.nowman++;
						people[j].now = 1;
						e1.stop(nowtime, e1.nowfloor, 1,argc,argv);
						j++;
					}
				}
				else {
					if ((people[j].askfloor - e1.nowfloor) <= nowtime) {
						e1.nowman++;
						people[j].now = 1;
						e1.stop(people[j].askfloor - e1.nowfloor+1, people[j].askfloor, 1,argc,argv);
						if ((people[j].askfloor - e1.nowfloor) == nowtime) nowtime++;
						e1.nowfloor = people[j].askfloor;
						j++;
					}
					else {
						e1.nowfloor = nowtime + 1;
					}
				}
			}
			if (people[j].n == 2) {
				e2.indicator = 1;
				if (e2.nowfloor == people[j].askfloor) {
					if (people[j].askfloor == 1) {
						e2.nowman++;
						people[j].now = 2;
						j++;
					}
					else {
						e2.nowman++;
						people[j].now = 2;
						e2.stop(nowtime, e2.nowfloor, 2,argc,argv);
						j++;
					}
				}
				else {
					if ((people[j].askfloor - e2.nowfloor) <= nowtime) {
						e2.nowman++;
						people[j].now = 2;
						e2.stop(people[j].askfloor - e2.nowfloor+1, people[j].askfloor, 2,argc,argv);
						if ((people[j].askfloor - e2.nowfloor) == nowtime) nowtime++;
						e2.nowfloor = people[j].askfloor;
						j++;
					}
					else {
						e2.nowfloor = nowtime + 1;
					}
				}
			}
			if (people[j].n == 3) {
				e3.indicator = 1;
				if (e3.nowfloor == people[j].askfloor) {
					if (people[j].askfloor == 1) {
						e3.nowman++;
						people[j].now = 3;
						j++;
					}
					else {
						e3.nowman++;
						people[j].now = 3;
						e3.stop(nowtime, e3.nowfloor, 3,argc,argv);
						j++;
					}
				}
				else {
					if ((people[j].askfloor - e3.nowfloor) <= nowtime) {
						e3.nowman++;
						people[j].now = 3;
						e3.stop(people[j].askfloor - e3.nowfloor+1, people[j].askfloor, 3,argc,argv);
						if ((people[j].askfloor - e3.nowfloor) == nowtime) nowtime++;
						e3.nowfloor = people[j].askfloor;
						j++;
					}
					else {
						e3.nowfloor = nowtime + 1;
					}
				}
			}
		}
	}//如果前几条请求都在第一层
	else {
		nowtime += people[j].askfloor - 1;
		e2.nowfloor = people[j].askfloor;
		e2.stop(nowtime, e2.nowfloor, 2,argc,argv);
		e2.indicator = 1;
		e2.nowman++;
		people[j].now = 2;
		nowtime++;
		j++;
		while (people[j].asktime == people[1].asktime && j <= N) {
			if (people[j].n == 1) {
				e1.nowfloor = people[j].askfloor;
				distime = people[j].askfloor - people[1].askfloor;
				e1.stop(nowtime + distime, e1.nowfloor, 1,argc,argv);
				e1.indicator = 1;
				e1.nowman++;
				people[j].now = 1;
				nowtime++;
				j++;
			}
			if (people[j].n == 3) {
				e3.nowfloor = people[j].askfloor;
				distime = people[j].askfloor - people[1].askfloor;
				e3.stop(nowtime + distime, e3.nowfloor, 3,argc,argv);
				e3.indicator = 1;
				e3.nowman++;
				people[j].now = 3;
				nowtime++;
				j++;
			}
			if (people[j].n == 2) {
				e2.nowfloor = people[j].askfloor;
				distime = people[j].askfloor - people[1].askfloor;
				e2.stop(nowtime + distime, e2.nowfloor, 2,argc,argv);
				e2.indicator = 1;
				e2.nowman++;
				people[j].now = 2;
				nowtime++;
				j++;
			}
		}
	}//对第一条请求不在第一层而做出响应 
	while (1) {
		if (e1.nowman == 0) e1.indicator = 0;
		if (e2.nowman == 0) e2.indicator = 0;
		if (e3.nowman == 0) e3.indicator = 0;
		if (e1.nowman == 1) {
			for (i = 1; i <= N; i++) {
				if (people[i].now == 1) {
					if (people[i].askspace > e1.nowfloor) e1.indicator = 1;
					else e1.indicator = -1;
					break;
				}
			}
		}
		if (e2.nowman == 1) {
			for (i = 1; i <= N; i++) {
				if (people[i].now == 2) {
					if (people[i].askspace > e2.nowfloor) e2.indicator = 1;
					else e2.indicator = -1;
					break;
				}
			}
		}
		if (e3.nowman == 1) {
			for (i = 1; i <= N; i++) {
				if (people[i].now == 3) {
					if (people[i].askspace > e3.nowfloor) e3.indicator = 1;
					else e3.indicator = -1;
					break;
				}
			}
		}
		nowtime++;
		if (e1.indicator == 1 && e1.nowfloor == 10) e1.indicator = -1;
		if (e1.indicator == -1 && e1.nowfloor == 1) e1.indicator = 1;
		if (e2.indicator == 1 && e2.nowfloor == 10) e2.indicator = -1;
		if (e2.indicator == -1 && e2.nowfloor == 1) e2.indicator = 1;
		if (e3.indicator == 1 && e3.nowfloor == 10) e3.indicator = -1;
		if (e3.indicator == -1 && e3.nowfloor == 1) e3.indicator = 1;//调整电梯运行方向
		if (e1.indicator == 1) e1.nowfloor++;
		if (e1.indicator == -1) e1.nowfloor--;
		if (e2.indicator == 1) e2.nowfloor++;
		if (e2.indicator == -1) e2.nowfloor--;
		if (e3.indicator == 1) e3.nowfloor++;
		if (e3.indicator == -1) e3.nowfloor--;//电梯运行 
		for (i = 1; i <= N; i++) {
			uplift(i,argc,argv);
			downlift(i,argc,argv);
		}
		
		if (num == 0) break; //如果N个乘客都处理完，结束循环 
	}
	fclose(stdin);
	fclose(stdout);
	fclose(stdout);
	fclose(stdout);
	return 0;
}
