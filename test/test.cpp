#include<iostream>
#include<fstream>
using namespace std;

int main(){
    char c;
    ifstream fin("a.jpg",ios::in | ios::binary);
    ofstream fout("b.jpg",ios::out | ios::binary);
    if(!fin){
        cout<<"open file error"<<endl;
        exit(1);
    }
    while(fin.get(c)){
        fout.put(c);
    }
    fin.close();
    fout.close();
    return 0;
}