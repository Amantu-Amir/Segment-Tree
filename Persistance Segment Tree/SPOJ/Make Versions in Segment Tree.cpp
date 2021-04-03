#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define inf 2147483647

//---------------------------------------------------------------------------//
//Timus: 314795JS

//knight moves
//ll X[8] = {2, 1, -1, -2, -2, -1, 1, 2}; 	
//ll Y[8] = {1, 2, 2, 1, -1, -2, -2, -1}; 
//ll dx[]={1,-1,0,0};
//ll dy[]={0,0,1,-1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
ll toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
string toString(ll n){stringstream ss;ss<<n;string s;ss>>s;return s;}
string UPPER(string s){transform(all(s),s.begin(),::toupper);return s;}
string LOWER(string s){transform(all(s),s.begin(),::tolower);return s;}
bool isDigit(char ch){if(ch>=48 && ch<=57) return true; else return false;}
vector<ll>removeDup(vector<ll>v){sort(all(v)); v.resize(distance(v.begin(),unique(all(v))));return v;}
bool isVowel(char ch){ch=toupper(ch);if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E'){return true;}return false;}
bool isCons(char ch){if(isalpha(ch) && !isVowel(ch)){return true;} return false;}

//------------------------------------------------------------------------------//
const ll N=2e5+50;
const ll mod=1e9+7;

class Node{
public:
	ll left,right,val;
}tree[N*20];

ll id,curr;
vector<ll>A(N),root(N);

void build(ll node, ll b, ll e){
	if(b==e){
		tree[node].val=A[b];
		return;
	}
	ll mid=b+(e-b)/2;
	tree[node].left=++id;
	tree[node].right=++id;
	build(tree[node].left,b,mid);
	build(tree[node].right,mid+1,e);
	tree[node].val=tree[tree[node].left].val + tree[tree[node].right].val;
}

ll update(ll node, ll b, ll e, ll idx, ll value){
	if(b>idx or e<idx){
		return node;
	}
	if(b==e){
		tree[++id]=tree[node];
		tree[id].val+=value;
		return id;
	}
	ll mid=b+(e-b)/2;
	tree[++id]=tree[node];
	node=id;
	tree[node].left = update(tree[node].left,b,mid,idx,value);
	tree[node].right = update(tree[node].right,mid+1,e,idx,value);
	tree[node].val = tree[tree[node].left].val + tree[tree[node].right].val;
	return node;
}

ll query(ll node, ll b, ll e, ll L, ll R){
	if(b>R or e<L or b>e){
		return 0;
	}
	if(b>=L and e<=R){
		return tree[node].val;
	}
	ll mid=b+(e-b)/2;
	ll q1=query(tree[node].left,b,mid,L,R);
	ll q2=query(tree[node].right,mid+1,e,L,R);
	return q1+q2;
}

void init(ll n){
	root[0]=id=1;
	build(root[0],1,n);
}


int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll n; cin>>n;
		for(ll i=1; i<=n; i++){
			cin>>A[i];
		}
		init(n);
		ll q; cin>>q;
		for(ll i=1; i<=q; i++){
			ll type; cin>>type;
			if(type==1){
				ll version,idx,value;
				cin>>version>>idx>>value;
				root[++curr]=update(root[version],1,n,idx,value);
			}
			else{
				ll version,L,R;
				cin>>version>>L>>R;
				ll res=query(root[version],1,n,L,R);
				cout<<res<<"\n";
			}
		}
	}
	return 0;
}

