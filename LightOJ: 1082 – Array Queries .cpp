/**Bismillahir Rahmanir Rahim.**/
#include <bits/stdc++.h>
#define mem(a, v)           memset(a, v, sizeof a)
#define ast(v)              sort(v.begin(),v.end())
#define dst(v)              sort(v.begin(),v.end(), greater <int> ())
#define ass(tmp, v)         tmp.assign(v.begin(), v.end())
#define rep(i, l, r)        for (int i = (l); i <= (r); ++i)
#define sf(n)               scanf("%d", &n)
#define sff(n, m)           scanf("%d %d",&n,&m)
#define sfl(n)              scanf("%lld", &n)
#define sfu(n)              scanf("%llu", &n)
#define sffl(n, m)          scanf("%lld %lld",&n,&m)

#define pf(n)               printf("%d", n)
#define sp                  printf(" ")
#define nl                  printf("\n")
#define prln(n)             printf("%d\n", n)
#define pfl(n)              printf("%lld", n)
#define pfu(n)              printf("%llu", n)
#define pb                  push_back
#define pp                  pair<ll,ll>
#define mp                  make_pair
#define mod                 1e9+7
#define T                   true
#define F                   false
#define S                   second
#define f                   first
#define PI                  3.1415926

//-----------------------------------***********************----------------------------------------------//

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
const int N = 100050;


int v[N];
int tree[N*4];


int init(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = v[b];
        return v[b];
    }

    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)/2;

    int x = init(left, b, mid);
    int y = init(right, mid+1, e);
    tree[node] = min(x, y);
    return tree[node];
}


int query(int node, int b, int e, int l, int r)
{
    if(l > e or r < b)
        return INT_MAX;

    if(b >= l and e <= r)
        return tree[node];

    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)/2;

    int p1 = query(left, b, mid, l, r);
    int p2 = query(right, mid+1, e, l, r);

    return min(p1, p2);
}



int main()
{

//freopen("test.txt", "r", stdin);

    int tcase, cas = 1;
    sf(tcase);
    while(tcase--)
    {
        int n, q;
        sff(n, q);

        rep(i, 1, n)
        sf(v[i]);

        init(1, 1, n);

        printf("Case %d:\n", cas);
        rep(i, 1, q)
        {
            int l, r;
            sff(l, r);
           printf("%d\n", query(1, 1, n, l, r));
        }



        //cout << "Case " << cas << ": " << ans << endl;
        cas++;
    }
    return 0;

}

//-----------------------------------***********************----------------------------------------------//






///sorting
/*bool des(pair<string,ll> a, pair<string, ll> b)
{
    if(a.second!= b.second) return a.second > b.second;    /// kom theke beshi sort ///return p.first > q.first; /// beshi theke kom sort
    else return a.first < b.first;
}

*/
///sieve
/*
vector<int>prime;
bool isPrime[N+50];
int sieve()
{
    prime.push_back(2);
    for(int i=3; i<100; i+=2)
    {
        if(isPrime[i] == 0)
        {
            prime.push_back(i);
            for(int j = i*i; j<N; j += (i*2))
                isPrime[j]=1;
        }
    }
}
*/
///check prime
/*
boolean isPrime( int n ) {
    if ( n == 1 ) return false; // by definition, 1 is not prime number
    if ( n == 2 ) return true; // the only one even prime
    if ( n%2 == 0 ) return false; // check if is even
    for ( int i = 3; i * i <= n; i += 2 ) // for each odd number
        if ( n%i == 0 ) return false;
    return true;
}
*/
///prime factor
/*
void primeFactorization(int n)
{
    int tmp = sqrt(n), pos = 0;
    for(int i = 0; prime[i] <= tmp; i++)
    {
        if(n%prime[i] == 0)
        {
            while(n%prime[i] == 0)
            {
                n /= prime[i];
                primeFactor[pos++] = prime[i];
            }
        }
    }

    if(n > 1)
        primeFactor[pos++] = n;

    for(int i = 0; i < pos; i++)
        cout << primeFactor[i] << " ";
    nl;
}
*/

