//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 100000000
int dp[205][55],t[55];
bool h[205][55][2];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int N,T,ca=1;
	while(cin>>N,N)
	{
		memset(h,0,sizeof(h));
		cin>>T;
		for(int i=1;i<N;++i) cin>>t[i];
		int M1,M2;
		cin>>M1;
		for(int k=1;k<=M1;++k)
		{
			int x;cin>>x;
			for(int i=1;x<=T&&i<N;x+=t[i++]) h[x][i][0]=1;
		}
		cin>>M2;
		for(int k=1;k<=M2;++k)
		{
			int x;cin>>x;
			for(int i=N;x<=T&&i>0;x+=t[--i]) h[x][i][1]=1;
		}
		for(int j=1;j<N;++j) dp[T][j]=INF;
		dp[T][N]=0;
		for(int i=T;i>=0;--i)
		{
//			cout<<"i="<<i<<endl;
			for(int j=1;j<=N;++j)
			{
				if(i!=T) dp[i][j]=dp[i+1][j]+1;
				if(j>1&&h[i][j][1]&&i+t[j-1]<=T) dp[i][j]=min(dp[i][j],dp[i+t[j-1]][j-1]);
				if(j<N&&h[i][j][0]&&i+t[j]<=T) dp[i][j]=min(dp[i][j],dp[i+t[j]][j+1]);
//				cout<<dp[i][j]<<" ";
			}
//			cout<<endl;
		}

		cout<<"Case Number "<<ca++<<": ";
		if(dp[0][1]>=INF) cout<<"impossible"<<endl;
		else cout<<dp[0][1]<<endl;
	}
}
