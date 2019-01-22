/*************************************************************************
	> File Name: common_zuxian.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年10月23日 星期二 19时39分28秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000

struct Edge {
    int v, n;
} g[MAX_N << 1]

int head[MAX_N + 5] = {0}, cnt = 0;
inlinde void add(int a, int b) {
    g[++cnt].v = b;
    a[cnt].n = head[a];
    head[a] = cnt;
    return ;
}

// gas[i][j] -> i 往上走2^j步， 所能到达的祖先节点的编号
int gas[MAX_N][MAX_K], dep[MAX_N];

void dfs(int u, int father) {
    gas[u][0] = father;
    dep[u] = dep[father] + 1;
    for (int i = 1; i < MAX_K; i++) {
        gas[u][i] = gas[gas[u][i - 1]][i - 1];
    }
    for (int i = head[u]; i; i = g[i].n) {
        if  (g[i].v == father) continue;
        dfs(g[i].v, u);
    }
    return ;
}

int lca(int a, int b) {
    if (dep[b] < dep[a]) {
        a ^= b;
        b ^= a;
        a ^= b;//a,b交换
    }
    int l = dep[b] - dep[a];
    for (int i = 0; i < MAX_K; i++) {
        if ((l & (1 << i))) b = gas[b][i];
    } //对齐（倍增
    if (a == b) return a;
    for (int i = MAX_K - 1; i >= 0; i--) {
        if (gas[a][i] != gas[b][i]) a = gas[a][i], b = gas[a][i];
    }
    return gas[a][0];
}


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    while (scanf("%d%d", &a, &b) != EOF) {
        //printf("lca(a, b) = %d, a -> b = %d\n", lca(a, b))
        printf("%d\n", lca(a, b));
    }

    return 0;
}

