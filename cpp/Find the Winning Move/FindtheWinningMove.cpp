//
//  FindtheWinningMove.cpp
//  Algorithms
//
//  Created by ����ɺ on 13-7-7.
//  Copyright (c) 2013�� ����ɺ. All rights reserved.
//
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;
//class TicTacToe;
//bool checkrow(int i, int targ){//���targ��ʾ����Ƿ��ڵ�i��Ӯ
//    int v=15<<(i*4);
//    return v==(targ&v);
//}
//bool checkcol(int j, int targ){//���targ��ʾ����Ƿ��ڵ�j��Ӯ
//    int v=4369<<j;
//	return v==(targ&v);
//}
//bool checkdiag(int targ){//���targ��ʾ����Ƿ������Խ���Ӯ
//    int v=33825;
//    return v==(targ&v);
//}
//bool checkdiag1(int targ){//���targ��ʾ����Ƿ��ڴζԽ���Ӯ
//    int v=4680;
//    return v==(targ&v);
//}
//class Player{//�����
//    bool win;//Ӯ��־
//    int pattern;//�ԼҸ��
//    int initp;//�Լҳ�ʼ���
//public:
//    Player(int p=0):win(false),initp(p),pattern(p){}
//    void place(int i, int j);//�ڵ�i�е�j�д�����
//    void clear(int i, int j);//�����i�е�j�д�����
//    void reset();//���Լҳ�ʼ�������
//    void reset(int p);//�ø�ֲ�������
//    bool isWin(){return win;}//���Ӯ��־
//    friend void explore(TicTacToe &game, int k);//̽��һ����
//};
//void Player::place(int i, int j){
//    int v=1;
//    v=v<<(i*4+j);
//    pattern=pattern|v;//���ø�ֶ�ӦλΪ1
//    win=checkrow(i, pattern)||checkcol(j, pattern)||checkdiag(pattern)||checkdiag1(pattern);
//}
//void Player::clear(int i, int j){
//    int v=1;
//    v=v<<(i*4+j);
//    v=~v;//ȡ��
//    pattern=pattern&v;//�����ֶ�Ӧλ�ϵ�1
//}
//void Player::reset(){
//    pattern=initp;
//    win=false;
//}
//void Player::reset(int p){
//    pattern=initp=p;
//    win=false;
//}
//bool checkdiag1(bitset<16> &targ){//���targ��ʾ����Ƿ��ڴζԽ���Ӯ
//    bitset<16> v=4680;
//    return v==(targ&v);
//}
//class TicTacToe {//һ������
//    Player x, o;//�������
//    vector<pair<int, int> > hole;//�����п����ӵ�����
//    int p[16];//����˳��
//    int n;//��������Ŀ
//    bool draw;//ƽ�ֱ�־
//    bool forceWin;//x��Ӯ��־
//public:
//    pair<int, int> winMove;//��Ӯ�ײ�
//    TicTacToe(string a[4]);//���캯��
//    void oneTurn(int k);//��k��
//    void restore(int k);//����ǰ�ָ����
//    void reset();//����
//    bool xIsWin(){return forceWin;}//���x��Ӯ��־
//    friend void findWinningMove(TicTacToe &game);//����������Ӯ�ײ�
//    friend void explore(TicTacToe &game, int k);
//};
//TicTacToe::TicTacToe(string a[4]){
//    int xinit=0,oinit=0;
//    n=0;
//    for(int i=0,t=0;i<4;i++)
//        for(int j=0;j<4;j++){
//            if(a[i][j]=='.'){//��¼����������
//                hole.push_back(make_pair(i,j));
//                p[t++]=n++;
//                continue;
//            }
//            int k=i*4+j,v=1;
//            v=v<<k;
//            if(a[i][j]=='x')//����x��ʼ���
//                xinit=xinit|v;
//            else//����o��ʼ���
//                oinit=oinit|v;
//        }
//    x.reset(xinit);//��ʼ��x���
//    o.reset(oinit);//��ʼ��o���
//    forceWin=draw=false;//��ʼ������־
//    winMove=hole[p[0]];//��ʼ����Ӯ�ײ�
//}
//void TicTacToe::oneTurn(int k){//��k��
//    int i=hole[p[k]].first,j=hole[p[k]].second;
//    if (k%2==0)//�ֵ�x���
//        x.place(i, j);
//    else//�ֵ�o���
//        o.place(i, j);
//}
//void TicTacToe::restore(int k){//�ָ���k��ǰ���
//    int i=hole[p[k]].first,j=hole[p[k]].second;
//    if (k%2==0)
//        x.clear(i, j);
//    else
//        o.clear(i, j);
//}
//void TicTacToe::reset(){
//    x.reset();
//    o.reset();
//    draw=false;
//    forceWin=draw=false;
//    winMove=hole[p[0]];
//}
//void explore(TicTacToe &game, int k){
//    int n=game.n;
//    if (game.o.isWin()){//��һ��o���Ӯ���˳�
//        return;
//    }
//    if(game.x.isWin()){//��һ��x���Ӯ��׼��x����һ���߷�
//        game.x.win=false;
//        return;
//    }
//    if((k>=n)&&!game.x.isWin()&&!game.o.isWin()){//����ƽ��
//        game.draw=true;
//        return;
//    }
//    for(int i=k;i<n;i++){//��һ��δ�ܾ���ʤ����׼����һ��̽��������n-k�����ܵ��߷�
//        swap(game.p[k],game.p[i]);//�������ӵ�����
//        game.oneTurn(k);//��һ��
//        explore(game, k+1);//̽����һ��
//        game.restore(k);//����ǰ�ָ����
//        swap(game.p[k], game.p[i]);
//    }
//}
//void findWinningMove(TicTacToe &game){
//    int n=game.n;
//    for (int i=0; i<n; i++) {//n�����ܵ��ײ�
//        swap(game.p[0], game.p[i]);
//        if (i>0&&!game.o.isWin()&&!game.draw) {//ǰһ��x��Ӯ
//            game.forceWin=true;
//            return;
//        }else{//���ǵ�һ�֣�����ǰһ��x�Ǳ�Ӯ
//            game.reset();//���ã�x��o�ĸ�ָֻ���ʼ״̬��
//            game.oneTurn(0);//x����ߵ�һ��
//            explore(game,1);//̽����һ��
//            game.restore(0);//�ָ�����Ҹ��
//            swap(game.p[0], game.p[i]);
//        }
//    }
//}
bool checkrow(int i, bitset<16> &targ){//���targ��ʾ����Ƿ��ڵ�i��Ӯ
	bitset<16> v(15<<(i*4));
    return v==(targ&v);
}
bool checkcol(int j, bitset<16> &targ){//���targ��ʾ����Ƿ��ڵ�j��Ӯ
    bitset<16> v(4369<<j);
	return v==(targ&v);
}
bool checkdiag(bitset<16> &targ){//���targ��ʾ����Ƿ������Խ���Ӯ
    bitset<16> v(33825);
    return v==(targ&v);
}
bool checkdiag1(bitset<16> &targ){//���targ��ʾ����Ƿ��ڴζԽ���Ӯ
    bitset<16> v(4680);
    return v==(targ&v);
}
class Player{//�����
    bool win;//Ӯ��־
    bitset<16> pattern;//�ԼҸ��
    bitset<16> initp;//�Լҳ�ʼ���
    void place(int i, int j);//�ڵ�i�е�j�д�����
    void clear(int i, int j);//�����i�е�j�д�����
    void reset();//���Լҳ�ʼ�������
    void reset(bitset<16> &p);//�ø�ֲ�������
public:
    Player(int p=0):win(false),initp(p),pattern(p){}
    bool isWin(){return win;}//���Ӯ��־
    friend class TicTacToe;//̽��һ����
};
void Player::place(int i, int j){
	pattern.set(i*4+j);//���ø�ֶ�ӦλΪ1
    win=checkrow(i, pattern)||checkcol(j, pattern)||checkdiag(pattern)||checkdiag1(pattern);
}
void Player::clear(int i, int j){
    pattern.reset(i*4+j);//�����ֶ�Ӧλ�ϵ�1
}
void Player::reset(){
    pattern=initp;
    win=false;
}
void Player::reset(bitset<16> &p){
    pattern=initp=p;
    win=false;
}
class TicTacToe {//һ������
    Player x, o;//�������
    vector<pair<int, int> > hole;//�����п����ӵ�����
    vector<int> p;//����˳��
    int n;//��������Ŀ
    bool draw;//ƽ�ֱ�־
    void oneTurn(int k);//��k��
    void restore(int k);//����ǰ�ָ����
    void reset();//����
    void explore(int k);
public:
    pair<int, int> winMove;//��Ӯ�ײ�
    TicTacToe(vector<string> &a);//���캯��
    friend bool findWinningMove(TicTacToe &game);//����������Ӯ�ײ�
};
TicTacToe::TicTacToe(vector<string> &a){
    bitset<16> xinit=0,oinit=0;
    n=0;
    for(int i=0,t=0;i<4;i++)
        for(int j=0;j<4;j++){
            if(a[i][j]=='.'){//��¼����������
                hole.push_back(make_pair(i,j));
				p.push_back(n++);
                continue;
            }
            int k=i*4+j;
            if(a[i][j]=='x')//����x��ʼ���
                xinit.set(k);
            else//����o��ʼ���
                oinit.set(k);
        }
    x.reset(xinit);//��ʼ��x���
    o.reset(oinit);//��ʼ��o���
    draw=false;//��ʼ������־
    winMove=hole[p[0]];//��ʼ����Ӯ�ײ�
}
void TicTacToe::oneTurn(int k){//��k��
    int i=hole[p[k]].first,j=hole[p[k]].second;
    if (k%2==0)//�ֵ�x���
        x.place(i, j);
    else//�ֵ�o���
        o.place(i, j);
}
void TicTacToe::restore(int k){//�ָ���k��ǰ���
    int i=hole[p[k]].first,j=hole[p[k]].second;
    if (k%2==0)
        x.clear(i, j);
    else
        o.clear(i, j);
}
void TicTacToe::reset(){
    x.reset();
    o.reset();
    draw=false;
    draw=false;
    winMove=hole[p[0]];
}
void TicTacToe::explore(int k){
    if (o.isWin()){//��һ��o���Ӯ���˳�
        return;
    }
    if(x.isWin()){//��һ��x���Ӯ��׼��x����һ���߷�
        x.win=false;
        return;
    }
    if((k>=n)&&!x.isWin()&&!o.isWin()){//����ƽ��
        draw=true;
        return;
    }
    for(int i=k;i<n;i++){//��һ��δ�ܾ���ʤ����׼����һ��̽��������n-k�����ܵ��߷�
        swap(p[k],p[i]);//�������ӵ�����
        oneTurn(k);//��һ��
        explore(k+1);//̽����һ��
        restore(k);//����ǰ�ָ����
        swap(p[k], p[i]);
    }
}
bool findWinningMove(TicTacToe &game){
    int n=game.n;
    for (int i=0; i<n; i++) {//n�����ܵ��ײ�
        swap(game.p[0], game.p[i]);
        if (i>0&&!game.o.isWin()&&!game.draw) {//ǰһ��x��Ӯ
            return true;
        }else{//���ǵ�һ�֣�����ǰһ��x�Ǳ�Ӯ
            game.reset();//���ã�x��o�ĸ�ָֻ���ʼ״̬��
            game.oneTurn(0);//x����ߵ�һ��
            game.explore(1);//̽����һ��
            game.restore(0);//�ָ�����Ҹ��
            swap(game.p[0], game.p[i]);
        }
    }
	return false;
}

int main(){
    ifstream inputdata("Find the Winning Move/inputdata.txt");
    ofstream outputdata("Find the Winning Move/outputdata.txt");
    char ch;
    inputdata>>ch;
    while(ch!='$'){
        string  s;
		vector<string> a(4);
        for(int i=0;i<4;i++)//��ȡ������ʼ���
            inputdata>>a[i];
        TicTacToe game(a);//�������
        if (findWinningMove(game)) {//����x��Ӯ�ײ�
            outputdata<<"("<<game.winMove.first<<","<<game.winMove.second<<")"<<endl;
            cout<<"("<<game.winMove.first<<","<<game.winMove.second<<")"<<endl;
        }else{
            outputdata<<"#####"<<endl;
            cout<<"#####"<<endl;
        }
        inputdata>>ch;
    }
    inputdata.close();
	outputdata.close();
	return 0;
}