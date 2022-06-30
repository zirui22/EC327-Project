#include <iostream>
#include <string>
#include <map>
#include <array>
#include <vector>
using namespace std;
struct Move
{
	int r;//行
	int c;//列
	char player;
};

char tttresult(string tttboard) {
	
	//1.如果有其他字符出现，则为e,字符数目不为9，则为e
	if(tttboard.length() != 9)
		return 'e';
	for(int i=0;i<9;i++){
		if(tttboard.at(i) !='o' && tttboard.at(i) !='x' &&tttboard.at(i) !='#'){
			return 'e';
		}
	}
	//2.如果有过多的同种字符出现，则为i
	int numx=0,numo=0;
	for(int i=0;i<tttboard.length();i++){
		if(tttboard.at(i) == 'x')
			numx++;
		if(tttboard.at(i) =='o')
			numo++;
	}
	int oxs=numx-numo;
	if(oxs != 0 && oxs!=1){
		//cout<<numx<<"  "<<numo<<endl;
		//cout<<"guoduo"<<endl;
		return 'i';
	}
	//3.如果x和o同时赢了，则为i
	int xv =0;
	int ov=0;
	char as='x';
	if(tttboard.at(0) == as && tttboard.at(4) == as && tttboard.at(8) == as) {
		xv = 1;
	}
	else if(tttboard.at(2) == as && tttboard.at(4) == as && tttboard.at(6) == as) {
		xv = 1;
	}
	else if(tttboard.at(0) == as && tttboard.at(3) == as && tttboard.at(6) == as) {
		xv = 1;
		
	}
	else if(tttboard.at(1) == as && tttboard.at(4) == as && tttboard.at(7) == as) {
		xv = 1;
	}
	else if(tttboard.at(2) == as && tttboard.at(5) == as && tttboard.at(8) == as) {
		xv = 1;
		
	}
	else if(tttboard.at(0) == as && tttboard.at(1) == as && tttboard.at(2) == as){
		xv = 1;
		
	}
	else if(tttboard.at(3) == as && tttboard.at(4) == as && tttboard.at(5) == as){
		xv = 1;
	}
	else if(tttboard.at(6) == as && tttboard.at(7) == as && tttboard.at(8) == as){
		xv = 1;
	}
	if(xv==1 && oxs==0){
		return 'i';
	}

	as='o';
	if(tttboard.at(0) == as && tttboard.at(4) == as && tttboard.at(8) == as) {
		ov = 1;
	}
	else if(tttboard.at(2) == as && tttboard.at(4) == as && tttboard.at(6) == as) {
		ov = 1;
	}
	else if(tttboard.at(0) == as && tttboard.at(3) == as && tttboard.at(6) == as) {
		ov = 1;
		
	}
	else if(tttboard.at(1) == as && tttboard.at(4) == as && tttboard.at(7) == as) {
		ov = 1;
	}
	else if(tttboard.at(2) == as && tttboard.at(5) == as && tttboard.at(8) == as) {
		ov = 1;
		
	}
	else if(tttboard.at(0) == as && tttboard.at(1) == as && tttboard.at(2) == as){
		ov = 1;
		
	}
	else if(tttboard.at(3) == as && tttboard.at(4) == as && tttboard.at(5) == as){
		ov = 1;
	}
	else if(tttboard.at(6) == as && tttboard.at(7) == as && tttboard.at(8) == as){
		ov = 1;
	} 
	if(ov==1 && oxs==1){
		return 'i';
	}
	if(xv== 1 && ov==1){
		return 'i';
	}
	//如果x赢了就输出x，o则输出o
	if(ov==1){
		return 'o';
	}
	if(xv==1){
		return 'x';
	}
	//若有空位则输出c，否则t
	if(tttboard.find("#") == string::npos){
		return 't';
	}
	else
		return 'c';
}
char tttresult(vector<Move> borad){
	string str="#########";
	//r行 c列
	if(borad.size() >9){
		return 'e';
	}
	if(borad.at(0).player == 'o')
		return 'i';
	int flag=0;
	for (vector<Move>::iterator iter = borad.begin(); iter != borad.end(); iter++){
		if(flag == 0 && (*iter).player == 'o'){
			return 'i';
		}
		if(flag == 1 && (*iter).player =='x'){
			return 'i';
		}
		if((*iter).r >2 || (*iter).c >2)
			return 'e';
		if(str[((*iter).r)*3+((*iter).c)] == 'o' || str[((*iter).r)*3+((*iter).c)] == 'x'){
			return 'i';
		}
		str[((*iter).r)*3+((*iter).c)]=(*iter).player;
		if((*iter).player =='o')
			flag=0;
		else
			flag=1;
	}
	return tttresult(str);
}

vector<string> get_all_boards(){
	vector<string> v;
	for(int i=19682;i>=0;i--){
		string str = "#########";
		int tmp=i;
		int j = 8;
		while (tmp != 0) {
			int t = tmp % 3;
			switch (t)
			{
			case 1:
				str.at(j) = 'o';
				break;
			case 2:
				str.at(j) = 'x';
				break;
			}
			j--;
			tmp /= 3;
		}
		char flag = tttresult(str);
		if (flag == 'x' || flag == 'o' || flag == 't' || flag == 'c'|| flag == 'i') {
			v.push_back(str);
		}
	}
	return v;
}

void ttt_tally(){
	int c=0,x=0,o=0,t=0,i=0;
	vector<string> v=get_all_boards();
	//cout<<v.size()<<endl;
	for (int j = 0; j < v.size(); j++)
    {
    	char ch=tttresult(v[j]);
    	switch(ch){
    		case 'c':
    		c++;
    		break;
    		case 'x':
    		x++;
    		break;
    		case 'o':
    		o++;
    		break;
    		case 't':
    		t++;
    		break;
    		case 'i':
    		i++;
    		break;
    	}
    }
    cout<<"x "<<x<<endl;
    cout<<"o "<<o<<endl;
    cout<<"t "<<t<<endl;
    cout<<"c "<<c<<endl;
    cout<<"i "<<i<<endl;
}
