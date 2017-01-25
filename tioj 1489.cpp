//By SCJ
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 100000000
int cnt[128];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int n;
	while(cin>>n,n!=0)
	{
		cin.get();
		memset(cnt,0,sizeof(cnt));
		string s;getline(cin,s);
		int l=0,r=0,left=26,a=0,b=INF;
		while(r<=n)
		{
			if(left==0)
			{
				if(r-l<b-a) a=l,b=r;
				--cnt[s[l]];
				if(cnt[s[l]]==0) ++left;
				++l;
			}
			else
			{
				if(r==n) break;
				++cnt[s[r]];
				if(cnt[s[r]]==1) --left;
				++r;
			}
		}
		if(b!=INF){
			for(int i=a;i<b;++i) cout<<s[i];cout<<endl;
		}
		else cout<<"not found\n";
	}

}
