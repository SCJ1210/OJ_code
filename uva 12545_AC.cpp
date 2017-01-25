//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int T;cin>>T;
	for(int ca=1;ca<=T;++ca)
	{
		string a,b;cin>>a>>b;
		int qz=0,qo=0,z=0,o=0;
		for(int i=0;i<a.size();++i)
		{
			if(a[i]=='?'&&b[i]=='0') qz++;
			else if(a[i]=='?'&&b[i]=='1') qo++;
			else if(a[i]=='1'&&b[i]=='0') o++;
			else if(a[i]=='0'&&b[i]=='1') z++;
		}
		cout<<"Case "<<ca<<": ";
		if(z+qo<o) cout<<"-1"<<endl;
		else if(z>=o)cout<<qz+qo+z<<endl;
		else cout<<o+qo+qz<<endl;
	}
}
