//By SCJ
#include<iostream>
using namespace std;
#define endl '\n'
struct Node{
	int flag,ans;
}seg[100005*8];

inline void down(int i)
{
	if(seg[i].flag) seg[i<<1]=seg[i<<1|1]=seg[i],seg[i].flag=0;
}

inline void up(int i)
{
	seg[i].ans=seg[i<<1].ans|seg[i<<1|1].ans;
}

inline void build(int l,int r,int i)
{
	if(l==r)
	{
		seg[i].flag=1;
		seg[i].ans=(1<<1);
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,i<<1);
	build(mid+1,r,i<<1|1);
	up(i);
}

inline void update(int l,int r,int i,int ql,int qr,int c)
{
	if(r<ql||l>qr) return ;
	down(i);
	if(l>=ql&&r<=qr)
	{
		seg[i].flag=c;
		seg[i].ans=(1<<c);
		return ;
	}
	int mid=(l+r)>>1;
	update(l,mid,i<<1,ql,qr,c);
	update(mid+1,r,i<<1|1,ql,qr,c);
	up(i);
}

inline int query(int l,int r,int i,int ql,int qr)
{
	if(r<ql|l>qr) return 0;
	down(i);
	if(l>=ql&&r<=qr) return seg[i].ans;
	int mid=(l+r)>>1;
	return query(l,mid,i<<1,ql,qr)|query(mid+1,r,i<<1|1,ql,qr);
}

inline int cntbit(int x)
{
	int res=0;
	while(x)
	{
		res+=(x&1);
		x>>=1;
	}
	return res;
}

int main()
{
	int n,T,m;
	scanf("%d%d%d",&n,&T,&m);
	build(1,n,1);
	while(m--)
	{
		getchar();
		char ch;ch=getchar();
		int a,b,c;
		if(ch=='C')
		{
			scanf("%d%d%d",&a,&b,&c);
			if(a>b) swap(a,b);
			update(1,n,1,a,b,c);
		}
		else
		{
			scanf("%d%d",&a,&b);
			if(a>b) swap(a,b);
			printf("%d\n",cntbit(query(1,n,1,a,b)));
		}
	}
}
