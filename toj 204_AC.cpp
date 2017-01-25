//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[10005];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int n;
	while(cin>>n,n!=0)
	{
		for(int i=0;i<n;++i) cin>>a[i];
		sort(a,a+n);
		int ans=0,sum=0;
		for(int i=0;i<n-1;++i)
		{
			sum+=a[i];
			if(sum>=a[i+1]) ans=i+2;
		}
		cout<<ans<<endl;
	}
}
