#ifndef FUNCTION_H
#define FUNCTION_H

#include "class.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void menu1(RegularEmployee* reHead,TemporaryEmployee* teHead); //菜单函数1
void menu2(RegularEmployee* reHead,TemporaryEmployee* teHead); //菜单函数2
void open(RegularEmployee* reHead,TemporaryEmployee* teHead); //打开文件函数
void save(RegularEmployee* reHead,TemporaryEmployee* teHead); //保存文件函数
void addEmployee(int job,RegularEmployee* reHead,TemporaryEmployee* teHead); //添加员工信息函数
void searchEmployee(int flag,RegularEmployee* reHead,TemporaryEmployee* teHead); //查询员工信息函数
void modifyEmployee(int id,int flag,RegularEmployee* reHead,TemporaryEmployee* teHead); //修改员工信息函数
void deleteEmployee(int id,RegularEmployee* reHead,TemporaryEmployee* teHead); //删除员工信息函数
template<typename T>
void modify1(int flag,T* t); //修改员工信息子函数1
void modify2(int flag,RegularEmployee* re); //修改员工信息子函数2
void modify3(int flag,TemporaryEmployee* te); //修改员工信息子函数3


void menu(RegularEmployee* reHead,TemporaryEmployee* teHead) //菜单函数
{
    cout<<"欢迎使用员工管理系统!"<<endl;
    open(reHead,teHead); //打开文件
    menu1(reHead,teHead);
    menu2(reHead,teHead);
    cout<<"感谢使用员工管理系统!"<<endl;
}
void menu1(RegularEmployee* reHead,TemporaryEmployee* teHead) //菜单函数1
{
    int temp1,temp2;
    //主菜单
    cout<<"\t1.添加员工"<<endl;
    cout<<"\t2.查询员工"<<endl;
    cout<<"\t3.修改信息"<<endl;
    cout<<"\t4.删除员工"<<endl;
    cout<<"\t请输入对应数字选择功能:"<<endl;
    cin>>temp1;
    //子菜单
    switch (temp1)
    {
    case 1: //添加员工子菜单
        cout<<"\t\t1.添加正式员工"<<endl;
        cout<<"\t\t2.添加临时员工"<<endl;
        cout<<"\t\t请输入对应数字选择功能:"<<endl;
        cin>>temp2;
        addEmployee(temp2,reHead,teHead);
        cout<<"添加成功"<<endl;
        break;
    case 2: //查询员工子菜单
        cout<<"\t\t1.按照编号查询"<<endl;
        cout<<"\t\t2.按照姓名查询"<<endl;
        cout<<"\t\t3.按照职务查询"<<endl;
        cout<<"\t\t请输入对应数字选择功能:"<<endl;
        cin>>temp2;
        searchEmployee(temp2,reHead,teHead);
        cout<<"查询成功"<<endl;
        break;
    case 3: //修改信息子菜单
        int temp3;
        cout<<"\t\t请输入要修改的员工编号:"<<endl;
        cin>>temp2;
        cout<<"\t\t\t1.全部修改"<<endl;
        cout<<"\t\t\t2.修改编号"<<endl;
        cout<<"\t\t\t3.修改姓名"<<endl;
        cout<<"\t\t\t4.修改性别"<<endl;
        cout<<"\t\t\t5.修改年龄"<<endl;
        cout<<"\t\t\t6.修改家庭住址"<<endl;
        cout<<"\t\t\t7.修改职务"<<endl;
        cout<<"\t\t\t8.修改工龄"<<endl;
        cout<<"\t\t\t9.修改基本工资"<<endl;
        cout<<"\t\t\t10.修改所得税"<<endl;
        cout<<"\t\t\t11.修改岗位津贴"<<endl;
        cout<<"\t\t\t12.修改养老金"<<endl;
        cout<<"\t\t\t13.修改住房公积金"<<endl;
        cout<<"\t\t\t14.修改医疗保险"<<endl;
        cout<<"\t\t\t15.修改奖金"<<endl;
        cout<<"\t\t\t请输入对应数字选择功能:"<<endl;
        cin>>temp3;
        modifyEmployee(temp2,temp3,reHead,teHead);
        cout<<"修改成功"<<endl;
        break;
    case 4: //删除员工子菜单
        cout<<"\t\t请输入要删除的员工编号:"<<endl;
        cin>>temp2;
        deleteEmployee(temp2,reHead,teHead);
        cout<<"删除成功"<<endl;
        break;
    }
}
void menu2(RegularEmployee* reHead,TemporaryEmployee* teHead) //菜单函数2
{
    int temp4;
    cout<<"\t1.返回主菜单"<<endl;
    cout<<"\t2.保存并退出系统"<<endl;
    cout<<"\t3.直接退出系统"<<endl;
    cout<<"\t请输入对应数字选择功能:"<<endl;
    cin>>temp4;
    switch (temp4)
    {
    case 1:
        menu1(reHead,teHead);
        break;
    case 2:
        save(reHead,teHead);
        break;
    case 3:
        break;
    }
}
void addEmployee(int job,RegularEmployee* reHead,TemporaryEmployee* teHead) //添加员工函数
{
    RegularEmployee* reTemp = reHead;
    TemporaryEmployee* teTemp = teHead;
    if(job==1) //添加正式员工
    {
        RegularEmployee temp;
        cin>>temp;
        temp.setRealPay();
        reTemp->next = new RegularEmployee(temp);
        reTemp = reTemp->next;
        return;
    }
    else if(job==2) //添加临时员工
    {
        TemporaryEmployee temp;
        cin>>temp;
        temp.setRealPay();
        teTemp->next = new TemporaryEmployee(temp);
        teTemp = teTemp->next;
        return;
    }
    cout<<"输入错误！"<<endl;
}
void searchEmployee(int flag,RegularEmployee* reHead,TemporaryEmployee* teHead) //查询员工函数
{
    RegularEmployee* reTemp = reHead;
    TemporaryEmployee* teTemp = teHead;
    if(flag==1) //按照编号查询
    {
        int id;
        cout<<"\t\t\t请输入要查询的员工编号:"<<endl;
        cin>>id;
        while(reTemp->next!=nullptr)
        {
            if(reTemp->next->getId()==id)
            {
                cout<<*reTemp->next;
                return;
            }
            reTemp = reTemp->next;
        }
        while(teTemp->next!=nullptr)
        {
            if(teTemp->next->getId()==id)
            {
                cout<<*teTemp->next;
                return;
            }
            teTemp = teTemp->next;
        }
    }
    else if(flag==2) //按照姓名查询
    {
        string name;
        cout<<"\t\t\t请输入要查询的员工姓名:"<<endl;
        cin>>name;
        while(reTemp->next!=nullptr)
        {
            if(reTemp->next->getName()==name)
            {
                cout<<*reTemp->next;
                return;
            }
            reTemp = reTemp->next;
        }
        while(teTemp->next!=nullptr)
        {
            if(teTemp->next->getName()==name)
            {
                cout<<*teTemp->next;
                return;
            }
            teTemp = teTemp->next;
        }
    }
    else if(flag==3) //按照职务查询
    {
        Job job;
        cout<<"\t\t\t请输入要查询的员工职务:"<<endl;
        cin>>(int&)job;
        while(reTemp->next!=nullptr)
        {
            if(reTemp->next->getJob()==job)
            {
                cout<<*reTemp->next;
                return;
            }
            reTemp = reTemp->next;
        }
        while(teTemp->next!=nullptr)
        {
            if(teTemp->next->getJob()==job)
            {
                cout<<*teTemp->next;
                return;
            }
            teTemp = teTemp->next;
        }
    }
    cout<<"查询失败！"<<endl;
}
void modifyEmployee(int id,int flag,RegularEmployee* reHead,TemporaryEmployee* teHead) //修改员工函数
{
    RegularEmployee* reTemp = reHead;
    TemporaryEmployee* teTemp = teHead;
    if(flag<=0 || flag>=16)
    {
        cout<<"输入错误！"<<endl;
        return;
    }
    while(reTemp->next!=nullptr)
    {
        if(reTemp->next->getId()==id)
        {
            if(flag>=1 && flag<=10)
                modify1(flag,reTemp->next);
            else if(flag>=11 && flag<=14)
                modify2(flag,reTemp->next);
            return;
        }
        reTemp = reTemp->next;
    }
    while(teTemp->next!=nullptr)
    {
        if(teTemp->next->getId()==id)
        {
            if(flag>=1 && flag<=10)
                modify1(flag,reTemp->next);
            else if(flag==15)
                modify3(flag,teTemp->next);
            return;
        }
        teTemp = teTemp->next;
    }
    cout<<"没有该员工！"<<endl;
}
template<typename T>
void modify1(int flag,T* t) //修改员工子函数
{
    if(flag==1) //全部修改
    {
        T temp;
        cin>>temp;
        t=new T(temp);
        return;
    }
    else if(flag==2) //修改编号
    {
        int id;
        cout<<"\t\t\t\t请输入编号:"<<endl;
        cin>>id;
        t->setId(id);
        return;
    }
    else if(flag==3) //修改姓名
    {
        string name;
        cout<<"\t\t\t\t请输入姓名:"<<endl;
        cin>>name;
        t->setName(name);
        return;
    }
    else if(flag==4) //修改性别
    {
        Sex sex;
        cout<<"\t\t\t\t请输入性别(0.female 1.male):"<<endl;
        cin>>(int&)sex;
        t->setSex(sex);
        return;
    }
    else if(flag==5) //修改年龄
    {
        int age;
        cout<<"\t\t\t\t请输入年龄:"<<endl;
        cin>>age;
        t->setAge(age);
        return;
    }
    else if(flag==6) //修改家庭住址
    {
        string address;
        cout<<"\t\t\t\t请输入家庭住址:"<<endl;
        cin>>address;
        t->setAddress(address);
        return;
    }
    else if(flag==7) //修改职务
    {
        Job job;
        cout<<"\t\t\t\t请输入职务:"<<endl;
        cin>>(int&)job;
        t->setJob(job);
        return;
    }
    else if(flag==8) //修改工龄
    {
        int workage;
        cout<<"\t\t\t\t请输入工龄:"<<endl;
        cin>>workage;
        t->setWorkage(workage);
        return;
    }
    else if(flag==9) //修改基本工资
    {
        float basicwage;
        cout<<"\t\t\t\t请输入基本工资:"<<endl;
        cin>>basicwage;
        t->setBasicwage(basicwage);
        t->setRealPay();
        return;
    }
    else if(flag==10) //修改所得税
    {
        float incomeTax;
        cout<<"\t\t\t\t请输入所得税:"<<endl;
        cin>>incomeTax;
        t->setIncomeTax(incomeTax);
        t->setRealPay();
        return;
    }
}
void modify2(int flag,RegularEmployee* re) //修改员工子函数
{
    if(flag==11) //修改岗位津贴
    {
        float postwage;
        cout<<"\t\t\t\t请输入岗位津贴:"<<endl;
        cin>>postwage;
        re->setPostwage(postwage);
        re->setRealPay();
        return;
    }
    else if(flag==12) //修改养老金
    {
        float pension;
        cout<<"\t\t\t\t请输入养老金:"<<endl;
        cin>>pension;
        re->setPension(pension);
        re->setRealPay();
        return;
    }
    else if(flag==13) //修改住房公积金
    {
        float housingFund;
        cout<<"\t\t\t\t请输入住房公积金:"<<endl;
        cin>>housingFund;
        re->setHousingFund(housingFund);
        re->setRealPay();
        return;
    }
    else if(flag==14) //修改医疗保险
    {
        float medicalInsurance;
        cout<<"\t\t\t\t请输入医疗保险:"<<endl;
        cin>>medicalInsurance;
        re->setMedicalInsurance(medicalInsurance);
        re->setRealPay();
        return;
    }
}
void modify3(int flag,TemporaryEmployee* te) //修改员工子函数
{
    if(flag==15) //修改奖金
    {
        float bonus;
        cout<<"\t\t\t\t请输入奖金:"<<endl;
        cin>>bonus;
        te->setBonus(bonus);
        te->setRealPay();
        return;
    }
}
void deleteEmployee(int id,RegularEmployee* reHead,TemporaryEmployee* teHead) //删除员工函数
{
    RegularEmployee* reTemp = reHead;
    TemporaryEmployee* teTemp = teHead;
    while(reTemp->next!=nullptr)
    {
        if(reTemp->next->getId()==id)
        {
            reTemp->next = reTemp->next->next;
            return;
        }
        reTemp = reTemp->next;
    }
    while(teTemp->next!=nullptr)
    {
        if(teTemp->next->getId()==id)
        {
            teTemp->next = teTemp->next->next;
            return;
        }
        teTemp = teTemp->next;
    }
    cout<<"没有该员工！"<<endl;
}
void open(RegularEmployee* reHead,TemporaryEmployee* teHead) //打开文件函数
{
    RegularEmployee* reTemp = reHead;
    TemporaryEmployee* teTemp = teHead;
    fstream reData("RegularEmployee.txt",ios::out|ios::binary);
    if(!reData)
    {
        cout<<"打开\"RegularEmployee.txt\"文件失败！"<<endl;
        return;
    }
    fstream teData("TemporaryEmployee.txt",ios::out|ios::binary);
    if(!teData)
    {
        cout<<"打开文件\"TemporaryEmployee.txt\"失败！"<<endl;
        return;
    }
    while (!reData.eof())
    {
        reData.read((char*)&reTemp->next,sizeof(RegularEmployee));
        reTemp = reTemp->next;
    }
    while (!teData.eof())
    {
        teData.read((char*)&teTemp->next,sizeof(TemporaryEmployee));
        teTemp = teTemp->next;
    }
    reData.close();
    teData.close();
}
void save(RegularEmployee* reHead,TemporaryEmployee* teHead) //保存文件函数
{
    RegularEmployee* reTemp = reHead;
    TemporaryEmployee* teTemp = teHead;
    fstream reData("RegularEmployee.txt",ios::binary);
    if(!reData)
    {
        cout<<"打开\"RegularEmployee.txt\"文件失败！"<<endl;
        return;
    }
    fstream teData("TemporaryEmployee.txt",ios::binary);
    if(!teData)
    {
        cout<<"打开文件\"TemporaryEmployee.txt\"失败！"<<endl;
        return;
    }

}

#endif