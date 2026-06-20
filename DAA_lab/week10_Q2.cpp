#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <queue> 
using namespace std; 
 
vector<int> maxActivityHappen(vector<int>& rt, vector<int>&dl, int n) { 
    vector<pair<int,pair<int,int>>> corpus; 
    for(int i=0; i<n; i++) corpus.push_back({dl[i],{rt[i],i}}); 
    sort(corpus.begin(), corpus.end()); 
 
    priority_queue<pair<int,int>> pq; 
    int currTime=0; 
    for(int i=0; i<n; i++) { 
        if(currTime + corpus[i].second.first <=corpus[i].first) { 
            pq.push({corpus[i].second.first, corpus[i].second.second}); 
            currTime+=corpus[i].second.first; 
        } 
        else if(!pq.empty() && pq.top().first > corpus[i].second.first){ 
            currTime-=pq.top().first;  pq.pop(); 
            pq.push({corpus[i].second.first, corpus[i].second.second}); 
        } 
    } 
    vector<int> pos; 
    while(!pq.empty()) { 
        pos.push_back(pq.top().second);   pq.pop(); 
    } 
    return pos; 
} 
 
int main() { 
    int n; 
    cout<<"Enter the number of activities: "; 
    cin>>n; 
    vector<int> rt(n), dl(n); 
    cout<<"Enter the required time of each activity: "; 
    for(int i=0; i<n; i++) cin>>rt[i]; 
    cout<<"Enter the deadline of each activity: "; 
    for(int i=0; i<n; i++) cin>>dl[i]; 
 
    vector<int> lst = maxActivityHappen(rt,dl,n); 
    cout<<"The total number of activities happen: "<<lst.size(); 
    cout<<"The list of task that can happen :"; 
    for(int i=0; i<lst.size(); i++) cout<<lst[i]<<" "; 
    return 0; 
}