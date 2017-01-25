//By SCJ
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 100005
int w[22],v[22],dp[22][maxn],m;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int n;
	while(cin>>m>>n)
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i)
			cin>>w[i],v[i]=w[i];
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(j<w[i]) dp[i][j]=dp[i-1][j];
				else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
		stack<int> st;
		for(int x=n,y=m;x!=0;--x)
		{
			if(dp[x][y]==dp[x-1][y]) continue;
			st.push(w[x]);y-=w[x];
		}
		while(st.size()) cout<<st.top()<<' ',st.pop();
		cout<<"sum:"<<dp[n][m]<<endl;
	}
}
