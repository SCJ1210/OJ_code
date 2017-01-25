//By SCJ
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
ull dp[66][66],O[66],Z[66],Onum,Znum;
ull P[66]={1};
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	for(int i=1;i<66;++i) P[i]=P[i-1]*2;
	int n,d,ca=1;
	ull k;
	while(cin>>n,n!=0)
	{
		cin>>d>>k;
		memset(dp,0,sizeof(dp));
		Onum=Znum=0;dp[0][0]=1;
		ull tp=k;
		stack<int> s;
		while( tp ) s.push(tp%2),tp/=2;
		while( s.size() < n ) s.push(0);
		vector< int > v;
		while( s.size() ) v.push_back( s.top() ) , s.pop();
		for(int i=0;i<n;++i)
		{
			if(v[i]) O[++Onum]=i;
			else Z[++Znum]=i;
		}
		for(int i=0;i<=Znum;++i)
		{
			for(int j=0;j<=Onum;++j)
			{
				if(j==Onum||O[j+1]+d>=Z[i+1]) dp[i+1][j]+=dp[i][j];
				if(i==Znum||Z[i+1]+d>=O[j+1]) dp[i][j+1]+=dp[i][j];
			}
		}
		vector<int> MAX,MIN;
		queue<int> zero,one;
		for(int i=0;i<n;++i)
		{
			if(v[i]) one.push(i+d),MAX.push_back(1);
			else zero.push(i+d),MIN.push_back(0);
			while(one.size()&&one.front()==i) MIN.push_back(1),one.pop();
			while(zero.size()&&zero.front()==i) MAX.push_back(0),zero.pop();
		}
			while(one.size()) MIN.push_back(1),one.pop();
			while(zero.size()) MAX.push_back(0),zero.pop();
		ull aMAX=0,aMIN=0;
		for(int i=0;i<n;++i) aMAX+=P[n-i-1]*MAX[i];
		for(int i=0;i<n;++i) aMIN+=P[n-i-1]*MIN[i];
		cout<<"Case "<<ca++<<": "<<dp[Znum][Onum]<<' '<<aMIN<<' '<<aMAX<<endl;
	}
}
