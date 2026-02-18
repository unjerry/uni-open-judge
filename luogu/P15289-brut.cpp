#include <stdio.h>
#include <iostream>
#include <random>
#include <fstream>
#define MAX(a, b) ((a > b) ? (a) : (b))
template <size_t N>
void dfs(ssize_t j, ssize_t *ans, ssize_t (&b)[N], ssize_t n, ssize_t ly, ssize_t d2)
{
    *ans = MAX(*ans, ly);
    // std::cout << *ans << std::endl;
    for (size_t i = 1; i <= n - 1; i++)
    {
        // std::cout << b[i] << " ";
    }
    // std::cout << std::endl;
    for (ssize_t i = -2; i <= +2; i++)
    {
        if (i + j < 1 || i + j > n - 1)
        {
            continue;
        }
        if (b[j + i] >= d2 + 2)
        {
            b[j + i] -= d2;
            dfs(j + i, ans, b, n, ly + 1, d2);
            b[j + i] += d2;
        }
    }
}
int main()
{
    freopen("P15289.in", "r", stdin);

    ssize_t n, a, d;
    scanf("%lld%lld%lld", &n, &a, &d);
    // printf("%d %d %d\n", n, a, d);
    ssize_t b[1000005];
    ssize_t p[1000005];
    for (size_t i = 1; i <= n - 1; i++)
    {
        scanf("%lld", &(b[i]));
        p[i] = MAX((b[i] - 2) / (2 * d), 0);
        // printf("%d ", p[i]);
    }
    // printf("\n");
    fclose(stdin);

    ssize_t ans = 0;
    dfs((ssize_t)a, &ans, b, (ssize_t)n, (ssize_t)0, (ssize_t)(2 * d));
    printf("%lld\n", ans);
    return 0;
}
