//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF 10000000000000000
int G[25][25][25];
main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int T;cin>>T;
	while(T--)
	{
		int a,b,c;cin>>a>>b>>c;
		for(int i=1;i<=a;++i)
			for(int j=1;j<=b;++j)
				for(int k=1;k<=c;++k)
					cin>>G[i][j][k];
		for(int i=1;i<=a;++i)
		{
			for(int j=1;j<=b;++j)
				for(int k=1;k<c;++k)
					G[i][j][k+1]+=G[i][j][k];
			for(int k=1;k<=c;++k)
				for(int j=1;j<b;++j)
					G[i][j+1][k]+=G[i][j][k];
		}
		int ans=-INF;
		for(int x1=1;x1<=b;++x1)
		{
			for(int y1=1;y1<=c;++y1)
			{
				for(int x2=x1;x2<=b;++x2)
				{
					for(int y2=y1;y2<=c;++y2)
					{
						int MIN=0,sum=0;
						for(int i=1;i<=a;++i)
						{
							sum+=G[i][x2][y2]-G[i][x1-1][y2]-
								 G[i][x2][y1-1]+G[i][x1-1][y1-1];
							ans=max(ans,sum-MIN);
							MIN=min(MIN,sum);
						}
					}
				}
			}
		}
		cout<<ans<<endl;
		if(T) cout<<endl;
	}
}
/*
2
2 2 2
-1 2 0 -3 -2 -1 1 5
2 2 2
-1 -2 -2 -3 -4 -5 -6 -7
*/
