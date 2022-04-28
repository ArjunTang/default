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
    (3)修改记录:能够打开已存在的数据表文件，并对确定的任意记录进行修改，在修改 过程中，应显示记录信息，给出确认提示，并对更新的记录信息进行文件保存。
    (4)删除记录:能够打开已存在的数据表文件，可以删除数据表中的任一记录，要求具 备逻辑删除(具有恢复功能)和物理删除功能，并对新的数据表信息进行文件保存。
*/

#include<iostream>
#include<fstream>
using namespace std;

#define MAXSIZE 10 //定义类数组的最大长度

//基本职工类
enum Sex { female,male }; //性别枚举类型
enum Job { regular,temporary }; //职务枚举类型
class BaseEmployee
{
protected:
    int id; //编号
    char name[20]; //姓名
    Sex sex; //性别
    int age; //年龄
    char position[20]; //家庭住址
    Job job; //职务
    int serviceLength; //工龄
    float basePay; //基本工资
public:
    BaseEmployee* pNext=nullptr;
    BaseEmployee(){};
};

template<class T>
inline void baseInput(T &e) //输入基本信息
{
    cout<<"******************************"<<endl;
    cout<<"输入信息:"<<endl;
    cout<<"\t编号:";
    cin>>e.id;
    cout<<"\t姓名:";
    cin>>e.name;
    cout<<"\t性别(0.female 1.male):";
    cin>>(int&)e.sex;
    cout<<"\t年龄:";
    cin>>e.age;
    cout<<"\t家庭住址:";
    cin>>e.position;
    cout<<"\t职务(0.正式工 1.临时工):";
    cin>>(int&)e.job;
    cout<<"\t工龄:";
    cin>>e.serviceLength;
    cout<<"\t基本工资:";
    cin>>e.basePay;
}
template<class T>
inline void baseOutput(T& e) //输出基本信息
{
    cout<<"******************************"<<endl;
    cout<<"编号:"<<e.id<<endl;
    cout<<"姓名:"<<e.name<<endl;
    cout<<"性别(0.female 1.male):"<<e.sex<<endl;
    cout<<"年龄:"<<e.age<<endl;
    cout<<"家庭住址:"<<e.position<<endl;
    cout<<"职务(0.正式工 1.临时工):"<<e.job<<endl;
    cout<<"工龄:"<<e.serviceLength<<endl;
    cout<<"基本工资:"<<e.basePay<<endl;
}

//正式职工类
class RegularEmployee:public BaseEmployee
{
private:
    float postAllowance; //岗位津贴
    float pension; //养老金
    float housingFund; //住房公积金
    float incomeTax; //所得税
    float medicalInsurance; //医疗保险
    float realPay; //实发工资
public:
    RegularEmployee(){};
    friend istream& operator>>(istream&,RegularEmployee&); //重载输入运算符
    friend ostream& operator<<(ostream&,RegularEmployee&); //重载输出运算符
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
    cin>>(int&)e.sex;
    cout<<"\t年龄:";
    cin>>e.age;
    cout<<"\t家庭住址:";
    cin>>e.position;
    cout<<"\t职务(0.正式工 1.临时工):";
    cin>>(int&)e.job;
    cout<<"\t工龄:";
    cin>>e.serviceLength;
    cout<<"\t基本工资:";
    cin>>e.basePay;
    cout<<"\t岗位津贴:";
    cin>>e.postAllowance;
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
    cout<<"家庭住址:"<<e.position<<endl;
    cout<<"职务(0.正式工 1.临时工):"<<e.job<<endl;
    cout<<"工龄:"<<e.serviceLength<<endl;
    cout<<"基本工资:"<<e.basePay<<endl;
    cout<<"\t岗位津贴:"<<e.postAllowance<<endl;
    cout<<"\t养老金:"<<e.pension<<endl;
    cout<<"\t住房公积金:"<<e.housingFund<<endl;
    cout<<"\t所得税:"<<e.incomeTax<<endl;
    cout<<"\t医疗保险:"<<e.medicalInsurance<<endl;
    cout<<"******************************"<<endl;
    return os;
}

//临时职工类
class TemporaryEmployee:public BaseEmployee
{
private:
    float bonus; //奖金
    float incomeTax; //所得税
    float realPay; //实发工资
public:
    TemporaryEmployee(){};
    friend istream& operator>>(istream&,TemporaryEmployee&); //重载输入运算符
    friend ostream& operator<<(ostream&,TemporaryEmployee&); //重载输出运算符
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
    cin>>(int&)e.sex;
    cout<<"\t年龄:";
    cin>>e.age;
    cout<<"\t家庭住址:";
    cin>>e.position;
    cout<<"\t职务(0.正式工 1.临时工):";
    cin>>(int&)e.job;
    cout<<"\t工龄:";
    cin>>e.serviceLength;
    cout<<"\t基本工资:";
    cin>>e.basePay;
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
    cout<<"家庭住址:"<<e.position<<endl;
    cout<<"职务(0.正式工 1.临时工):"<<e.job<<endl;
    cout<<"工龄:"<<e.serviceLength<<endl;
    cout<<"基本工资:"<<e.basePay<<endl;
    cout<<"\t奖金:"<<e.bonus<<endl;
    cout<<"\t所得税:"<<e.incomeTax<<endl;
    cout<<"******************************"<<endl;
    return os;
}


//测试
int main()
{
    RegularEmployee re[MAXSIZE];
    TemporaryEmployee te[MAXSIZE];
    BaseEmployee p;
    cin>>re[0];
    cin>>te[0];
    fstream file("test.txt",ios::in|ios::out|ios::binary);
    if(!file)
    {
        cout<<"文件打开失败！"<<endl;
        return 0;
    }
    file.write((char *)&re[0],sizeof(re[0]));
    file.write((char *)&te[0],sizeof(te[0]));
    file.close();
    file.open("test.txt",ios::in|ios::out|ios::binary);
    file.read((char *)&te[1],sizeof(te[1]));
    file.read((char *)&re[1],sizeof(re[1]));
    cout<<re[1];
    cout<<te[1];
    file.close();

    return 0;
}
