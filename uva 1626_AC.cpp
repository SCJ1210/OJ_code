//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 0x3f3f3f3f
int d[105][105],n;
string s;
void init()
{
	memset(d,INF,sizeof(d));
	for(int i=0;i<n;++i) d[i][i]=1,d[i+1][i]=0;
}
bool match(char a,char b)
{
	if(a=='['&&b==']') return true;
	if(a=='('&&b==')') return true;
	return false;
}
int dp(int i,int j)
{
	if(d[i][j]!=INF) return d[i][j];
	if(match(s[i],s[j])) d[i][j]=min(d[i][j],dp(i+1,j-1));
	for(int k=i;k<j;++k)
		d[i][j]=min(d[i][j],dp(i,k)+dp(k+1,j));
	return d[i][j];
}
void pf(int i,int j)
{
	if(i>j) return ;
	if(i==j){
		if(s[i]=='('||s[i]==')') cout<<"()";
		else cout<<"[]";
		return ;
	}
	if(match(s[i],s[j])&&d[i][j]==d[i+1][j-1]){
		cout<<s[i];pf(i+1,j-1);cout<<s[j];
		return ;
	}
	for(int k=i;k<j;++k)
	{
		if(d[i][j]==d[i][k]+d[k+1][j]){
			pf(i,k);pf(k+1,j);return ;
		}
	}
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int T;cin>>T;cin.get();
	for(int no=0;no<T;++no)
	{
		cin.get();
		if(no) cout<<"\n";
		getline(cin,s);
		n=s.size();
		init();
		dp(0,n-1);
		//cout<<dp(0,n-1)<<endl;
		pf(0,n-1);cout<<endl;
	}
}
/*
1

([(]
*/
