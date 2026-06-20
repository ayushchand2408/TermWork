#include<iostream>
#include<fstream>

using namespace std;

/*
The useful classes for working with files in c++ are :
1.fstreambase
2.ifstream --> derived from fstreambase
3.ofstream --> derived from fstreambase
*/


// in order to work with files in c++ , there are 2 ways to open a files :
// 1 . using a constructor 
// 2. using a member function open() of the class 

int main(){
    string st = "harry bhai";
    string st2;
    //oopeneing file using constructor and writing it
    // ofstream out("smaple60.txt"); // write operation
    // out << st;

    //opening file using constructor and reading it
    ifstream in("smaple60.txt"); // Read operation
    // in>>st2;
    getline(in,st2);
    cout<<st2;

}