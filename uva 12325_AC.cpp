//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int T;cin>>T;
	for(int ca=1;ca<=T;++ca)
	{
		int n,w1,v1,w2,v2,x1,x2,ans=0;
		cin>>n>>w1>>v1>>w2>>v2;
		if(v1*w2<v2*w1) swap(v1,v2),swap(w1,w2);
		int gd=__gcd(w1,w2),A=w1/gd;
		for(int i=0;i<=A;++i)
		{
			if(i*w2>n) break;
			ans=max(ans,i*v2+(n-i*w2)/w1*v1);
		}
		cout<<"Case #"<<ca<<": "<<ans<<endl;
	}
}
