//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 100000000
struct P{
	int a,b,id;
	bool operator < (const P &rhs)const{
		return a<rhs.a;
	}
}d[1005];
int dp[1005],pa[1005];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int n=1,ans=0,ap;
	while(cin>>d[n].a>>d[n].b) d[n].id=n,++n;
	sort(d+1,d+n+1);
	d[0]={-INF,INF,0};
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<i;++j)
		{
			if(d[i].a>d[j].a&&d[i].b<d[j].b&&dp[j]+1>dp[i])
			{
				dp[i]=dp[j]+1;pa[i]=j;
				if(ans<dp[i]) ans=dp[i],ap=i;
			}
		}
	}
	cout<<ans<<endl;
	stack<int> st;
	for(int i=ap;i!=0;i=pa[i]) st.push(d[i].id);
	while(st.size()) cout<<st.top()<<endl,st.pop();
}
