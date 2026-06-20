#include<iostream>

using namespace std;

class Parent{
    public:
    int x=10;
    virtual void hello(){
        // cout << "hello from par\n";
        cout << x+10<<endl;
    }
};

class Child : public Parent{
    public:
    void hello(){
        // cout << "hello from child\n";
        cout << x+5 << endl;
    }
};

int main()
{
    Child c1;
    c1.hello();
}