#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 1e4+50;

int pre, res;
vector<int> v(N);
vector<int> tree[N*4];
void build(int node, int b, int e){
	if(b == e){
		tree[node].push_back(v[b]);
		return;
	}
	int mid = b+(e-b)/2;
	build(node*2, b, mid);
	build(node*2+1, mid+1, e);
	merge(tree[node*2].begin(), tree[node*2].end(), tree[node*2+1].begin(), tree[node*2+1].end(),
		back_inserter(tree[node]));
	/*cout<<node<<"\n";
	for(int i=0; i<tree[node].size(); i++){
		cout<<tree[node][i]<<" ";
	}
	cout<<"\n";*/
}
void query(int node, int b, int e, int l, int r){
	if(b > r or e < l or b > e) return;
	if(b >= l and e <= r){
		int len = tree[node].size();
		int val = tree[node][len-1];
		int lb = lower_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();
		if(pre < val){
			pre = val; res = len-lb;
		}
		else if(pre == val){
			res += (len-lb);
		}
		return;
	}
	int mid = b+(e-b)/2;
	query(node*2, b, mid, l, r);
	query(node*2+1, mid+1, e, l, r);
}

void reset(){
	for(int i=0; i<(N*4)-5; i++){
		tree[i].clear();
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	int tc = 1; cin>>tc;
	for(int T=1; T<=tc; T++){
		reset();
		int n,q; cin>>n>>q;
		for(int i=1; i<=n; i++){
			cin>>v[i];
		}
		build(1,1,n);
		cout<<"Case "<<T<<":\n";
		for(int i=1; i<=q; i++){
			int l,r; cin>>l>>r;
			pre = -(1<<30), res = 0;
			query(1,1,n,l+1,r+1);
			cout<<res<<"\n";
		}
	}
	return 0;
}