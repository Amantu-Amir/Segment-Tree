#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 1e5+50;

vector<int>v,res(35);
vector<int>tree[N*3];
void build(int node, int b, int e){
	if(b==e){
		int a = v[b];
		//cout<<a<<"\n";
		for(int i=0; i<=32; i++){
			if(a>0){
				int rem = a%2; a/=2;
				tree[node].push_back(rem);
			}
			else{
				tree[node].push_back(0);
			}
		}
		//reverse(tree[node].begin(),tree[node].end());
		/*for(int i=0; i<=32; i++){
			cout<<tree[node][i]<<" ";
		}
		cout<<"\n";*/
		return;
	}
	int mid = b+(e-b)/2;
	build(node*2,b,mid);
	build(node*2+1,mid+1,e);
	for(int i=0; i<=32; i++){
		tree[node].push_back(tree[node*2][i] + tree[node*2+1][i]);
	}
}

void query(int node, int b, int e, int l, int r, int k){
	if(b>r or e<l or b>e) return;
	if(b>=l and e<=r){
		for(int i=0; i<=32; i++){
			res[i] = res[i] + tree[node][i];
		}
		return;
	}
	int mid = b+(e-b)/2;
	query(node*2,b,mid,l,r,k);
	query(node*2+1,mid+1,e,l,r,k);
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("CodeChef.txt","r",stdin);
	int n; cin>>n;
	v.resize(n+1);
	for(int i=1; i<=n; i++){
		cin>>v[i];
	}
	build(1,1,n);
	int q; cin>>q;
	for(int i=0; i<q; i++){
		int l,r,k; cin>>l>>r>>k;
		res.clear(); res.resize(35,0);
		query(1,1,n,l,r,k);
		int ok=0;
		for(int i=0; i<=32; i++){
			//cout<<res[i]<<" ";
			if(res[i]>=k){
				ok=1; break;
			}
		}
		if(ok) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
