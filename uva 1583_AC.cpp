//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 100000
#define INF 0x3f3f3f3f
int dp[maxn+10000];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	memset(dp,INF,sizeof(dp));
	for(int i=1;i<=maxn;++i)
	{
		int cnt=0,tp=i;
		while(tp){
			cnt+=tp%10;
			tp/=10;
		}
		dp[i+cnt]=min(dp[i+cnt],i);
	}
	int T;cin>>T;
	while(T--)
	{
		int n;cin>>n;
		if(dp[n]==INF) cout<<0<<endl;
		else cout<<dp[n]<<endl;
	}
}
