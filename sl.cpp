#include <bits/stdc++.h>
using namespace std;

int x[13], y[13];
int n;


 int calc(int p, int mask) {
     if(p==0){
         return (mask != 0)&&1e9 ;
     }
int  ret = 1e9;
    for (int i = 0; i <= n; ++i) {
        if (mask & (1 << i)) {
            int dist = abs(x[p] - x[i]) + abs(y[p] - y[i]);
            ret = min(ret, calc(i, mask ^ (1 << i)) + dist);
        }
    }
    return ret;
}


int main() {

    for (int i = 0; i < 3; ++i) {
        scanf("%d", &n);
        scanf("%d %d", &x[n + 1], &y[n + 1]);
        scanf("%d %d", &x[0], &y[0]);
        for (int j = 1; j <= n; ++j) {
            scanf("%d %d", &x[j], &y[j]);
        }
        printf("#%d %d\n", i + 1, calc(n + 1, (1 << (n + 1)) - 1));
    }
    return 0;
}