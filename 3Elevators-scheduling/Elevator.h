#include<bits/stdc++.h> 
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
	int now;//�����жϸó˿��Ƿ��Ѵ����״̬��-1δ����1,2,3�ֱ���1��2��3�ŵ����У�0������
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
	void stop(int time, int floor, int n,int argc, char * argv[]); //ͣ���ڵ�ǰ¥��
	void show(int nowfloor); //��ʾ��ǰ����¥��λ��

private:
	int sumtime;//�˿͵���Ŀ�ĵ�֮ǰ���ܵȴ�ʱ��

};
