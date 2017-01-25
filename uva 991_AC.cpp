//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 0x3f3f3f3f
int dp[31];
int f(int n)
{
	if(dp[n]!=INF) return dp[n];
	dp[n]=0;
	for(int i=2;i<=n;i+=2)
	{
		dp[n]+=f(i-2)*f(n-i);
	}
	return dp[n];
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	memset(dp,INF,sizeof(dp));
	dp[0]=1;dp[1]=0;dp[2]=1;//dp[3]=0;
	f(30);
	for(int i=1;i<=30;i+=2) dp[i]=0;
	int n;
	bool fir=0;
	while(cin>>n)
	{
		if(fir) cout<<endl;
		fir=1;
		cout<<dp[n*2]<<endl;
	}
}
