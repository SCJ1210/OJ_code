//By SCJ
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 200005
#define INF 0x3f3f3f3f
int dp[maxn];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int T;cin>>T;
	while(T--)
	{
		int n;cin>>n;
		memset(dp,INF,sizeof(dp));dp[0]=-INF;
		int com=0,last=-INF,ans=0,cnt=0;
		for(int r=0;r<n;++r)
		{
			int x;cin>>x;
			if(x>last) com++,cnt++;
			else com=1,cnt=1;
			dp[com]=min(dp[com],x);
			cnt=max(cnt,(int)(lower_bound(dp,dp+n,x)-dp));
			ans=max(ans,cnt);
			last=x;
		}
		cout<<ans<<endl;
	}
}
