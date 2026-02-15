#include <stdio.h>
#include <iostream>
#include <random>
#include <fstream>
#define MAX(a, b) ((a > b) ? (a) : (b))
template <size_t N>
void dfs(int j, int *ans, int (&b)[N], int n, int ly, int d2)
{
    *ans = MAX(*ans, ly);
    std::cout << *ans << std::endl;
    for (size_t i = 1; i <= n - 1; i++)
    {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
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
    std::ofstream fs;
    fs.open("P15289.in");
    int N = 10;
    std::random_device rd;                      // 真随机种子
    std::mt19937 gen(rd());                     // Mersenne Twister 引擎
    std::uniform_int_distribution<> dist(2, N); // 区间 [1,100]

    int n = dist(gen);
    std::uniform_int_distribution<> dist1(1, n - 1); // 区间 [1,100]
    int a = dist1(gen);
    std::uniform_int_distribution<> dist2(1, (n - 1) / 2); // 区间 [1,100]
    int d = dist2(gen);
    int b[20];
    fs << n << " " << a << " " << d << std::endl;
    std::cout << n << " " << a << " " << d << std::endl;
    for (size_t i = 1; i <= n - 1; i++)
    {
        b[i] = dist(gen);
        fs << b[i] << " ";
        std::cout << b[i] << " ";
    }
    fs << std::endl;
    fs.close();
    std::cout << "sdlkf" << std::endl;
    int ans = 0;
    dfs(a, &ans, b, n, 0, 2 * d);
    return 0;
}
