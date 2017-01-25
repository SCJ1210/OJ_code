//By SCJ
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 0x3f3f3f3f
#define maxn 10004
int a[maxn],dp[maxn],LIS1[maxn],LIS2[maxn];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int n;
	while(cin>>n)
	{
		memset(dp,INF,sizeof(dp));
		for(int i=0;i<n;++i) cin>>a[i];
		int ma=0;
		for(int i=0;i<n;++i)
		{
			int d=lower_bound(dp,dp+ma,a[i])-dp;
			if(d==ma) ma++;
			dp[d]=a[i];
			LIS1[i]=d;
		}
		memset(dp,INF,sizeof(dp));
		for(int i=n-1;i>=0;--i)
		{
			int d=lower_bound(dp,dp+ma,a[i])-dp;
			if(d==ma) ma++;
			dp[d]=a[i];
			LIS2[i]=d;
		}
		int ans=0;
		for(int i=0;i<n;++i) ans=max(ans,min(LIS1[i],LIS2[i])*2+1);
		cout<<ans<<endl;
	}
}
