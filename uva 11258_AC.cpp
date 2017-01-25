//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define IMAX 2147483647
int dp[202],P[15]={1};
main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int T;cin>>T;
	for(int i=1;i<15;++i) P[i]=P[i-1]*10;
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		string s;cin>>s;
		int sz=s.size();
		dp[sz-1]=s[sz-1]-'0';
		for(int i=sz-1;i>=0;--i)
		{
			int sum=0;
			for(int j=i;j>=0;j--)
			{
				sum+=(s[j]-'0')*P[i-j];
				if(sum>IMAX) break;
				dp[j]=max(dp[j],sum+dp[i+1]);
			}
		}
		cout<<dp[0]<<endl;
	}
}
