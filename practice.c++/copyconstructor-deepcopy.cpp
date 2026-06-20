#include<iostream>

using namespace std;

class student{
    public:
    string name ;
    double* cgpaPtr;

    student(string name , double cgpa)
    {
        this -> name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    student(student &obj)
    {
        this -> name = name;
        cgpaPtr = new double;
        *cgpaPtr = *obj.cgpaPtr;
    }

    
    void show()
    {
        cout << "name :- " << name << endl;
        cout << "cgpa :- "  << *cgpaPtr << endl;
    }

};

int main()
{
    student s1("Aman ji",7.67);
    student s2(s1);

    s1.show();
    *(s2.cgpaPtr) = 9.0;
    s1.show();
    s2.name = "neha";
    s2.show();

}