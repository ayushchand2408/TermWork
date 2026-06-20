#include<iostream>

using namespace std;

class student{
    public:
    string name ;
    int age;

    student(string name , int age)
    {
        this -> name = name;
        this -> age = age;
    }
};
class teacher{
    public:
    int salary;
    teacher(int salary)
    {
        this -> salary = salary;
    }
};

class TA : public student , public teacher{
    public:

    TA(string name , int age , int salary) : student(name , age) , teacher(salary){}
    void show()
    {
        cout<< "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "salary : " << salary << endl;
    }
};

int main()
{
    TA t1("Aman" ,28,25000);
    t1.show();
}