#include<iostream>

using namespace std;

class Person
{
    public:
    string name;
    int age;
};

class Student : public Person{
    public:
    int rollno;

    void show(){
         cout<< "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "rollno : " << rollno << endl;
    }
};

class Teacher:public Person
{
    public:
    string subject;

    void show(){
        cout<< "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "subject: " << subject << endl;
    }
};


int main()
{
    Student s1;
    s1.name = "Arvind";
    s1.age = 24;
    s1.rollno = 134;
    s1.show();
    Teacher t1;
    t1.name = "raman";
    t1.age = 25;
    t1.subject = "c++";
    t1.show();

}