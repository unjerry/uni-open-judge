#include <stdio.h>
#include <math.h>
#define MAX(a, b) ((a > b) ? (a) : (b))
int main()
{
    freopen("P15289.in", "r", stdin);

    long long n, a, d;
    scanf("%lld%lld%lld", &n, &a, &d);
    // printf("%d %d %d\n", n, a, d);
    long long b[n];
    long long p[n];
    for (long long i = 1; i <= n - 1; i++)
    {
        scanf("%lld", &(b[i]));
        p[i] = MAX((b[i] - 2) / (2 * d), 0);
        // printf("%d ", p[i]);
    }
    // printf("\n");
    long long ans = 0;
    {
        long long cnt = 0;
        long long j = a;
        while (true)
        {
            if (j + 0 == n - 1)
            {
                break;
            }
            else if (j + 1 == n - 1)
            {
                if (p[j + 1] > 0)
                {
                    j += 1;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (p[j + 1] > 0)
                {
                    j += 1;
                }
                else if (p[j + 2] >= 2 && p[j] >= 2)
                {
                    j += 2;
                }
                else
                {
                    break;
                }
            }
        }
        cnt = p[j];
        while (true)
        {
            if (j - 0 == 1)
            {
                break;
            }
            else if (j - 1 == 1)
            {
                if (p[j - 1] > 0)
                {
                    j -= 1;
                    cnt += p[j];
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (p[j - 1] > 0)
                {
                    j -= 1;
                    cnt += p[j];
                }
                else if (p[j - 2] > 0)
                {
                    j -= 2;
                    cnt += p[j];
                }
                else
                {
                    break;
                }
            }
        }
        // printf("%d\n\n", cnt);
        ans = MAX(ans, cnt);
    }
    {
        long long cnt = 0;
        long long j = a;
        while (true)
        {
            if (j - 0 == 1)
            {
                break;
            }
            else if (j - 1 == 1)
            {
                if (p[j - 1] > 0)
                {
                    j -= 1;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (p[j - 1] > 0)
                {
                    j -= 1;
                }
                else if (p[j - 2] >= 2 && p[j] >= 2)
                {
                    j -= 2;
                }
                else
                {
                    break;
                }
            }
        }
        cnt = p[j];
        while (true)
        {
            if (j + 0 == n - 1)
            {
                break;
            }
            else if (j + 1 == n - 1)
            {
                if (p[j + 1] > 0)
                {
                    j += 1;
                    cnt += p[j];
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (p[j + 1] > 0)
                {
                    j += 1;
                    cnt += p[j];
                }
                else if (p[j + 2] > 0)
                {
                    j += 2;
                    cnt += p[j];
                }
                else
                {
                    break;
                }
            }
        }
        // printf("%d\n\n", cnt);
        ans = MAX(ans, cnt);
    }
    printf("%lld\n", ans);

    fclose(stdin);
    return 0;
}