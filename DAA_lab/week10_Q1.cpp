#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
 
vector<int> maxMeetingHappen(vector<int>& st, vector<int>& et, int n) { 
    vector<pair<int,pair<int,int>>> corpus; 
    for(int i=0; i<n; i++) { 
        corpus.push_back({et[i],{st[i],i}}); 
    } 
    sort(corpus.begin(), corpus.end()); 
    vector<int> pos; 
    int currEndTime=-1; 
    for(int i=0; i<n; i++) { 
        if(corpus[i].second.first >= currEndTime) { 
            pos.push_back(corpus[i].second.second); 
            currEndTime = corpus[i].first; 
        } 
    } 
    return pos; 
} 
 
int main() { 
    int n; 
    cout<<"Enter the number of meetings:"; 
    cin>>n; 
    vector<int> st(n),et(n); 
    cout<<"Enter the starting time: "; 
    for(int i=0; i<n ;i++) { 
        cin>>st[i]; 
    } 
    cout<<"Enter the ending time: "; 
    for(int i=0; i<n; i++) { 
        cin>>et[i]; 
    } 
    vector<int> pos= maxMeetingHappen(st,et,n); 
    cout<<"No. of non-conflicting activities: "<<pos.size(); 
    cout<<"List of selected activities: "; 
    for(int i=0; i<pos.size(); i++) cout<<pos[i]<<" "; 
    return 0; 
} 