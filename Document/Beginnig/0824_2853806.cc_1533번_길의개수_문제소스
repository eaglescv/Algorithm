#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<vector<long long>> matrix;
const long long mod = 1000003;
matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= mod;
        }
    }
    return c;
}
int main() {
    int n, s, e, t;
    scanf("%d %d %d %d",&n,&s,&e,&t);
    matrix ans(n*5, vector<long long>(n*5));
    for (int i=0; i<n*5; i++) {
        ans[i][i] = 1;
    }
    matrix a(n*5, vector<long long>(n*5));
    for (int i=0; i<n; i++) {
        for (int j=0; j<4; j++) {
            a[5*i+j][5*i+j+1] = 1;
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int v;
            scanf("%1d",&v);
            if (v > 0) {
                a[5*i+v-1][5*j] = 1;
            }
        }
    }
    while (t > 0) {
        if (t & 1) {
            ans = ans * a;
        }
        a = a * a;
        t >>= 1;
    }
    s -= 1;
    e -= 1;
    printf("%lld\n",ans[5*s][5*e]);
    return 0;
}
