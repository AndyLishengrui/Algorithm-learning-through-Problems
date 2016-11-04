//
//  Machine Schedule.cpp
//  laboratory
//
//  Created by ����ɺ on 15/9/5.
//  Copyright (c) 2015�� xu_zishan. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
bool operator<(const set<int> &a, const set<int> &b){
	return a.size()<b.size();
}
class Comp{
public:
	bool operator()(set<int> &a, set<int> &b){
		return a<b;
	}
};
int machineSchedule(int n, int m, vector<int> &i, vector<int> &x, vector<int> &y) {
    vector<set<int>> mode(n+m, set<int>());
    set<int> jobs;//δ�������񼯺�
	int k=x.size();
    for (int j=0; j<k; j++) {
        mode[x[j]].insert(i[j]);//��¼����i��A������ģʽ
        mode[n+y[j]].insert(i[j]);//��¼����i��B������ģʽ
        jobs.insert(j);
    }
	set<int> r=mode[0].size()>mode[n+m-1].size()? mode[0]:mode[n+m-1];//�״ο���Ҫ���������
    int num=0;//������������
    while (!jobs.empty()) {//����δ��������
        num++;
		int* temp=new int[jobs.size()];
		int* p=set_difference(jobs.begin(), jobs.end(), r.begin(), r.end(), temp);//����������
		jobs=set<int>(temp, p);
		delete []temp;
        for (int j=0; j<n+m; j++) {//������ģʽ�ɽ��ܵ�����
			temp=new int[mode[j].size()];
			p=set_difference(mode[j].begin(), mode[j].end(),r.begin(), r.end(), temp);
			mode[j]=set<int>(temp, p);
			delete []temp;
        }
		int j=distance(mode.begin(), max_element(mode.begin(), mode.end(),Comp()));//�ɴ�����������ģʽ
        r=mode[j];//�´δ��������
    }
    return num;
}
int main(){
    ifstream inputdata("Machine Schedule/inputdata.txt");
    ofstream outputdata("Machine Schedule/outputdata.txt");
	int n;
	inputdata>>n;
	while(n>0){
		int m, k;
		inputdata>>m>>k;
		vector<int> i(k), x(k), y(k);
		for(int j=0; j<k; j++)
			inputdata>>i[j]>>x[j]>>y[j];
		int result=machineSchedule(n,m,i,x,y);
		outputdata<<result<<endl;
		cout<<result<<endl;
		inputdata>>n;
	}
    inputdata.close();
    outputdata.close();
    return 0;
}