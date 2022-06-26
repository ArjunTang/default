#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXN 51
int n;
int W;
struct NodeType
{

    int w;
    int v;
    int p; //性价比p=v/w
    bool operator<(const NodeType &s) const
    {

        return p > s.p;
    }
};
NodeType A[MAXN];
int maxv;
int x[MAXN];
void Knap() //求解背包问题并返回总价值
{

    maxv = 0;                // maxv初始化为0
    int weight = W;          //背包中能装入的余下重量
    memset(x, 0, sizeof(x)); //初始化x向量
    int i = 1;
    while (A[i].w <= weight) //物品i能够全部装入背包时，循环
    {

        x[i] = 1;         //装入物品i
        weight -= A[i].w; //减少背包中能装入的余下重量
        maxv += A[i].v;   //计算装入物品i后的总价值
        i++;
    }
}
void disp_bestx()
{

    int sumw = 0;
    cout << "放入购物车的物品序号为：";
    for (int j = 1; j <= n; j++)
    {

        if (x[j] == 1)
        {

            cout << j << " ";
            sumw += A[j].w;
        }
    }
    cout << endl;
    cout << "放入购物车的物品最大价值为：" << maxv << "，总重量为：" << sumw << endl;
}
int main()
{

    cout << "输入物品个数n:";
    cin >> n;
    cout << "输入购物车容量W:";
    cin >> W;
    cout << "依次输入每个物品的重量w和价值v，用空格分开：" << endl;
    ;
    for (int i = 1; i <= n; i++)
    {

        cin >> A[i].w >> A[i].v;
    }
    for (int i = 1; i <= n; i++)
    {

        A[i].p = A[i].v / A[i].w;
    }
    sort(A + 1, A + 1 + n);
    Knap();
    disp_bestx();
    return 0;
}