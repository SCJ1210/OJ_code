//By SCJ
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//int a[1000006];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	vector<int> a(1000001);
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;++i) cin>>a[i];
		sort(a.begin(),a.end());
		for(int i=0;i<n;++i) cout<<a[i]<<' ';cout<<endl;
	}
}
