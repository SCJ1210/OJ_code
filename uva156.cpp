#include<bits/stdc++.h>
using namespace std;

struct P{
	string a,b;
};
vector<P> es;
bool cmp(P x,P y)
{
	return x.a<y.a;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	string s;
	vector<string> ans;
	map<string,int> mp;
	while(cin>>s)
	{
		if(s=="#") break;
		string b=s;
		for(int i=0;i<s.size();++i)
		{
			if(s[i]>='A'&&s[i]<='Z') s[i]+=32;
		}
		sort(s.begin(),s.end());
		es.push_back({s,b});
		mp[s]++;
	}
	sort(es.begin(),es.end(),cmp);
	for(int i=0;i<es.size()-1;++i)
	{
		if(mp[es[i].a]==1) ans.push_back(es[i].b);
	}
	
	if(es[es.size()-2].a!=es[es.size()-1].a) ans.push_back(es[es.size()-1].b);
	sort(ans.begin(),ans.end());
	for(string s:ans) cout<<s<<endl;
}
