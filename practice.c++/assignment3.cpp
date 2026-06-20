#include<iostream>
#include<string>
using namespace std;
class Person
{
    public:
    string name;
    int age;
    public:
    Person()
    {
        name="";
        age=0;
    }
    Person(string name,int age)
    {
        this->name=name;
        this->age=age;
    }
    virtual void getdata()=0;
    virtual void putdata()=0;
};
class Professor:public Person
{
    public:
    static int id_counter;
    int publication,cur_id;
    public:
    Professor()
    {
        publication=0;
        cur_id=0;
    }
    void getdata()
    {
        cout<<"Enter the name , age and publication Respectively :"<<endl;
        cin>>name;
        cin>>age;
        cin>>publication;
        cur_id=id_counter++;

    }
    void putdata()
    {
        cout<<name<<endl<<age<<endl<<publication<<endl<<cur_id;
    }
};
int Professor::id_counter=1;
class Student:public Person
{
    public:
    static int id_counter;
    int cur_id,marks[6];
    public:
    Student()
    {
        for(int i=0;i<6;i++)
        {
            marks[i]=0;
        }
    }
    void getdata()
    {
        cout << "Enter name, age and 6 marks: ";
        cin>>name;
        cin>>age;
        for(int i=0;i<6;i++)
        {
            cin>>marks[i];
        }
        cur_id=id_counter++;
    }
    void putdata()
    {
        int total_marks=0;
        for(int i=0;i<6;i++)
        {
            total_marks=total_marks+marks[i];
        }
        cout<<name<<endl<<age<<endl<<total_marks<<endl<<cur_id<<endl;
    }
};
int Student::id_counter=1;
int main()
{
    cout<<"Enter the number of objects: ";
    int n;
    cin>>n;

    Person* people[n];
    for(int i=0;i<n;i++)
    {
        int type;
        cout<<"Enter 1 for professor and 2 for student :"<<endl;
        cin>>type;
        switch(type)
        {
            case 1:
            {   
                // Create Professor class' object;
                Professor* p = new Professor();
                p->getdata();
                people[i] = p;  
                break;
            }
             case 2: {
                // Create Student class' object
                Student* s = new Student();
                s->getdata();
                people[i] = s;  
                break;
            }
            default:
                cout << "Invalid input for type" << endl;
                break;
        
    
        }
    }
    for(int i=0;i<n;i++)
    {
        people[i]->putdata();
    }
 
   return 0;
}