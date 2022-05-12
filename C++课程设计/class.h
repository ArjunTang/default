#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
using namespace std;

//基本职工类
enum Sex { female,male }; //性别枚举类型
enum Job { regular,temporary }; //职务枚举类型
class BaseEmployee
{
protected:
    int id; //编号
    string name; //姓名
    Sex sex; //性别
    int age; //年龄
    string address; //家庭住址
    Job job; //职务
    int workage; //工龄
    float basicwage; //基本工资
public:
    BaseEmployee(){};
    int getId() { return id; } //获取编号
    string getName() { return name; } //获取姓名
    Job getJob() { return job; } //获取职务
    void setId(int id) { this->id = id; } //设置编号
    void setName(string name) { this->name = name; } //设置姓名
    void setSex(Sex sex) { this->sex = sex; } //设置性别
    void setAge(int age) { this->age = age; } //设置年龄
    void setAddress(string address) { this->address = address; } //设置家庭住址
    void setJob(Job job) { this->job = job; } //设置职务
    void setWorkage(int workage) { this->workage = workage; } //设置工龄
    void setBasicwage(float basicwage) { this->basicwage = basicwage; } //设置基本工资
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
    RegularEmployee* next; //指针域
    RegularEmployee(){};
    friend istream& operator>>(istream&,RegularEmployee&); //重载输入运算符
    friend ostream& operator<<(ostream&,RegularEmployee&); //重载输出运算符
    void setPostwage(float postwage) { this->postwage = postwage; } //设置岗位津贴
    void setPension(float pension) { this->pension = pension; } //设置养老金
    void setHousingFund(float housingFund) { this->housingFund = housingFund; } //设置住房公积金
    void setIncomeTax(float incomeTax) { this->incomeTax = incomeTax; } //设置所得税
    void setMedicalInsurance(float medicalInsurance) { this->medicalInsurance = medicalInsurance; } //设置医疗保险
    void setRealPay(); //设置实发工资
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
    cin>>e.address;
    cout<<"\t职务(0.正式工 1.临时工):";
    cin>>(int&)e.job;
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

//临时职工类
class TemporaryEmployee:public BaseEmployee
{
private:
    float bonus; //奖金
    float incomeTax; //所得税
    float realPay; //实发工资
public:
    TemporaryEmployee* next; //指针域
    TemporaryEmployee(){};
    friend istream& operator>>(istream&,TemporaryEmployee&); //重载输入运算符
    friend ostream& operator<<(ostream&,TemporaryEmployee&); //重载输出运算符
    void setBonus(float bonus) { this->bonus = bonus; } //设置奖金
    void setIncomeTax(float incomeTax) { this->incomeTax = incomeTax; } //设置所得税
    void setRealPay(); //设置实发工资
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
    cin>>e.address;
    cout<<"\t职务(0.正式工 1.临时工):";
    cin>>(int&)e.job;
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

#endif