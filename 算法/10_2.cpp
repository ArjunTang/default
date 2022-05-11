#include<iostream>
#include<cstring>
using namespace std;

char Left[3][7];
char Right[3][7];
char result[3][7];
bool isFake(char c,bool light);

int main(){
    for(int i=0;i<3;i++) cin>>Left[i]>>Right[i]>>result[i];
    for(char c='A';c<='Z';c++){
        if(isFake(c,true)){
            cout<<c<<" is fake and it is light."<<endl;
            break;
        }
        else if(isFake(c,false)){
            cout<<c<<" is fake and it is heavy."<<endl;
            break;
        }
    }
    return 0;
}

bool isFake(char c,bool light){
    for(int i=0;i<3;i++){
        char* pLeft,*pRight;
        if(light) pLeft=Left[i],pRight=Right[i];
        else pLeft=Right[i],pRight=Left[i];
        switch (result[i][0]){
            case 'E':
                if(strchr(pLeft,c)||strchr(pRight,c)) return false;
                break;
            case 'U':
                if(strchr(pRight,c)==NULL) return false;
                break;
            case 'D':
                if(strchr(pLeft,c)==NULL) return false;
                break;
        }
    }
    return true;
}