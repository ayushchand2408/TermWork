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
    
    ~student(){
        cout << "hi, I delete eveything";
        delete cgpaPtr;//memeory leak;
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
    s1.show();
}