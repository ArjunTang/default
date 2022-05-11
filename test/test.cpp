#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int a,b,aa,ba,temp;
    cin>>a>>b;
    if(a>b){
        temp=a;
        a=b;
        b=temp;
    }
    temp=1;
    while(pow(2,temp)>=a){
        temp++;
    }
    aa=temp;
    temp=1;
    while(pow(2,temp)>=b){
        temp++;
    }
    ba=temp;
    while(a!=b){
        while(aa!=ba){
            a=(a-pow(2,aa-1)+1)/2+1+pow(2,aa-2)-1;
            aa--;
        }
        a=(a-pow(2,aa-1)+1)/2+1+pow(2,aa-2)-1;
        aa--;
        b=(b-pow(2,ba-1)+1)/2+1+pow(2,ba-2)-1;
        ba--;
    }
    cout<<a<<endl;
    return 0;
}
