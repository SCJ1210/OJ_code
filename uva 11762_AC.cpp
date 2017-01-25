//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 1000006
double f[maxn];
vector<int> p;
bool np[maxn];
double dp(int x)
{
	if(f[x]!=-1) return f[x];
	int g=0,cnt=0;f[x]=0;
	for(int i:p)
	{
		if(i>x) break;
		cnt++;
		if(x%i==0)
		{
			g++;
			f[x]+=dp(x/i);
		}
	}
	f[x]=(f[x]+cnt)/g;
//	cout<<"f["<<x<<"]="<<f[x]<<endl;
//	cout<<cnt<<' '<<g<<endl;
	return f[x];
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	for(int i=2;i<maxn;++i)
	{
		if(!np[i])
		{
			p.push_back(i);
			for(int j=i+i;j<maxn;j+=i) np[j]=1;
		}
	}
	for(int i=0;i<maxn;++i) f[i]=-1;
	f[1]=0;
	int T;cin>>T;
	cout<<fixed<<setprecision(8);
	for(int ca=1;ca<=T;++ca)
	{
		int n;cin>>n;
		cout<<"Case "<<ca<<": ";
		cout<<dp(n)<<endl;
	}
}
