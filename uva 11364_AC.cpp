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
	while(T--)
	{
		int n,MAX=0,MIN=10000,x;cin>>n;
		while(n--){
			cin>>x;
			MAX=max(MAX,x);
			MIN=min(MIN,x);
		}
		cout<<((MAX-MIN)<<1)<<endl;
	}
}
