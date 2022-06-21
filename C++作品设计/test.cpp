/*
题目一:公司员工工资管理系统
设计一个职工信息管理案例，实现不同类别职工的工资数据。职工的种类包括:正式职工和临时工。
定义一个基本的职工类，基本信息包括:编号、姓名、性别、年龄、家庭住址、职务、工龄、基本职务工资。
派生出正式职工类，增加的属性包括:岗位津贴、养老金、住房公积金、所得税、医疗保险、实发工资;
派生出临时工类，临时工增加的属性包括:奖金、所得税、实发工资。
    1、正式职工:实发工资=基本职务工资+岗位津贴+工龄*150-养老金-住房公积金-所得税-医疗保险-所得税;
    2、临时工:实发工资=基本职务工资+奖金-所得税;
基本功能与技术要求:
1、系统以菜单方式工作。
2、数据文件管理功能:利用输入输出流创建新文件、打开文件、保存文件。
3、计算与统计功能:采用静态数据成员与成员函数完成记录中相关数据的统计;
    (1)能够打开已存在的数据表文件，对数据表中与某关键字匹配的相关记录进行数据统计(包括:工资总额、平均值)
    (2)计算每个职工的实发工资。
4、记录管理功能:利用继承与派生思想创建不同的类;记录的管理采用链表或者指针数组 实现;采用抽象类、虚函数等实现对象与函数的动态关联，体现多态性。
    (1)输入/添加/插入记录:利用重载运算符“>>”完成对任意一条记录输入、添加或 插入数据表中，并保存到数据文件中。
    (2)查询、显示记录:能够打开已存在的数据表文件，可以根据编号、名字、职务查询职工信息。利用重载运算符“<<”输出对象的信息。
    (3)修改记录:能够打开已存在的数据表文件，并对确定的任意记录进行修改，在修改过程中，应显示记录信息，给出确认提示，并对更新的记录信息进行文件保存。
    (4)删除记录:能够打开已存在的数据表文件，可以删除数据表中的任一记录，要求具备逻辑删除(具有恢复功能)和物理删除功能，并对新的数据表信息进行文件保存。
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//基本职工类
class BaseEmployee {
protected:
    int id; //编号
    string name; //姓名
    bool sex; //性别
    int age; //年龄
    string address; //家庭住址
    bool job; //职务
    int workage; //工龄
    float basicwage; //基本工资
public:
    BaseEmployee(){};
    ~BaseEmployee(){};
    int getId() { return id; } //获取编号
    string getName() { return name; } //获取姓名
    void setJob(bool job) { this->job = job; } //设置职务
};

//正式职工类
class RegularEmployee:public BaseEmployee
{
private:
    float postwage; //岗位津贴
    float pension; //养老金
    float housingFund; //住房公积金
    float incomeTax; //所得税
    float medicalInsurance; //医疗保险
    float realPay; //实发工资
public:
    RegularEmployee* next= nullptr; //指针域
    RegularEmployee() {};
    ~RegularEmployee() {};
    friend istream& operator>>(istream&,RegularEmployee&); //重载输入运算符
    friend ostream& operator<<(ostream&,RegularEmployee&); //重载输出运算符
    void setRealPay(); //设置实发工资
    void addEmployee(); //添加员工函数
    void searchEmployee(int flag,int id,string name); //查找员工函数
    void showEmployee(); //显示员工信息
    void modifyEmployee(int id); //修改员工函数
    void deleteEmployee(int id); //删除员工函数
    void readFile(); //读取文件
    void writeFile(); //写入文件
};
istream& operator>>(istream& is,RegularEmployee& e) //重载输入运算符
{
    cout<<"******************************"<<endl;
    cout<<"输入信息:"<<endl;
    cout<<"\t编号:";
    cin>>e.id;
    cout<<"\t姓名:";
    cin>>e.name;
    cout<<"\t性别(0.female 1.male):";
    cin>>e.sex;
    cout<<"\t年龄:";
    cin>>e.age;
    cout<<"\t家庭住址:";
    cin>>e.address;
    cout<<"\t工龄:";
    cin>>e.workage;
    cout<<"\t基本工资:";
    cin>>e.basicwage;
    cout<<"\t岗位津贴:";
    cin>>e.postwage;
    cout<<"\t养老金:";
    cin>>e.pension;
    cout<<"\t住房公积金:";
    cin>>e.housingFund;
    cout<<"\t所得税:";
    cin>>e.incomeTax;
    cout<<"\t医疗保险:";
    cin>>e.medicalInsurance;
    cout<<"******************************"<<endl;
    return is;
}
ostream& operator<<(ostream& os,RegularEmployee& e) //重载输出运算符
{
    cout<<"******************************"<<endl;
    cout<<"编号:"<<e.id<<endl;
    cout<<"姓名:"<<e.name<<endl;
    cout<<"性别(0.female 1.male):"<<e.sex<<endl;
    cout<<"年龄:"<<e.age<<endl;
    cout<<"家庭住址:"<<e.address<<endl;
    cout<<"职务(0.正式工 1.临时工):"<<e.job<<endl;
    cout<<"工龄:"<<e.workage<<endl;
    cout<<"基本工资:"<<e.basicwage<<endl;
    cout<<"岗位津贴:"<<e.postwage<<endl;
    cout<<"养老金:"<<e.pension<<endl;
    cout<<"住房公积金:"<<e.housingFund<<endl;
    cout<<"所得税:"<<e.incomeTax<<endl;
    cout<<"医疗保险:"<<e.medicalInsurance<<endl;
    cout<<"实发工资:"<<e.realPay<<endl;
    cout<<"******************************"<<endl;
    return os;
}
void RegularEmployee::setRealPay() //设置实发工资
{
    realPay = basicwage + postwage + workage * 150 - pension - housingFund - incomeTax - medicalInsurance - incomeTax;
}
void RegularEmployee::addEmployee() //添加员工函数
{
    RegularEmployee* p=this;
    while(p->next!=nullptr)
        p=p->next;
    RegularEmployee temp;
    cin>>temp;
    temp.setRealPay();
    temp.setJob(0);
    p->next=new RegularEmployee(temp);
    cout<<"添加成功"<<endl;
}
void RegularEmployee::searchEmployee(int flag,int id,string name) //删除员工函数
{
    RegularEmployee* p=this;
    if(flag==1) //按照编号查询
    {
        while(p->next!=nullptr)
        {
            if(p->next->getId()==id)
            {
                cout<<*p->next;
                return;
            }
            p = p->next;
        }
    }
    else if(flag==2) //按照姓名查询
    {
        while(p->next!=nullptr)
        {
            if(p->next->getName()==name)
            {
                cout<<*p->next;
                return;
            }
            p = p->next;
        }
    }
    cout<<"没有此员工"<<endl;
}
void RegularEmployee::modifyEmployee(int id) {
    RegularEmployee *p=this,*q;
    while(p->next!=nullptr)
    {
        if(p->next->getId()==id)
        {
            q=p->next;
            RegularEmployee temp;
            cin>>temp;
            temp.setRealPay();
            temp.setJob(0);
            p->next=new RegularEmployee(temp);
            p->next->next=q->next;
            cout<<"修改成功"<<endl;
            return;
        }
        p = p->next;
    }
    cout<<"没有此员工"<<endl;
}
void RegularEmployee::showEmployee() {
    RegularEmployee* p=this;
    while(p->next!=nullptr)
    {
        cout<<*p->next;
        p=p->next;
    }
}
void RegularEmployee::deleteEmployee(int id) {
    RegularEmployee *p=this;
    while(p->next!=nullptr)
    {
        if(p->next->getId()==id)
        {
            p->next=p->next->next;
            cout<<"删除成功"<<endl;
            return;
        }
        p = p->next;
    }
    cout<<"没有此员工"<<endl;
}
void RegularEmployee::readFile() {
    RegularEmployee* p=this;
    RegularEmployee temp;
    fstream file("RegularEmployee.txt",ios::in | ios::binary);
    if(!file)
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
    while(file.read((char*)&temp,sizeof(temp)))
    {
        temp.setRealPay();
        temp.setJob(0);
        p->next=new RegularEmployee(temp);
        p=p->next;
    }
    file.close();
}
void RegularEmployee::writeFile() {
    RegularEmployee* p=this;
    fstream file("RegularEmployee.txt",ios::out | ios::binary);
    if(!file)
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
    while(p->next!=nullptr)
    {
        file.write((char*)p->next,sizeof(*p->next));
        p=p->next;
    }
    file.close();
}

//临时职工类
class TemporaryEmployee:public BaseEmployee
{
private:
    float bonus; //奖金
    float incomeTax; //所得税
    float realPay; //实发工资
public:
    TemporaryEmployee* next= nullptr; //指针域
    TemporaryEmployee(){};
    friend istream& operator>>(istream&,TemporaryEmployee&); //重载输入运算符
    friend ostream& operator<<(ostream&,TemporaryEmployee&); //重载输出运算符
    void setRealPay(); //设置实发工资
    void addEmployee(); //添加员工函数
    void searchEmployee(int flag,int id,string name); //查找员工函数
    void showEmployee(); //显示员工信息
    void modifyEmployee(int id); //修改员工函数
    void deleteEmployee(int id); //删除员工函数
    void readFile(); //读取文件
    void writeFile(); //写入文件
};
istream& operator>>(istream& is,TemporaryEmployee& e) //重载输入运算符
{
    cout<<"******************************"<<endl;
    cout<<"输入信息:"<<endl;
    cout<<"\t编号:";
    cin>>e.id;
    cout<<"\t姓名:";
    cin>>e.name;
    cout<<"\t性别(0.female 1.male):";
    cin>>e.sex;
    cout<<"\t年龄:";
    cin>>e.age;
    cout<<"\t家庭住址:";
    cin>>e.address;
    cout<<"\t工龄:";
    cin>>e.workage;
    cout<<"\t基本工资:";
    cin>>e.basicwage;
    cout<<"\t奖金:";
    cin>>e.bonus;
    cout<<"\t所得税:";
    cin>>e.incomeTax;
    cout<<"******************************"<<endl;
    return is;
}
ostream& operator<<(ostream& os,TemporaryEmployee& e) //重载输出运算符
{
    cout<<"******************************"<<endl;
    cout<<"编号:"<<e.id<<endl;
    cout<<"姓名:"<<e.name<<endl;
    cout<<"性别(0.female 1.male):"<<e.sex<<endl;
    cout<<"年龄:"<<e.age<<endl;
    cout<<"家庭住址:"<<e.address<<endl;
    cout<<"职务(0.正式工 1.临时工):"<<e.job<<endl;
    cout<<"工龄:"<<e.workage<<endl;
    cout<<"基本工资:"<<e.basicwage<<endl;
    cout<<"奖金:"<<e.bonus<<endl;
    cout<<"所得税:"<<e.incomeTax<<endl;
    cout<<"实发工资:"<<e.realPay<<endl;
    cout<<"******************************"<<endl;
    return os;
}
void TemporaryEmployee::setRealPay() //设置实发工资
{
    realPay = basicwage + bonus - incomeTax;
}
void TemporaryEmployee::addEmployee() {
    TemporaryEmployee* p=this;
    while(p->next!=nullptr)
        p=p->next;
    TemporaryEmployee temp;
    cin>>temp;
    temp.setRealPay();
    temp.setJob(1);
    p->next=new TemporaryEmployee(temp);
    cout<<"添加成功"<<endl;
}
void TemporaryEmployee::searchEmployee(int flag,int id,string name) //删除员工函数
{
    TemporaryEmployee* p=this;
    if(flag==1) //按照编号查询
    {
        while(p->next!=nullptr)
        {
            if(p->next->getId()==id)
            {
                cout<<*p->next;
                return;
            }
            p = p->next;
        }
    }
    else if(flag==2) //按照姓名查询
    {
        while(p->next!=nullptr)
        {
            if(p->next->getName()==name)
            {
                cout<<*p->next;
                return;
            }
            p = p->next;
        }
    }
    cout<<"没有此员工"<<endl;
}
void TemporaryEmployee::modifyEmployee(int id) {
    TemporaryEmployee *p=this,*q;
    while(p->next!=nullptr)
    {
        if(p->next->getId()==id)
        {
            q=p->next;
            TemporaryEmployee temp;
            cin>>temp;
            temp.setRealPay();
            temp.setJob(1);
            p->next=new TemporaryEmployee(temp);
            p->next->next=q->next;
            cout<<"修改成功"<<endl;
            return;
        }
        p = p->next;
    }
    cout<<"没有此员工"<<endl;
}
void TemporaryEmployee::showEmployee() {
    TemporaryEmployee* p=this;
    while(p->next!=nullptr)
    {
        cout<<*p->next;
        p=p->next;
    }
}
void TemporaryEmployee::deleteEmployee(int id) {
    TemporaryEmployee *p=this;
    while(p->next!=nullptr)
    {
        if(p->next->getId()==id)
        {
            p->next=p->next->next;
            cout<<"删除成功"<<endl;
            return;
        }
        p = p->next;
    }
    cout<<"没有此员工"<<endl;
}
void TemporaryEmployee::readFile() {
    TemporaryEmployee* p=this;
    TemporaryEmployee temp;
    fstream file("TemporaryEmployee.txt",ios::in | ios::binary);
    if(!file)
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
    while(file.read((char*)&temp,sizeof(temp)))
    {
        temp.setRealPay();
        temp.setJob(1);
        p->next=new TemporaryEmployee(temp);
        p=p->next;
    }
    file.close();
}
void TemporaryEmployee::writeFile() {
    TemporaryEmployee* p=this;
    fstream file("TemporaryEmployee.txt",ios::out | ios::binary);
    if(!file)
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
    while(p->next!=nullptr)
    {
        file.write((char*)p->next,sizeof(*p->next));
        p=p->next;
    }
    file.close();
}
void menu1(RegularEmployee* reHead,TemporaryEmployee* teHead); //菜单1
void menu2(RegularEmployee* reHead,TemporaryEmployee* teHead); //菜单2

void menu(RegularEmployee* reHead,TemporaryEmployee* teHead) //菜单函数
{
    cout<<"欢迎使用员工管理系统!"<<endl;
    reHead->readFile(); //读取文件
    teHead->readFile(); //读取文件
    menu1(reHead,teHead);
    cout<<"感谢使用员工管理系统!"<<endl;
}
void menu1(RegularEmployee* reHead,TemporaryEmployee* teHead) //菜单函数1
{
    int temp1,temp2,temp3,id;
    string name;
    //主菜单
    cout<<"\t1.添加员工信息"<<endl;
    cout<<"\t2.查询员工信息"<<endl;
    cout<<"\t3.修改员工信息"<<endl;
    cout<<"\t4.删除员工信息"<<endl;
    cout<<"\t5.显示所有员工信息"<<endl;
    cout<<"\t请输入对应数字选择功能:";
    cin>>temp1;
    //子菜单
    switch (temp1)
    {
        case 1: //添加员工子菜单
            cout<<"\t\t1.添加正式员工"<<endl;
            cout<<"\t\t2.添加临时员工"<<endl;
            cout<<"\t\t请输入对应数字选择功能:";
            cin>>temp2;
            switch (temp2) {
                case 1:
                    reHead->addEmployee();
                    break;
                case 2:
                    teHead->addEmployee();
                    break;
                default:
                    cout<<"输入错误"<<endl;
                    break;
            }
            break;
        case 2: //查询员工子菜单
            cout<<"\t\t1.查询正式员工"<<endl;
            cout<<"\t\t2.查询临时员工"<<endl;
            cout<<"\t\t请输入对应数字选择功能:";
            cin>>temp2;
            cout<<"\t\t1.按编号查询"<<endl;
            cout<<"\t\t2.按姓名查询"<<endl;
            cout<<"\t\t请输入对应数字选择功能:";
            cin>>temp3;
            switch (temp2) {
                case 1:
                    switch (temp3) {
                        case 1:
                            cout<<"请输入要查询的员工编号:";
                            cin>>id;
                            reHead->searchEmployee(1,id,name);
                            break;
                        case 2:
                            cout<<"请输入要查询的员工姓名:";
                            cin>>name;
                            reHead->searchEmployee(2,id,name);
                            break;
                        default:
                            cout<<"输入错误"<<endl;
                            break;
                    }
                    break;
                case 2:
                    switch (temp3) {
                        case 1:
                            cout<<"请输入要查询的员工编号:";
                            cin>>id;
                            teHead->searchEmployee(1,id,name);
                            break;
                        case 2:
                            cout<<"请输入要查询的员工姓名:";
                            cin>>name;
                            teHead->searchEmployee(2,id,name);
                            break;
                        default:
                            cout<<"输入错误"<<endl;
                            break;
                    }
                    break;
                default:
                    cout<<"输入错误"<<endl;
                    break;
            }
            break;
        case 3: //修改信息子菜单
            cout<<"\t\t1.修改正式员工"<<endl;
            cout<<"\t\t2.修改临时员工"<<endl;
            cout<<"\t\t请输入对应数字选择功能:";
            cin>>temp2;
            cout<<"\t\t请输入员工编号:";
            cin>>temp3;
            switch (temp2) {
                case 1:
                    reHead->modifyEmployee(temp3);
                    break;
                case 2:
                    teHead->modifyEmployee(temp3);
                    break;
                default:
                    cout<<"输入错误"<<endl;
                    break;
            }
            break;
        case 4: //删除员工子菜单
            cout<<"\t\t1.删除正式员工"<<endl;
            cout<<"\t\t2.删除临时员工"<<endl;
            cout<<"\t\t请输入对应数字选择功能:";
            cin>>temp2;
            cout<<"\t\t请输入员工编号:";
            cin>>temp3;
            switch (temp2) {
                case 1:
                    reHead->deleteEmployee(temp3);
                    break;
                case 2:
                    teHead->deleteEmployee(temp3);
                    break;
                default:
                    cout<<"输入错误"<<endl;
                    break;
            }
            break;
        case 5: //显示所有员工子菜单
            reHead->showEmployee();
            teHead->showEmployee();
            break;
        default:
            cout<<"输入错误"<<endl;
            break;
    }
    menu2(reHead,teHead);
}
void menu2(RegularEmployee* reHead,TemporaryEmployee* teHead) //菜单函数2
{
    int temp4;
    cout<<"\t\t1.返回主菜单"<<endl;
    cout<<"\t\t2.保存并退出系统"<<endl;
    cout<<"\t\t3.直接退出系统"<<endl;
    cout<<"\t\t请输入对应数字选择功能:";
    cin>>temp4;
    switch (temp4)
    {
        case 1:
            menu1(reHead,teHead);
            break;
        case 2:
            reHead->writeFile();
            teHead->writeFile();
            break;
        case 3:
            break;
        default:
            cout<<"输入错误"<<endl;
            break;
    }
}
int main()
{
    RegularEmployee re; //正式职工
    TemporaryEmployee te; //临时职工
    RegularEmployee* pRe = &re; //正式职工指针
    TemporaryEmployee* pTe = &te; //临时职工指针

    menu(pRe, pTe);

    return 0;
}
