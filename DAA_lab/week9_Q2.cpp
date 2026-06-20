#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
 
double ksnap(vector<double>& value, vector<double>& weight, int n, int capacity) { 
    vector<pair<double,pair<int,int>>> frac; 
    for(int i=0; i<n; i++)  
        frac.push_back({value[i]/weight[i],{weight[i],value[i]}}); 
 
    sort(frac.rbegin(), frac.rend()); 
 
    double maxValue=0; 
    for(int i=0; i<n && capacity>0; i++) { 
        //weight of the item is fitting into the capacity     
        if(capacity>=frac[i].second.first) { 
            maxValue+=frac[i].second.second; 
            capacity-=frac[i].second.first; 
        }  
        //collect the value according to the remainig capacity 
        else { 
            maxValue+=frac[i].first*capacity; 
            capacity=0; 
        } 
    } 
    return maxValue; 
} 
 
int main() { 
    int n,w; 
    cout<<"Enter the number of values:"; 
    cin>>n; 
    vector<double> value(n), weight(n); 
    cout<<"Enter the weights: "; 
    for(int i=0; i<n; i++)  
        cin>>weight[i]; 
    cout<<"Enter the values: "; 
    for(int i=0; i<n; i++)  
        cin>>value[i]; 
    cout<<":Enter the capacity of the bag: "; 
    cin>>w; 
    cout<<"Maximum value retrived: "<<ksnap(value,weight,n,w)<<endl; 
    return 0; 
}