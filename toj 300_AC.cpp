//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 0x3f3f3f3f
int dp[205][205],a[205];

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int test;cin>>test;
	while(test--)
	{
		int n,m;cin>>n>>m;
		for(int i=1;i<=n;++i) cin>>a[i];
		memset(dp,INF,sizeof(dp));
		for(int i=1;i<=n;++i) dp[i][i]=1;
		for(int i=1;i<=n;++i)
			for(int j=1;j<n-i+1;++j)
				for(int k=j;k<=j+i;++k)
					if(a[j]==a[k])
						dp[j][j+i]=min(dp[j][j+i],(k==j?dp[k][k]:min(dp[j][k-1],dp[j+1][k])) + (k==j+i?0:dp[k+1][j+i]));

		cout<<dp[1][n]<<endl;
	}
}
