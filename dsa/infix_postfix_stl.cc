#include <iostream>
#include <stack>
using namespace std;
int prec(char ch){
    switch(ch){
        case '+': return 1;
        case '-': return -1;
        case '*': return 2;
        case '/': return -2;
    }
}
char retop(int i){
    switch(i){
        case 1: return '+';
        case -1: return '-';
        case 2: return '*';
        case -2: return '/';
    }
}
int main(){
    string out="";
    string s;
    cin>>s;
    int n=s.length();
    stack <int> st;
    for(int i=0;i<n;i++){
        if(s[i]=='(')
            st.push(0);
        else if(s[i]>='a'&&s[i]<='z')
            out+=s[i];
        else if(s[i]==')'){
            while(st.top()!=0){
               int t=st.top();
               char ch=retop(t);
               st.pop();
               out+=ch;
            }
            st.pop();
        }
        else{
            if(st.empty())
                st.push(prec(s[i]));
            else{
                while(abs(prec(s[i]))<abs(st.top())){
                    int t=st.top();
                    st.pop();
                    out+=retop(t);
                }
                st.push(prec(s[i]));
            }    
        }
    }
    while(!st.empty()){
        int t=st.top();
        st.pop();
        out+=retop(t);
    }
    cout<<"answer= "<<out<<endl;
    return 0;
}