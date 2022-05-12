#include<iostream>
#include<cmath>
using namespace std;

template<typename T>
void f(){
    if(is_same<T,int>::value)
        cout<<"int"<<endl;
    else if(is_same<T,double>::value)
        cout<<"double"<<endl;
}
int main(){
    f<int>();
}
