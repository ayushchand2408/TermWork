#include <iostream>
#include<stack>

using namespace std;

int eval(int a , int b, char ch)
{
    switch(ch){
        case '+': return a+b;
        case '-' : return a-b;
        case '*' : return a*b;
        case '/' : return a/b;
    }
}

int main()
{
    string  s="12+33/4*3*-5-";
    stack<int>st;

    int n=s.length();

    for(int i = 0 ; i<n;i++)
    {
        if(s[i] >= '0' && s[i]<= '9')
           st.push(s[i]-'0');
        
        else{
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            int res  = eval(a,b,s[i]);
            st.push(res);
        }
    }

    cout << "result is : " << st.top();

    return 0;
}