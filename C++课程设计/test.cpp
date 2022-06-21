#include <iostream>
#include <random>
using namespace std;
// 基类
class Player {
protected:
    int hp,atk,def; // 定义生命值、攻击力、防御力
public:
    Player(int hp,int atk,int def):hp(hp),atk(atk),def(def) {} // 初始化的时候，传入生命值、攻击力、防御力
    void reduceHP(int damage) { hp -= damage; } // 减少生命值
    virtual void attack(Player &p) { p.reduceHP(atk); } // 攻击
    virtual void defend(Player &p) { p.reduceHP(def); } // 防御
    int getATK() { return atk; } // 获取攻击力
    int getDEF() { return def; } // 获取防御力
    int getHP() {
        // 获取生命值
        if(hp<0)
            hp=0;
        return hp;
    }
    bool isAlive() {
        // 判断是否存活
        if(hp>0)
            return true;
        else
            return false;
    }
};
// 派生类-猫类
class Cat : public Player {
public:
    Cat():Player(100,15,20) {} // 初始化猫的生命值、攻击力、防御力
    void attack(Player &p) {
        // 攻击时,20%的概率连击
        p.reduceHP(atk);
        random_device rd;
        if(rd()%5==0) {
            p.reduceHP(atk);
            cout<<"玩家触发被动"<<endl;
        }
    }
};
// 派生类-狗类
class Dog : public Player {
public:
    Dog():Player(100,20,10) {} // 初始化狗的生命值、攻击力、防御力
    void defend(Player &p) {
        // 防御时,20%的概率恢复自身30点血量
        p.reduceHP(def);
        random_device rd;
        if(rd()%5==0) {
            p.reduceHP(-30);
            cout<<"玩家触发被动"<<endl;
        }
    }
};
int main() {
    bool mode; // 定义bool类型变量，储存每次的选择
    int turn=0; // 定义int类型变量，储存回合数
    Cat cat;
    Dog dog;
    Player *p1=&cat,*p2=&dog; // 定义指针，指向猫和狗，默认第一个玩家为猫角色，第二个玩家为狗角色
    cout<<"欢迎来到猫狗大战!"<<endl;
    cout<<"\t请选择游戏角色:"<<endl;
    cout<<"\t0\t玩家1-猫,玩家2-狗"<<endl;
    cout<<"\t1\t玩家1-狗,玩家2-猫"<<endl;
    cout<<"\t请输入您的选择:";
    cin>>mode;
    if(mode){ // 如果选择1，则交换指针指向的类
        p1=&dog;
        p2=&cat;
    }
    cout<<"游戏开始!"<<endl;
    cout<<"玩家1:血量"<<p1->getHP()<<",攻击力"<<p1->getATK()<<",防御力"<<p1->getDEF()<<endl;
    cout<<"玩家2:血量"<<p2->getHP()<<",攻击力"<<p2->getATK()<<",防御力"<<p2->getDEF()<<endl;
    cout<<"每回合请选择要进行的操作,0.防御,1.攻击:"<<endl;
    while(p1->isAlive()&&p2->isAlive()){ // 当玩家1和玩家2都存活时，游戏继续
        turn++;
        cout<<"\t第"<<turn<<"回合:"<<endl;
        cout<<"\t玩家1:";
        cin>>mode;
        if(mode)
            p1->attack(*p2);
        else
            p1->defend(*p2);
        cout<<"\t玩家2:";
        cin>>mode;
        if(mode)
            p2->attack(*p1);
        else
            p2->defend(*p1);
        cout<<"玩家1血量:"<<p1->getHP()<<endl;
        cout<<"玩家2血量:"<<p2->getHP()<<endl;
    }
    if(p1->isAlive()&&!p2->isAlive())
        cout<<"玩家1获胜!"<<endl;
    else if(!p1->isAlive()&&p2->isAlive())
        cout<<"玩家2获胜!"<<endl;
    else
        cout<<"平局!"<<endl;
    return 0;
}
