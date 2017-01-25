//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ing long long
main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int x[4],y[4],T;
	cin>>T;
	while(T--)
	{
		int ans=0;
		for(int i=0;i<3;++i) cin>>x[i]>>y[i],x[i]+=1000,y[i]+=1000;
		x[3]=x[0];y[3]=y[0];
		for(int i=1;i<=3;++i)
		{
			int a=abs(x[i]-x[i-1]),b=abs(y[i]-y[i-1]);
			int A=(a+1)*(b+1)-2;
			int g=__gcd(a,b);
			A-=g-1;
			A/=2;
			ans+=A;
		}
		sort(x,x+3);
		sort(y,y+3);
		int all=(x[2]-x[0]+1)*(y[2]-y[0]+1);
		cout<<all-ans<<endl;
	}
}
