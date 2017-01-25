//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int ans[1002],b[1002];
bool useda[1002],usedb[1002];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int n,ca=1;
	while(cin>>n)
	{
		if(n==0) break;
		cout<<"Game "<<ca++<<":"<<endl;
		for(int i=0;i<n;++i) cin>>ans[i];
		while(1)
		{
			bool fg=1;
			for(int i=0;i<n;++i)
			{
				cin>>b[i];
				if(b[i]!=0) fg=0;
			}
			if(fg) break;
			int A=0,B=0;
			memset(useda,0,sizeof(useda));
			memset(usedb,0,sizeof(usedb));
			for(int i=0;i<n;++i)
				if(ans[i]==b[i]) A++,useda[i]=usedb[i]=1;
			for(int i=0;i<n;++i)
			{
				if(useda[i]) continue;
				for(int j=0;j<n;++j)
				{
					if(usedb[j]) continue;
					if(ans[i]==b[j])
					{
						usedb[j]=1;
						B++;
						break;
					}
				}
			}
			cout<<"    ("<<A<<","<<B<<")"<<endl;
		}
	}
}
