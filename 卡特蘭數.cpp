//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 100
int cat[maxn+2]={1,1};
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	for(int i=1;i<maxn;++i)
	{
		for(int j=0;j<=i;++j)
		{
			cat[i+1]+=cat[j]*cat[i-j];
		}
	}
	for(int i=0;i<20;++i) cout<<cat[i]<<endl;
//	int n;cin>>n;

}
