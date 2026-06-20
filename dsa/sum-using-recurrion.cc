#include<iostream>

using namespace std;

int sum_ret(int n)
{
    int sum = 0 ;
    if(n==0) return sum;
    sum +=  n+sum_ret(n-1);
    return sum;
}
int main()
{
    int n = 100;

    int sum = sum_ret(n);
    cout << "sum of given n number of natural number : - " << sum ;
}