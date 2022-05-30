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
void menu1(RegularEmployee* reHead,TemporaryEmployee* teHead); //菜单1
void menu2(RegularEmployee* reHead,TemporaryEmployee* teHead); //菜单2
void open(RegularEmployee* reHead,TemporaryEmployee* teHead); //打开文件
void save(RegularEmployee* reHead,TemporaryEmployee* teHead); //保存文件
void addEmployee(int job,RegularEmployee* reHead,TemporaryEmployee* teHead); //添加员工
void searchEmployee(int flag,RegularEmployee* reHead,TemporaryEmployee* teHead); //查询员工
void modifyEmployee(int id,int flag,RegularEmployee* reHead,TemporaryEmployee* teHead); //修改员工
void deleteEmployee(int id,RegularEmployee* reHead,TemporaryEmployee* teHead); //删除员工

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
        addEmployee(temp2,reHead,teHead);
        cout<<"添加成功"<<endl;
        break;
    case 2: //查询员工子菜单
        cout<<"\t\t1.按照编号查询"<<endl;
        cout<<"\t\t2.按照姓名查询"<<endl;
        cout<<"\t\t3.按照职务查询"<<endl;
        cout<<"\t\t请输入对应数字选择功能:";
        cin>>temp2;
        searchEmployee(temp2,reHead,teHead);
        cout<<"查询成功"<<endl;
        break;
    case 3: //修改信息子菜单
        int temp3;
        cout<<"\t\t请输入要修改的员工编号:";
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
        cout<<"\t\t\t请输入对应数字选择功能:";
        cin>>temp3;
        modifyEmployee(temp2,temp3,reHead,teHead);
        cout<<"修改成功"<<endl;
        break;
    case 4: //删除员工子菜单
        cout<<"\t\t请输入要删除的员工编号:";
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
    cout<<"\t请输入对应数字选择功能:";
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
        cout<<"\t\t\t请输入要查询的员工编号:";
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
        cout<<"\t\t\t请输入要查询的员工姓名:";
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
        cout<<"\t\t\t请输入要查询的员工职务:";
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
template<typename T>
void modify1(int flag,T* t); //修改员工子函数
void modify2(int flag,RegularEmployee* re); //修改员工子函数
void modify3(int flag,TemporaryEmployee* te); //修改员工子函数
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
    if(flag==1){
        //全部修改
        T temp;
        cin >> temp;
        t = new T(temp);
    }
    else if(flag==2) {
        //修改编号
        int id;
        cout << "\t\t\t\t请输入编号:";
        cin >> id;
        t->setId(id);
    }
    else if(flag==3){
        //修改姓名
        string name;
        cout<<"\t\t\t\t请输入姓名:";
        cin>>name;
        t->setName(name);
    }
    else if(flag==4) {
        //修改性别
        Sex sex;
        cout << "\t\t\t\t请输入性别(0.female 1.male):";
        cin >> (int &) sex;
        t->setSex(sex);
    }
    else if(flag==5){
        //修改年龄
        int age;
        cout<<"\t\t\t\t请输入年龄:";
        cin>>age;
        t->setAge(age);
    }
    else if(flag==6){
        //修改家庭住址
        string address;
        cout<<"\t\t\t\t请输入家庭住址:";
        cin>>address;
        t->setAddress(address);
    }
    else if(flag==7){
        //修改职务
        Job job;
        cout<<"\t\t\t\t请输入职务:";
        cin>>(int &)job;
        t->setJob(job);
    }
    else if(flag==8){
        //修改工龄
        int workAge;
        cout<<"\t\t\t\t请输入工龄:";
        cin>>workAge;
        t->setWorkage(workAge);
    }
    else if(flag==9){
        //修改基本工资
        float basicwage;
        cout<<"\t\t\t\t请输入基本工资:";
        cin>>basicwage;
        t->setBasicwage(basicwage);
        t->setRealPay();
    }
    else if(flag==10) {
        //修改所得税
        float incomeTax;
        cout << "\t\t\t\t请输入所得税:";
        cin >> incomeTax;
        t->setIncomeTax(incomeTax);
        t->setRealPay();
    }
}
void modify2(int flag,RegularEmployee* re) //修改员工子函数
{
    if(flag==11) {

        //修改岗位津贴
        float postwage;
        cout << "\t\t\t\t请输入岗位津贴:";
        cin >> postwage;
        re->setPostwage(postwage);
        re->setRealPay();
    }
    else if(flag==12){
        //修改养老金
        float pension;
        cout<<"\t\t\t\t请输入养老金:";
        cin>>pension;
        re->setPension(pension);
        re->setRealPay();
    }
    else if(flag==13){
        //修改住房公积金
        float housingFund;
        cout<<"\t\t\t\t请输入住房公积金:";
        cin>>housingFund;
        re->setHousingFund(housingFund);
        re->setRealPay();
    }
    else if(flag==14){
        //修改医疗保险
        float medicalInsurance;
        cout<<"\t\t\t\t请输入医疗保险:";
        cin>>medicalInsurance;
        re->setMedicalInsurance(medicalInsurance);
        re->setRealPay();
    }
}
void modify3(int flag,TemporaryEmployee* te) //修改员工子函数
{
    if(flag==15){
        //修改奖金
        float bonus;
        cout<<"\t\t\t\t请输入奖金:";
        cin>>bonus;
        te->setBonus(bonus);
        te->setRealPay();
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
int main()
{
    RegularEmployee* reHead; //正式职工
    TemporaryEmployee* teHead; //临时职工

    menu(reHead,teHead);

    return 0;
}
