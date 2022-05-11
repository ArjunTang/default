#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int a[10]={0},size=0;
    a[++size]=1;
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
