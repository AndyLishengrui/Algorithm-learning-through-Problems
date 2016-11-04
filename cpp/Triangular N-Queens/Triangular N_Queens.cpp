//
//  Triangular N_Queens.cpp
//  laboratory
//
//  Created by ����ɺ on 15/4/15.
//  Copyright (c) 2015�� xu_zishan. All rights reserved.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
class Chessboard{
    vector<int> x;
    int first_col;//��һ�Żʺ�ĩβλ�õ��к�
    int seconde_row;//�ڶ��Żʺ��׸�λ���к�
    int seconde_col;//�ڶ��Żʺ�ĩβλ���к�
    int n;//���̹�ģ
    int k;
public:
    Chessboard();
    void triangularNQueens(int N);//�ӹ�ģk��չ���̵���ģN
    string toString(int i, int N);
};
Chessboard::Chessboard(){
	x.push_back(0), x.push_back(-1), x.push_back(1);//��ʼ������
    first_col=0;
    seconde_row=2;
    seconde_col=1;
	k=3;
    n=3;
}
void Chessboard::triangularNQueens(int N){
    n = N>n ? N : n;//�������̹�ģ
    while(k<n){//�����չ������
        switch (k%3) {
            case 0: //��չ����
				x.insert(x.begin(), 1, -1);
                seconde_row++;
                first_col+=2;
                x[first_col]=first_col;
	 	        break;//��һ�Żʺ�׷��һ��
            case 1: //��չ�ױ�
                x.insert(x.begin()+seconde_row, 1, -1);//�ڶ��Żʺ��³�һ��
                seconde_row++;
				break;
            default: //��չ�ױ�
                seconde_col+=2;//�ڶ��Żʺ�׷��һ��
                x.push_back(seconde_col);
            }
        k++;
    }
}
string Chessboard::toString(int i, int N){//���ص�i���������
	ostringstream s; 
    s<<(i+1)<<" "<<N<<" "<<((2*N+1)/3)<<endl;
    int count=0;
    for (int j=0; j<N; j++) {
        if (x[j] > -1) {
            s<<"["<<(j+1)<<", "<<(x[j]+1)<<"] ";
            if (++count == 8) {
                s<<endl;
            }
        }
    }
    s<<endl;
	return s.str();
}

int main(){
	ifstream inputdata("Triangular N-Queens/inputdata.txt");
    ofstream outputdata("Triangular N-Queens/outputdata.txt");
	int c;
	inputdata>>c;
	Chessboard chess;
	for (int i=0; i<c; i++){
		int n;
		inputdata>>n;
		chess.triangularNQueens(n);
		string s=chess.toString(i, n);
		outputdata<<s;
		cout<<s;
	}
    inputdata.close();
    outputdata.close();
    return 0;
}