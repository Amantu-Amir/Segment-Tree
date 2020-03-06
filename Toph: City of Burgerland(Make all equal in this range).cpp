///**Bismillahir Rahmanir Rahim.**
///Make all element equal in a range, find min cost. You can add or sub 1 for 1 cost
#include <bits/stdc++.h>
#define int                   long long int
#define clr(a, v)             memset(a,v,sizeof a)
#define all(v)                v.begin(),v.end()
#define ast(v)                sort(all(v))
#define sfs(s)                scanf("%s", s)
#define sf(n)                 scanf("%lld", &n)
#define sff(n, m)             scanf("%lld %lld",&n,&m)
#define dst(v)                sort(all(v),greater<int>())
#define sfff(n, m, o)         scanf("%lld %lld %lld",&n,&m,&o)
#define PP(n, m)              cout << n << " " << m << "\n"
#define PPP(a, b, c)          cout<<a<<" "<<b<<" "<<c<<"\n"
#define MX(a)                 *max_element(all(a))
#define MI(a)                 *min_element(all(a))
#define SUM(a)                accumulate(all(a),0)
#define I(n)                  cin >> n
#define II(n, m)              cin >> n >> m
#define III(a, b, c)          cin >> a >> b >> c
#define MIN(a, b, c)          min(a, min(b, c))
#define MAX(a, b, c)          max(a, max(b, c))
#define MID(b, e)             (b+(e-b)/2)
#define CAS(a)                cout << "Case " << a << ":"
#define pf(n)                 printf("%lld", n)
#define pff(n,m)              printf("%lld %lld\n",n,m)
#define prln(n)               cout<<n<<"\n"
#define P(n)                  cout << n
#define debug                 cout << " debug\n"
#define yes                   cout << "Yes\n"
#define no                    cout << "No\n"
#define minus1                cout << "-1\n"
#define zero                  cout << "0\n"
#define sp                    cout << " "
#define nl                    cout << "\n"
#define pii                   pair<int,int>
#define mp                    make_pair
#define pb                    push_back
#define S                     second
#define F                     first
#define inf                   (1<<30)

using namespace std;
const int N = 1e5+50;
const int mod = 1e9+7;
bool is_prime[N+50];
//cout<<fixed<<showpoint;
//cout<<setprecision(12)<<res<<"\n";
vector<int>prime,primeFactor;
int digit(int n){return log10(n)+1;}
int bit_on(int n,int pos){return n=n|(1<<pos);}
int bit_off(int n,int pos){return n=n&~(1<<pos);}
bool check(int n,int pos){return (bool)(n&(1<<pos));}
void fast(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
string toString(int n){stringstream ss;ss<<n;string s;ss>>s;return s;}
int toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
bool isVowel(char ch){ ch=tolower(ch); if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true; return false;}
bool isConst(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}
double dis(double x, double y, double x2, double y2){double res = sqrt(pow(x-x2,2) + pow(y-y2,2));return res;}
void sieve(){prime.push_back(2);for(int i=4;i<=N;i+=2)is_prime[i]=1;for(int i=3; i<N; i+=2){if(is_prime[i] == 0)
{prime.push_back(i);for(int j = i*i; j<N; j += (i*2))is_prime[j]=1;}}}
bool isPrime(int n){if(n == 1) return false;if(n == 2) return true;if(n%2 == 0) return false;
for(int i = 3; i * i <= n; i += 2 )if(n%i == 0) return false;return true;}
void primeFac(int n){int tmp = sqrt(n);for(int i = 0; prime[i] <= tmp; i++){if(n%prime[i] == 0)
{while(n%prime[i] == 0){n /= prime[i];primeFactor.pb(prime[i]);}}}if(n > 1)primeFactor.pb(n);}
int SOD(int n){int sum = 1;for(int i = 0; prime[i] <= n; i++){if(n%prime[i] == 0){int cnt = 1;
while(n%prime[i] == 0){n /= prime[i];cnt++;}sum *= (pow(prime[i], cnt) - 1)/ (prime[i] - 1);}}return sum;}
int NOD(int n){int till=sqrt(n+1);int p,divisor=1;for(int i=0;prime[i]<=till;i++){if(n%prime[i]==0){p=1;
while(n%prime[i]==0){n/=prime[i];p++;}till=sqrt(n);divisor*=p;}}if(n>1)divisor*=2;return divisor;}
bool isDigit(char ch){if(ch >= 48 && ch <= 57) return true; else return false;}
string Upper(string s){transform(all(s),s.begin(),::toupper);return s;}
string Lower(string s){transform(all(s),s.begin(),::tolower);return s;}
int fx[]={0,0,1,-1};    //grid visit
int fy[]={1,-1,0,0};
//Template end
//-------------------******Alhamdulillah******--------------------//

vector<int>v;
vector<int>tree[N*3],cum[N*3];

void myMerge(int node){
    int left = tree[node*2].size();
    int right = tree[node*2+1].size();
    int L = 0, R = 0, Sum = 0;
    while(L<left && R<right){
        if(tree[node*2][L]>tree[node*2+1][R]){
            tree[node].pb(tree[node*2+1][R]);
            Sum += tree[node*2+1][R];
            cum[node].pb(Sum); R++;
        }
        else{
            tree[node].pb(tree[node*2][L]);
            Sum += tree[node*2][L];
            cum[node].pb(Sum); L++;
        }
    }
    while(L<left){
        tree[node].pb(tree[node*2][L]);
        Sum += tree[node*2][L];
        cum[node].pb(Sum); L++;
    }
    while(R<right){
        tree[node].pb(tree[node*2+1][R]);
        Sum += tree[node*2+1][R];
        cum[node].pb(Sum); R++;
    }
    //cout<<node<<"\n";
    //for(int i=0; i<tree[node].size(); i++) cout<<tree[node][i]<<" "<<cum[node][i]<<"\n";
    //nl;
}

void build(int node, int b, int e){
    //PPP(node,b,e);
    if(b==e){
        tree[node].pb(v[b]);
        cum[node].pb(v[b]);
        return;
    }
    build(node*2,b,MID(b,e));
    build(node*2+1,MID(b,e)+1,e);
    myMerge(node);
}

int query(int node, int b, int e, int l, int r, int val){
    if(b>r || e<l || b>e){
        return 0;
    }
    if(b>=l && e<=r){
        int lb = lower_bound(all(tree[node]),val)-tree[node].begin();
        int ub = upper_bound(all(tree[node]),val)-tree[node].begin();
        //PP(lb,ub);
        int tot = lb*val;
        int aa = tot-cum[node][lb-1];
        int tot2 = (tree[node].size()-ub)*val;
        int bb = (cum[node][tree[node].size()-1]-cum[node][ub-1]) - tot2;
        //PP(aa,bb);
        return aa+bb;
    }
    int q1 = query(node*2,b,(b+(e-b)/2),l,r,val);
    int q2 = query(node*2+1,(b+(e-b)/2)+1,e,l,r,val);
    return q1+q2;
}
int32_t main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast();
    int tc=1;
    for(int T=1; T<=tc; T++){
        int n,k; cin>>n>>k;
        v.resize(n+1);
        for(int i=1; i<=n; i++){
            cin>>v[i];
        }
        build(1,1,n);
        for(int i=0; i<k; i++){
            int l,r,cap;
            cin>>l>>r>>cap;
            int ans = query(1,1,n,l,r,cap);
            cout<<ans<<"\n";
        }
    }
    return 0;

}

//--------------------******Alhamdulillah******-------------------//


