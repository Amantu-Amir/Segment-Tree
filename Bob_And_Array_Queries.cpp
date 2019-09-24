///**Bismillahir Rahmanir Rahim.**
///Amantu Amir, University of Barishal, Bangladesh
///Accepted
#include <bits/stdc++.h>
using namespace std;
#define clr(a, v)             memset(a, v, sizeof a)
#define all(v)                v.begin(), v.end()
#define ast(v)                sort(v.begin(),v.end())
#define dst(v)                sort(v.begin(),v.end(), greater <int> ())
#define fast ios_base::       sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ass(cur, v)           cur.assign(v.begin(), v.end())
#define int                   long long int
#define rep(i, l, r)          for (int i = l; i < r; i++)
#define rep2(i, l, r)         for (int i = l-1; i >= r; i--)
#define sfs(s)                scanf("%s", s)
#define sfl(n)                scanf("%lld", &n)
#define sffl(n, m)            scanf("%lld %lld",&n,&m)
#define sfffl(n, m, o)        scanf("%d %d %d",&n,&m, &o)
#define pf(n)                 printf("%d", n)
#define debug                 cout << " debug\n"
#define yes                   cout << "YES\n"
#define no                    cout << "NO\n"
#define sp                    cout << " "
#define nl                    cout << "\n"
#define prln(n)               printf("%d\n", n)
#define pfl(n)                printf("%lld\n", n)
#define I(n)                  cin >> n
#define II(n, m)              cin >> n >> m
#define III(a, b, c)          cin >> a >> b >> c
#define small(a, b, c)        min(a, min(b, c))
#define big(a, b, c)          max(a, max(b, c))
#define P(n)                  cout << n
#define PP(n, m)              cout << n << " " << m << "\n"
#define PPP(a, b, c)          cout << a << " " << b << " " << c << "\n"
#define rt(n)                 return n
#define mid(b, e)             (b+e)/2
#define left(node)            node*2
#define right(node)           node*2+1
#define pii                   pair<int,int>
#define mp                    make_pair
#define pb                    push_back
#define S                     second
#define F                     first
#define PI                    3.1415926

struct greaters{
    bool operator()(const long& a, const long& b) const{
        return a > b;
    }
};

int x_move[] = {2, 1, -1, -2, -2, -1, 1, 2};
int y_move[] = {1, 2, 2, 1, -1, -2, -2, -1};

string toString(int n){
    stringstream ss; ss << n;
    string s; ss >> s;
    return s;
}

int toInt(string s){
    stringstream ss; ss << s;
    int n; ss >> n;
    return n;
}


//Template end
//-------------------******Alhamdulillah******--------------------//

const int N = 5e5+50;
const int mod = 1e9+7;

void reset(){
 
}

int flag, tree[N*4];
void update(int node, int b, int e, int idx){
    if(b == idx and e == idx){
        if(flag){
            tree[node]++;
        }
        else{
            if(tree[node]>0){
                tree[node]--;
            } 
        }
        return;
    }
    if(idx >= b and idx <= mid(b,e)){
        update(node*2, b, mid(b,e), idx);
    }
    else{
        update(node*2+1, mid(b,e)+1, e, idx);
    }
    tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int node, int b, int e, int l, int r){
    if(b>r or e<l or b>e){
        return 0;
    }
    if(b>=l and e<=r){
        return tree[node];
    }
    int q1 = query(node*2, b, mid(b,e), l, r);
    int q2 = query(node*2+1, mid(b,e)+1, e, l, r);
    return q1+q2;
}

int32_t main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    int tc = 1, cas = 0;
    while(tc--){
        //reset();
        int n,q; II(n,q);
        while(q--){
            int op; I(op);
            if(op == 1){
                int x; I(x);
                flag = 1;
                update(1,1,n,x);
            }
            else if(op == 2){
                int x; I(x);
                flag = 0;
                update(1,1,n,x);
            }
            else{
                int l, r; II(l,r);
                P(query(1,1,n,l,r)); nl;
            }
        }
    }
    return 0;
}
 
//--------------------******Alhamdulillah******-------------------//
