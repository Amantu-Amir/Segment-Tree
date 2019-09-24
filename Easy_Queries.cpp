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

const int N = 2e5+5;
const int mod = 1e9+7;

void reset(){
 
}
 
int32_t main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    int tc = 1, cas = 0;
    while(tc--){
        //reset();
        int n, q; II(n, q); 
        set <int> st;
        set <int> :: iterator it;
        set <int> :: iterator it2;
        int a[n+5];
        rep(i, 0, n){
            I(a[i]); 
            if(a[i] == 1){
                st.insert(i);
            }
        }
        while(q--){
            int op, x; II(op, x);
            if(op == 0){
                it = st.lower_bound(x);
                it2 = st.upper_bound(x);
                int L = -1, R = -1;
                if(it != st.begin() and st.size()){
                    --it;
                    L = *it;
                }
                if(it2 != st.end() and st.size()){
                    R = *it2;
                }
                PP(L, R);
            }
            else{
                if(a[x] == 0){
                    st.insert(x);
                }
            }
        }
    }
    return 0;
 
}
 
//--------------------******Alhamdulillah******-------------------//
