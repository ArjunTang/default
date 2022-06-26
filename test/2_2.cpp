#include<stdio.h>
#include<iostream>
using namespace std;
#define max(x,y) ((x)>(y)?(x):(y))
#define MAXN 30		//最多物品数
#define MAXW 100	//最大限制重量
//问题表示
int n, W;	//n个数，W容量
int w[MAXN], v[MAXN];	//物品重量和价值
//求解结果表示
int dp[MAXN][MAXW];
int x[MAXN];
int bestp;		//存放最优解的总价值
//用动态规划法求0/1背包问题
void Knap()
{
    
	int i, r;
	for (i = 0; i <= n; i++)	//置边界条件dp[i][0] = 0
		dp[i][0] = 0;
	for (r = 0; r <= W; r++)	//置边界条件dp[0][r] = 0
		dp[0][r] = 0;
	for (i = 1; i <= n; i++) {
    
		for (r = 1; r <= W; r++) {
    
			if (r < w[i])
				dp[i][r] = dp[i - 1][r];
			else
				dp[i][r] = max(dp[i - 1][r], dp[i - 1][r - w[i]] + v[i]);
		}
	}
}
void Buildx()		//回推求最优解
{
    
	int i = n, r = W;
	bestp = 0;
	while (i >= 0) {
    
		if (dp[i][r] != dp[i - 1][r]) {
    
			x[i] = 1;
			bestp += v[i];
			r = r - w[i];
		}
		else
			x[i] = 0;
		i--;
	}
}
int main() {
    
	cout << "输入物品个数n:"; cin >> n;
	cout << "输入最大容量W:"; cin >> W;
	cout << "依次输入每个物品的重量w和价值v，用空格分开：";
	for (int i = 1; i <= n; i++) {
    
		cin >> w[i] >> v[i];
	}
	Knap();
	Buildx();
	printf("最优方案\n");
	printf("选取物品为：");
	for (int i = 1; i <= n; i++)
		if (x[i] == 1)
			printf("%d ", i);
	printf("\n");
	printf("总价值=%d\n", bestp);
	return 0;
}