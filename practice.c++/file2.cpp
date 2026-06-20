#include<iostream> 
#include<fstream> 
#include<cctype> 
using namespace std; 
int main(){ 
    ifstream inputFile("source.txt"); 
    ofstream outputFile("destination.txt"); 
    if(!inputFile.is_open() || !outputFile.is_open()){ 
        cerr<<"Error opening file!"<<endl; 
        return 1; 
    } 
    char ch; 
    while(inputFile.get(ch)){ 
        if(isalpha(ch)){ 
            ch=islower(ch)?tolower(ch):toupper(ch); 
        } 
        outputFile.put(ch); 
    } 
    cout<<"File is copied from Source to desitnation."<<endl; 
    inputFile.close(); 
    outputFile.close(); 
    cout<<"\n****************************************************************** *********"<<endl; 
}