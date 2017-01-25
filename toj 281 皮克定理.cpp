//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 100000000
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int T;cin>>T;
	while(T--)
	{
		int x[4],y[4];
		for(int i=0;i<3;++i) cin>>x[i]>>y[i];
		x[3]=x[0];y[3]=y[0];
		int minx=INF,miny=INF,maxx=-INF,maxy=-INF;
		int dot_on_edge=3;
		double A=0;
		for(int i=1;i<4;++i)
		{
			int a=abs(x[i]-x[i-1]);
			int b=abs(y[i]-y[i-1]);
			A-=a*b/2.0;
			minx=min(minx,x[i]);
			miny=min(miny,y[i]);
			maxx=max(maxx,x[i]);
			maxy=max(maxy,y[i]);
			dot_on_edge+=__gcd(a,b)-1;
		}
		A+=(maxx-minx)*(maxy-miny);
		int dot_in_grath=A-dot_on_edge/2.0+1;
		cout<<dot_in_grath+dot_on_edge<<endl;
	}
}
