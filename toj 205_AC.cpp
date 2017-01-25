//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 2005
int p[maxn],dp[maxn][maxn],go[maxn],back[maxn],c[maxn],start[maxn];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int test;cin>>test;
	while(test--)
	{
		int n;cin>>n;
		for(int i=1;i<=n;++i) cin>>p[i]>>go[i]>>c[i],back[i]=go[i];
		for(int i=2;i<=n;++i) c[i]+=c[i-1],p[i]+=p[i-1];
		int MIN=back[n];
		for(int i=n-1;i>0;--i)
		{
			MIN=min(back[i],MIN+c[i]-c[i-1]);
			back[i]=MIN;
		}
//		cout<<"back : ";
//		for(int i=1;i<=n;++i)
//		{
//			cout<<back[i]<<' ';
//		}
//		cout<<endl;
		int B,R;cin>>B>>R;
		memset(start,0,sizeof(start));
		for(int i=1;i<=n;++i)
		{
			for(int j=i;j>0;--j)
			{
				int sum=c[i-1]-c[j-1]+go[i]+back[j];
				if(sum<=B) start[i]=j;
				//else break;
			}
		}
//		cout<<"start :";
//		for(int i=1;i<=n;++i) cout<<start[i]<<' ';
//		cout<<endl;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=R;++j)
			{
				dp[i][j]=dp[i-1][j];
				if(start[i]) dp[i][j]=max(dp[i][j],dp[start[i]-1][j-1]+p[i]-p[start[i]-1]);
			}
		}
		cout<<dp[n][R]<<endl;
	}
}
/*
2
3
10 2 3
10 4 2
10 5 5
11 1
3
10 2 3
10 4 2
10 5 5
11 2

2
1
100 10 10
20 1
1
100 10 10
10 1
*/
