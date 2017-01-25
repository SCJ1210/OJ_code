//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int unsigned int
int e[1005];
void pfip(int x)
{
	for(int i=0;i<4;++i)
	{
		if(i) cout<<'.';
		int tp=(x<<(i*8));
		tp=(tp>>24);
		cout<<tp;
	}
}
main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;++i)
		{
			int a,b,c,d;
			char tp;
			cin>>a>>tp>>b>>tp>>c>>tp>>d;
			e[i]=0;
			e[i]+=(a<<24);
			e[i]+=(b<<16);
			e[i]+=(c<<8);
			e[i]+=d;
		}
		int S=(1LL<<32)-1;
		for(int i=0;i<32;++i)
		{
			bool fg=1;
			for(int j=1;j<n;++j)
			{
				if((e[j]&S)!=(e[j-1]&S)) {fg=0;break;}
			}
			if(fg) break;
			S-=(1LL<<i);
		}
		pfip((S&e[0])&S);cout<<endl;
		pfip(S);cout<<endl;
	}
}
