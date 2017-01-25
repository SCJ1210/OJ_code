//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
/*
      00    01
      02    03
04 05 06 07 08 09 10
      11    12
13 14 15 16 17 18 19
      20    21
      22    23
*/
int need[8]={6,7,8,11,12,15,16,17};
int TO[8][8]={
	{22,0,2,6,11,15,20,22},{23,1,3,8,12,17,21,23},
	{4,10,9,8,7,6,5,4},{13,19,18,17,16,15,14,13},
	{1,23,21,17,12,8,3,1},{0,22,20,15,11,6,2,0},
	{19,13,14,15,16,17,18,19},{10,4,5,6,7,8,9,10}
};

int maxd;
string path="AAAAAAAAAAAAAAAAAAAAAAAA",state;
inline int H()
{
	int x[3]={0};
	for(int i=0;i<8;++i) x[state[need[i]]-'1']++;
	return 8-max(max(x[0],x[1]),x[2]);
}
bool dfs(int dep)
{
	int ct=H();
	if(dep+ct>maxd) return false;
	if(dep==maxd)
	{
		if(ct==0) return true;
		return false;
	}
	for(int i=0;i<8;++i)
	{
		string tp=state;path[dep]=i+'A';
		for(int j=2;j<8;++j)
			swap(state[TO[i][j]],state[TO[i][j-1]]);
		if(dfs(dep+1)) return true;
		state=tp;
	}
	return false;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	while(cin>>state,state!="0")
	{
		for(int i=1;i<24;++i){
			char x;cin>>x;state+=x;
		}
		if(H()==0){
			cout<<"No moves needed"<<endl<<state[6]<<endl;
			continue;
		}
		for(maxd=1;;maxd++)
		{
			if(dfs(0)){
				for(int i=0;i<maxd;++i) cout<<path[i];
				cout<<endl<<state[6]<<endl;
				break;
			}
		}
	}
}
/*
1 1 1 1 1 1 2 2 2 1 1 2 2 3 3 2 2 2 3 3 3 3 3 3
2 2 2 2 2 2 3 3 3 2 2 3 3 1 1 3 3 3 1 1 1 1 1 1
1 1 1 1 3 2 3 2 3 1 3 2 2 3 1 2 2 2 3 1 2 1 3 3
1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3
0
*/
