//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
bool ha[128],used[128];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int n;
	while(cin>>n)
	{
		if(n==-1) break;
		memset(used,0,sizeof(used));
		memset(ha,0,sizeof(ha));
		cout<<"Round "<<n<<endl;
		string a,b;cin>>a>>b;
		for(int i=0;i<a.size();++i) ha[a[i]]=1;
		int cnt=0,lose=0;
		for(int i='a';i<='z';++i) cnt+=ha[i];
		for(int i=0;i<b.size();++i)
		{
			if(ha[b[i]])
			{
				if(used[b[i]]) continue;
				used[b[i]]=1;cnt--;
			}
			else lose++;
			if(cnt==0) break;
		}
		if(lose>=7) cout<<"You lose."<<endl;
		else if(cnt) cout<<"You chickened out."<<endl;
		else cout<<"You win."<<endl;
	}
}
