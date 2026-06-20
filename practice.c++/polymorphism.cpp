//polymorphism is the ability of object to take on different forms or behave in different 
//ways depending on the contex in which they are used.
#include<iostream>
using namespace std;

// class Student
// {
//     public:
//     string name;
//     Student(){
//         cout << "non-perameterize\n";
//     }
//     Student(string name)
//     {
//         this->name = name;
//         cout << "parameterized\n";
//     }
// };

// int main()
// {
//     Student s1;

// }

class Sum1
{
    public:
    int x,y;

    Sum1(int x, int y){
        this -> x = x;
        this -> y = y;
    }
    void operator ++()
    {
        x+=1;
        y+=1;
    }
    // void operator ++(int num)
    // {
    //     x+=1;
    //     y += 1;
    // }
    friend void operator ++(Sum1&,int num);
    void show()
    {
        cout << "x : " << x << endl;
        cout << "y : " << y << endl;
    }
};
void operator++(Sum1&s1 , int num)
{
    ++(s1.x);
    ++(s1.y);
}

int main()
{
    Sum1 s1(5,6);
    ++s1;
    s1.show();
    s1++;
    s1.show();
}