///**Bismillahir Rahmanir Rahim.**

#include <bits/stdc++.h>
#define clr(a, v)             memset(a, v, sizeof a)
#define all(v)                v.begin(), v.end()
#define ast(v)                sort(v.begin(),v.end())
#define dst(v)                sort(v.begin(),v.end(), greater <int> ())
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ass(tmp, v)           tmp.assign(v.begin(), v.end())
#define mid(b, e)             (b+e)/2
#define left(node)            node*2
#define right(node)           node*2+1
#define rep(i, l, r)          for (int i = l; i < r; i++)
#define rep2(i, l, r)         for (int i = l-1; i >= r; i--)
#define sf(n)                 scanf("%d", &n)
#define sff(n, m)             scanf("%d %d",&n,&m)
#define sfl(n)                scanf("%lld", &n)
#define sfu(n)                scanf("%llu", &n)
#define sffl(n, m)            scanf("%lld %lld",&n,&m)
#define sfff(n, m, o)         scanf("%d %d %d",&n,&m, &o)
#define pf(n)                 printf("%d", n)
#define sp                    printf(" ")
#define nl                    printf("\n")
#define prln(n)               printf("%d\n", n)
#define pfl(n)                printf("%lld", n)
#define pfu(n)                printf("%llu", n)
#define pb                    push_back
#define pii                   pair<int,int>
#define mp                    make_pair
#define S                     second
#define F                     first
#define PI                    3.1415926

struct greaters
{
    bool operator()(const long& a, const long& b) const
    {
        return a > b;
    }
};

//-----------------------------------***********************----------------------------------------------//

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
const int N = 200050;
const int mod = 1e9+7;

int segment[N][2], point[N];
int main(){
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //fast;
    int tc, cas = 0;
    sf(tc);
    while(tc--){
      int n, q;
      sff(n, q);

      rep(i, 0, n) sff(segment[i][0], segment[i][1]);
      rep(i, 0, q) sf(point[i]);

      printf("Case %d:\n", ++cas);
      rep(i, 0, q){
        int ans = 0;
        rep(j, 0, n){
          if(segment[j][0] <= point[i] and segment[j][1] >= point[i]) ans++;
        }
        prln(ans);
      }

        ///printf("Case %d: %lld\n", ++cas, ans);
    }
    return 0;

}

//-----------------------------------***********************----------------------------------------------//
