#include<iostream>
#include<map>
#include<string.h>

using namespace std;

int main(){
    map<int,string>m;
    m[0] = "Ayush";
    m[1]="Raman";
    m[2]="Ramesh";
    m[3]="Akash";

    m.insert({5,"Aman"});
    for(auto it =m.begin() ; it!=m.end();it++){
        cout << "no. " << it->first << " name: " << it->second<<endl ;
    }

}