//By SCJ
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
#define endl '\n'
#define INF 1000000000
#define maxn 131072
inline int rd()
{
	return rand()*rand();
}
struct treap;
treap *nul;
struct treap{
	int sz,val,pri;
	treap *l,*r;
	treap(int v):sz(1),val(v),pri(rd()),l(nul),r(nul){}
	inline void up()
	{
		sz=l->sz+r->sz+1;
		//zero=l->zero|r->zero;
	}
};

inline treap *merge(treap *a,treap *b)
{
	if(a==nul) return b;
	if(b==nul) return a;
	if(a->pri > b->pri){
		a->r=merge(a->r,b);
		a->up();
		return a;
	}
	else{
		b->l=merge(a,b->l);
		b->up();
		return b;
	}
}

inline void split(treap *t,int k,treap *&a,treap *&b)
{
	if(t==nul){a=b=nul;return ;}
	int asz=t->l->sz+1;
	if(asz<=k){
		a=t;
		split(t->r,k-asz,a->r,b);
	}
	else{
		b=t;
		split(t->l,k,a,b->l);
	}
	t->up();
}

//int seg[maxn*8];
//void build(int l,int r,int i)
//{
//	if(l==r) {seg[i]=l;return ;}
//	int mid=(l+r)/2;
//	build(l,mid,i*2);
//	build(mid+1,r,i*2+1);
//	seg[i]=min(seg[i*2],seg[i*2+1]);
//}
//void update(int l,int r,int i,int qx)
//{
//	if(l==r){seg[i]=INF;return ;}
//	int mid=(l+r)/2;
//	if(qx<=mid) update(l,mid,i*2,qx);
//	else update(mid+1,r,i*2+1,qx);
//	seg[i]=min(seg[i*2],seg[i*2+1]);
//}
//
//int query(int l,int r,int i,int ql,int qr)
//{
//	if(r<ql||l>qr) {return INF;}
//	if(l>=ql&&r<=qr) return seg[i];
//	int mid=(l+r)/2;
//	return min(query(l,mid,i*2,ql,qr),query(mid+1,r,i*2+1,ql,qr));
//}

int pa[maxn*2];
inline void init(int n)
{
	for(int i=0;i<=n;++i) pa[i]=i;
}
inline int find(int x)
{
	if(pa[x]==x) return x;
	return pa[x]=find(pa[x]);
}

inline void U(int x,int y)
{
	x=find(x);y=find(y);
	pa[x]=y;
}

inline void pf(treap *t)
{
	if(t->l!=nul) pf(t->l);
	printf("%d ",t->val);
	if(t->r!=nul) pf(t->r);
}

int main()
{
	srand(7122);
	nul=new treap(0);nul->sz=0;
	treap *root=nul;
	int n,m,W=0;
	scanf("%d%d",&m,&n);
	int NM=n+m+1;
	for(int i=0;i<NM;++i)
		root=merge(root,new treap(0));
//	build(1,NM,1);
	init(NM);
	for(int i=1;i<=m;++i)
	{
		int L,R;scanf("%d",&L);
//		R=query(1,NM,1,L,NM);
//		update(1,NM,1,R);
		R=find(L);
		U(R,find(R+1));
		W=max(W,R);
		treap *a,*b,*c,*tp;
		if(L==R){
			split(root,L-1,a,c);
			split(c,1,b,c);
			b->val=i;
			root=merge(merge(a,b),c);
		}
		else{
			split(root,R-1,b,c);
			split(c,1,tp,c);
			split(b,L-1,a,b);
			root=merge(merge(a,new treap(i)),merge(b,c));
		}
	}
	printf("%d\n",W);
	treap *tp;
	split(root,W,root,tp);
	pf(root);puts("");
}
