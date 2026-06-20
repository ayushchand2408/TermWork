#include<iostream>

using namespace std;

class sum{
    int k,n;
    public:
    sum():k(0),n(0){}
    sum(int k,int n): k(k),n(n){}
    sum operator +(sum&o){
        return sum(k+o.k,n+o.n);
    }
    friend ostream & operator <<(ostream& o,sum& s){
        o<<s.k << " + "<<s.n << "i" ;
        return o;
    }
};
int main()
{
sum a1(5,6),a2(6,7);
sum a3 = a1 + a2;
cout << a3 <<endl;
}