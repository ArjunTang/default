#include<iostream>
using namespace std;
void swap(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
void QuickSort(int a[],int s,int e){
    if(s>=e){
        return;
    }
    int i = s,j = e;
    int pivot = a[(s+e)/2];
    while(i<=j){
        while(a[i]<pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    QuickSort(a,s,j);
    QuickSort(a,i,e);
}
int main(){
    int a[10] = {24,3,15,7,9,31,2,49,6,8};
    int size = sizeof(a)/sizeof(a[0]);
    QuickSort(a,0,size-1);
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}