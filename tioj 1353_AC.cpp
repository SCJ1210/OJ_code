//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 1000000
bool np[maxn+5]={1,1};
int cnt[maxn+5];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	for(int i=2;i<=maxn;++i)
	{
		if(!np[i]){
			cnt[i]++;
			for(int j=i+i;j<=maxn;j+=i) np[j]=1,cnt[j]++;
		}
	}
	int a,b;
	while(cin>>a>>b)
	{
		if(a>b) swap(a,b);
		int ans1=0,ans2=0;
		for(int i=a;i<=b;++i)
		{
			if(cnt[i]>ans2) ans2=cnt[i],ans1=i;
		}
		cout<<ans1<<' '<<ans2<<endl;
	}
}
