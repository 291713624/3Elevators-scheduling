#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include"Elevator.h"
using namespace std;
int N, n, i, j, l, num, distime;//����ȫ�ֱ�����
Elevator e1, e2, e3;
man people[100006];
int nowtime = 0;
void uplift(int i)//�жϸó˿��Ƿ�����ϵ�������
{
	if (nowtime >= people[i].asktime&&people[i].now == -1) {
		if (people[i].n == 1) {
			if (e1.nowfloor == people[i].askfloor && e2.nowfloor == people[i].askfloor) {
				if (people[i].askspace > people[i].askfloor) {
					if (e2.indicator == 1) {
						e2.stop(nowtime, e2.nowfloor, 2);
						e2.nowman++;
						people[i].now = 0;
						nowtime++;
						return;
					}
					if (e1.indicator == 1) {
						e1.stop(nowtime, e1.nowfloor, 1);
						e1.nowman++;
						people[i].now = 0;
						nowtime++;
						return;
					}
					e2.stop(nowtime, e2.nowfloor, 2);
					e2.nowman++;
					people[i].now = 0;
					nowtime++;
					return;
				}
				if (people[i].askspace < people[i].askfloor) {
					if (e2.indicator == -1) {
						e2.stop(nowtime, e2.nowfloor, 2);
						e2.nowman++;
						people[i].now = 0;
						nowtime++;
						return;
					}
					if (e1.indicator == -1) {
						e1.stop(nowtime, e1.nowfloor, 1);
						e1.nowman++;
						people[i].now = 0;
						nowtime++;
						return;
					}
					e2.stop(nowtime, e2.nowfloor, 2);
					e2.nowman++;
					people[i].now = 0;
					nowtime++;
					return;
				}
			}
			if (e2.nowfloor == people[i].askfloor) {
				e2.stop(nowtime, e2.nowfloor, 2);
				e2.nowman++;
				people[i].now = 0;
				nowtime++;
				return;
			}
			if (e1.nowfloor == people[i].askfloor) {
				e1.stop(nowtime, e1.nowfloor, 1);
				e1.nowman++;
				people[i].now = 0;
				nowtime++;
				return;
			}
		}
		if (people[i].n == 3) {
			if (e3.nowfloor == people[i].askfloor && e2.nowfloor == people[i].askfloor) {
				if (people[i].askspace > people[i].askfloor) {
					if (e2.indicator == 1) {
						e2.stop(nowtime, e2.nowfloor, 2);
						e2.nowman++;
						people[i].now = 0;
						nowtime++;
						return;
					}
					if (e3.indicator == 1) {
						e3.stop(nowtime, e3.nowfloor, 3);
						e3.nowman++;
						people[i].now = 0;
						nowtime++;
						return;
					}
					e2.stop(nowtime, e2.nowfloor, 2);
					e2.nowman++;
					people[i].now = 0;
					nowtime++;
					return;
				}
				if (people[i].askspace < people[i].askfloor) {
					if (e2.indicator == -1) {
						e2.stop(nowtime, e2.nowfloor, 2);
						e2.nowman++;
						people[i].now = 0;
						nowtime++;
						return;
					}
					if (e3.indicator == -1) {
						e3.stop(nowtime, e3.nowfloor, 3);
						e3.nowman++;
						people[i].now = 0;
						nowtime++;
						return;
					}
					e2.stop(nowtime, e2.nowfloor, 2);
					e2.nowman++;
					people[i].now = 0;
					nowtime++;
					return;
				}
			}
			if (e2.nowfloor == people[i].askfloor) {
				e2.stop(nowtime, e2.nowfloor, 2);
				e2.nowman++;
				people[i].now = 0;
				nowtime++;
				return;
			}
			if (e3.nowfloor == people[i].askfloor) {
				e3.stop(nowtime, e3.nowfloor, 3);
				e3.nowman++;
				people[i].now = 0;
				nowtime++;
				return;
			}
		}
	}
}

void downlift(int i)//�жϸó˿��Ƿ񵽴�Ŀ�ĵ�
{
	if (people[i].now == 1) {
		if (people[i].askspace == e1.nowfloor) {
			e1.stop(nowtime, e1.nowfloor, 1);
			e1.nowman--;
			people[i].now = 0;
			nowtime++;
			num--;
			return;
		}
	}
	if (people[i].now == 2) {
		if (people[i].askspace == e2.nowfloor) {
			e2.stop(nowtime, e2.nowfloor, 2);
			e2.nowman--;
			people[i].now = 0;
			nowtime++;
			num--;
			return;
		}
	}
	if (people[i].now == 3) {
		if (people[i].askspace == e3.nowfloor) {
			e3.stop(nowtime, e3.nowfloor, 3);
			e3.nowman--;
			people[i].now = 0;
			nowtime++;
			num--;
			return;
		}
	}
}
int main() {
	ifstream infile("./input.txt", ios::in);
	if (!infile)
	{
		cerr << "open infile wrong!\n";
		exit(1);
	}
	ofstream outfile4("./output1.txt", ios::app);
	if (!outfile4)//�ж��ļ����Ƿ�ɹ�
	{
		cerr << "open outfile wrong!\n";
		exit(1);
	}
	ofstream outfile5("./output2.txt", ios::app);
	if (!outfile5)//�ж��ļ����Ƿ�ɹ�
	{
		cerr << "open outfile wrong!\n";
		exit(1);
	}
	ofstream outfile6("./output3.txt", ios::app);
	if (!outfile6)//�ж��ļ����Ƿ�ɹ�
	{
		cerr << "open outfile wrong!\n";
		exit(1);
	}
	infile >> N;
	num = N;
	for (i = 1; i <= N; i++) {
		infile >> people[i].asktime >> people[i].askfloor >> people[i].askspace;
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
	}//��ȡN������
	j = 1;
	nowtime = people[1].asktime;//���ݵȴ������յ���һ������
	if (people[1].askfloor == 1) {
		e2.indicator = 1;
		e2.nowman++;
		people[j].now = 2;
		nowtime++;
		j++;
		while (people[j].askfloor == 1) {
			if (people[j].n == 1) {
				e1.indicator = 1;
				e1.nowman++;
				people[j].now = 1;
				nowtime++;
				j++;
			}
			if (people[j].n == 3) {
				e3.indicator = 1;
				e3.nowman++;
				people[j].now = 3;
				nowtime++;
				j++;
			}
			if (people[j].n == 2) {
				e2.indicator = 1;
				e2.nowman++;
				people[j].now = 2;
				nowtime++;
				j++;
			}
		}
	}//���ǰ���������ڵ�һ��
	else {
		nowtime += people[j].askfloor - 1;
		e2.nowfloor = people[j].askfloor;
		e2.stop(nowtime, e2.nowfloor, 2);
		e2.indicator = 1;
		e2.nowman++;
		people[j].now = 2;
		nowtime++;
		j++;
		while (people[j].asktime == people[1].asktime) {
			if (people[j].n == 1) {
				e1.nowfloor = people[j].askfloor;
				distime = people[j].askfloor - people[1].askfloor;
				e1.stop(nowtime + distime, e1.nowfloor, 1);
				e1.indicator = 1;
				e1.nowman++;
				people[j].now = 1;
				nowtime++;
				j++;
			}
			if (people[j].n == 3) {
				e3.nowfloor = people[j].askfloor;
				distime = people[j].askfloor - people[1].askfloor;
				e3.stop(nowtime + distime, e3.nowfloor, 3);
				e3.indicator = 1;
				e3.nowman++;
				people[j].now = 3;
				nowtime++;
				j++;
			}
			if (people[j].n == 2) {
				e2.nowfloor = people[j].askfloor;
				distime = people[j].askfloor - people[1].askfloor;
				e2.stop(nowtime + distime, e2.nowfloor, 2);
				e2.indicator = 1;
				e2.nowman++;
				people[j].now = 2;
				nowtime++;
				j++;
			}
		}
	}//�Ե�һ������������Ӧ 
	while (1) {
		nowtime++;
		if (e1.indicator == 1 && e1.nowfloor == 10) e1.indicator = -1;
		if (e1.indicator == -1 && e1.nowfloor == 1) e1.indicator = 1;
		if (e2.indicator == 1 && e2.nowfloor == 10) e2.indicator = -1;
		if (e2.indicator == -1 && e2.nowfloor == 1) e2.indicator = 1;
		if (e3.indicator == 1 && e3.nowfloor == 10) e3.indicator = -1;
		if (e3.indicator == -1 && e3.nowfloor == 1) e3.indicator = 1;//�����������з���
		if (e1.indicator == 1) e1.nowfloor++;
		if (e1.indicator == -1) e1.nowfloor--;
		if (e2.indicator == 1) e2.nowfloor++;
		if (e2.indicator == -1) e2.nowfloor--;
		if (e3.indicator == 1) e3.nowfloor++;
		if (e3.indicator == -1) e3.nowfloor--;//�������� 
		for (i = 1; i <= N; i++) {
			uplift(i);
			downlift(i);
		}
		if (e1.nowman == 0) e1.indicator = 0;
		if (e2.nowman == 0) e2.indicator = 0;
		if (e3.nowman == 0) e3.indicator = 0;
		if (e1.nowman == 1) {
			for (i = 1; i < N; i++) {
				if (people[i].now == 1) {
					if (people[i].askspace > e1.nowfloor) e1.indicator = 1;
					else e1.indicator = -1;
					break;
				}
			}
		}//��������1���з��� 
		if (e2.nowman == 1) {
			for (i = 1; i < N; i++) {
				if (people[i].now == 2) {
					if (people[i].askspace > e2.nowfloor) e2.indicator = 1;
					else e2.indicator = -1;
					break;
				}
			}
		}//��������2���з��� 
		if (e3.nowman == 1) {
			for (i = 1; i < N; i++) {
				if (people[i].now == 3) {
					if (people[i].askspace > e3.nowfloor) e3.indicator = 1;
					else e3.indicator = -1;
					break;
				}
			}
		}//��������3���з��� 
		if (num == 0) break; //���N���˿Ͷ������꣬����ѭ�� 
	}

	return 0;
}
