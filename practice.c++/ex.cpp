#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Shape{
    public:
    virtual void area(int a) = 0;
    virtual void area(int a , int b) = 0;
    
};


class Rectangle : public Shape{
    public :
    void area(int a , int b) override {
        cout << "Area of Rectangle :- " << a*b <<endl;
    }
    void area(int a ) override {
        cout << "Area of Rectangle :- " << a <<endl;
    }
};

// class Circle : public Shape {
//     public:
//     void area(int a ) override{
//         cout << "Area of circle :- " << a* M_PI << endl;
//     }
// };

class person{
    string name;
    int age;
    string gender;
    public:
    person(string name , int age , string gender){
        this->name = name;
        this->age = age;
        this->gender = gender;
    }
    void hi(){
        cout << "food";
    }
    friend class student;
};

class student : public person {
    int roll_no;
    int study_year;
    public:
    student(string name , int age , string gender , int roll_no , int study_year): person(name ,age ,gender){
        this -> roll_no = roll_no;
        this-> study_year = study_year;
    }

    void show(){
        cout << name << endl;
    }
};

int main(){
    student s("a" , 1,"M",34,3);
    s.show();
    s.hi();

}