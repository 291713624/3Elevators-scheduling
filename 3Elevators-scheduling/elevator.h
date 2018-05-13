#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
class man {
public:
	man();
	~man();
	int n;//�жϳ˿͸ó����ڼ������ݣ�
	int asktime;//����ʱ�� 
	int askfloor;//���������¥�� 
	int askspace;//����ǰ����Ŀ�ĵ� 
	int usetime;//�ó˿��ܵȴ�ʱ�� 
	int now;//�����жϸó˿��Ƿ��Ѵ����״̬��
	void uplift(int i);//�жϸó˿��Ƿ�����ϵ�������
	void downlift(int i);//�жϸó˿��Ƿ񵽴�Ŀ�ĵ�
};
class Elevator {
public:
	Elevator();
	~Elevator();
	int nowfloor;//��ǰλ��
	int indicator; //��ǰ�������з���
	int nowman;//�ڵ����г˿͵�������
	void gotofloor(int askfloor); //���ܵ���ĳһ���ָ��
	void stop(int time, int floor, int n); //ͣ���ڵ�ǰ¥��
	void show(int nowfloor); //��ʾ��ǰ����¥��λ��

private:
	int sumtime;//�˿͵���Ŀ�ĵ�֮ǰ���ܵȴ�ʱ��

};
