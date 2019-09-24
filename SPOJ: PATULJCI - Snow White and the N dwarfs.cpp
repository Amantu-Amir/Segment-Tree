#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

const int N = 300005;
const int M = 2222;

int a[N];
vector <int> G[N];

int main()
{
    srand(time(0));

    int n, c;
    scanf("%d %d", &n, &c);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        G[a[i]].push_back(i);
    }

    int q;
    scanf("%d", &q);
    while(q--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        x--;
        y--;

        int diff = (y - x + 1);
        int it = 25, flag = 0;

        while(it--)
        {
            int rpos = a[x+rand()%diff];
            int cnt = upper_bound(all(G[rpos]), y) - lower_bound(all(G[rpos]), x);
            if(cnt > diff / 2)
            {
                flag = rpos;
                break;
            }
        }
        if(flag) printf("yes %d\n", flag);
        else puts("no");
    }
    return 0;
}
