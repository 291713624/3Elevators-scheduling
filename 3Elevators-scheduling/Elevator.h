#include<bits/stdc++.h> 
using namespace std;
class man {
public:
	man();
	~man();
	int n;//判断乘客该乘坐第几个电梯；
	int asktime;//请求时间 
	int askfloor;//发出请求的楼层 
	int askspace;//请求前往的目的地 
	int usetime;//该乘客总等待时间 
	int now;//用于判断该乘客是否已处理的状态；-1未处理，1,2,3分别在1号2号3号电梯中，0处理完
	void uplift(int i);//判断该乘客是否符合上电梯条件
	void downlift(int i);//判断该乘客是否到达目的地
};
class Elevator {
public:
	Elevator();
	~Elevator();
	int nowfloor;//当前位置
	int indicator; //当前电梯运行方向
	int nowman;//在电梯中乘客的总人数
	void gotofloor(int askfloor); //接受到达某一层的指令
	void stop(int time, int floor, int n,int argc, char * argv[]); //停靠在当前楼层
	void show(int nowfloor); //显示当前所处楼层位置

private:
	int sumtime;//乘客到达目的地之前的总等待时间

};
