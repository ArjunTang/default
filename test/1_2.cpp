#include <iostream>
using namespace std;
//取得划分点
int getPivot(int a[], int left, int right)
{
    int pivot;
    if (left < right)
    {
        int low = left, high = right, key = a[left];
        while (low < high)
        {
            while (a[high] >= key && low < high)
            {
                high--;
            }
            a[low] = a[high];
            while (a[low] <= a[high] && low < high)
            {
                low++;
            }
            a[high] = a[low];
        }
        pivot = low;
        a[pivot] = key;
    }
    return pivot;
}

//随机快排
void randomizedQuickSort(int a[], int left, int right)
{
    if (left < right)
    {
        //输入随机数种子
        srand(unsigned(time(NULL)));
        //生成left到right的的随机数
        int randNum = rand() % (right - left + 1) + left;
        //在left到right随机找一个数据作为基准点
        swap(a[left], a[randNum]);
        //取得划分点
        int pivot = getPivot(a, left, right);
        randomizedQuickSort(a, left, pivot - 1);
        randomizedQuickSort(a, pivot + 1, right);
    }
}

int main()
{
    int a[10] = {24, 3, 15, 7, 9, 31, 2, 49, 6, 8};
    int size = sizeof(a) / sizeof(a[0]);
    randomizedQuickSort(a, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
