#include<iostream>
using namespace std;

class Shape
{
    virtual void draw() = 0;
};

class Circle : public Shape
{
    public:
    void draw()
    {
        cout <<" drawing a circle";
    }
};

int main()
{
    Circle c1;
    c1.draw();
    
}