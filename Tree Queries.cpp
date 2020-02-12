#include<bits/stdc++.h>
#define int long long int
#define all(v) v.begin(), v.end()
using namespace std;
const int N=5e5+50;

vector<int>G[N];
vector<int>tree[N*3];
vector<int>a, ar(N), st(N), et(N);
int n, t;

void dfs(int root){
	st[root] = ++t;
	ar[t] = a[root];
	for(auto child:G[root]){
        dfs(child);
	}
	et[root] = t;
}

void build(int node, int b, int e){
    if(b==e){
        tree[node].push_back(ar[b]);
        return;
    }
    int mid = b+(e-b)/2;
    build(node*2,b,mid);
    build(node*2+1,mid+1,e);
    merge(all(tree[node*2]), all(tree[node*2+1]), back_inserter(tree[node]));
}

int query(int node, int b, int e, int l, int r, int val){
    if(b>r or e<l or b>e) return 0;
    if(b>=l and e<=r){
        int siz = tree[node].size();
        int temp = lower_bound(all(tree[node]),val)-tree[node].begin();
        return siz-temp;
    }
    int mid = b+(e-b)/2;
    int q1 = query(node*2, b, mid, l, r, val);
    int q2 = query(node*2+1, mid+1, e, l, r, val);
    return q1+q2;
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt","r",stdin);

	int m,par; cin>>n>>m;
	for(int i=2; i<=n; i++){
		cin>>par;
		G[par].push_back(i);
	}
	a.resize(n+1);
	for(int i=1; i<=n; i++){
        cin>>a[i];
	}
	dfs(1);
    build(1,1,n);
    for(int i=1; i<=m; i++){
        int ver,val; cin>>ver>>val;
        int res = query(1,1,n,st[ver],et[ver],val);
        cout<<res<<"\n";
    }
	return 0;
}





