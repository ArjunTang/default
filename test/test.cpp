<<<<<<< HEAD
=======
#include<iostream>
using namespace std;

class A{
public:
    int i;
    A(){i=-1;next=nullptr;}
    A* next;
    void add(int i){
        A* p=this;
        while(p->next!=nullptr)p=p->next;
        p->next=new A();
        p->next->i=i;
    }
    void print(){
        A* p=this;
        while(p!=nullptr){
            cout<<p->i<<" ";
            p=p->next;
        }
        cout<<endl;
    }
};

int main(){
    
    A a;
    a.add(1);
    a.add(2);
    a.add(3);
    a.print();
    
    return 0;
}
>>>>>>> 6aa216878050ae43bcc21191292c6e4e65f4222f
