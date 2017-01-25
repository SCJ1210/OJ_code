//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define endl '\n'
int ma[128],mb[128];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	string a,b;
	while(cin>>a>>b)
	{
		memset(ma,0,sizeof(ma));
		memset(mb,0,sizeof(mb));
		int sz=a.size();
		for(int i=0;i<sz;++i) ma[a[i]]++,mb[b[i]]++;
		vector<int> x,y;
		for(int i='A';i<='Z';++i)
		{
			if(ma[i]) x.push_back(ma[i]);
			if(mb[i]) y.push_back(mb[i]);
		}
		bool YES=1;
		if(x.size()!=y.size()) YES=0;
		else{
			sort(x.begin(),x.end());
			sort(y.begin(),y.end());
			for(int i=0;i<x.size();++i)
				if(x[i]!=y[i]) YES=0;
		}
		if(YES) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
