#include <iostream> 
#include <vector> 
using namespace std; 
 
int waysToAddUp(vector<int>& coins, int index, int currSum, int target, 
vector<vector<int>>& dp) { 
    if(currSum==0) return 1; 
    if(index<0 ) return 0; 
 
    if(dp[index][currSum]!=-1) return dp[index][currSum]; 
 
    if(coins[index] > currSum) return dp[index][currSum] = waysToAddUp(coins,index-1,currSum,target,dp); 
 
    int f = waysToAddUp(coins,index-1,currSum,target,dp); 
    int s = waysToAddUp(coins,index,currSum-coins[index],target,dp); 
 
    return dp[index][currSum] = f+s; 
} 
 
int main() { 
    int n,target; 
    cout<<"Enter the number of coins:"; 
    cin>>n; 
    vector<int> coins(n); 
    cout<<"Enter the value of coins:"; 
    for(int i=0; i<n; i++) cin>>coins[i]; 
    cout<<"Enter the target:"; 
    cin>>target; 
 
    vector<vector<int>> dp(n+1,vector<int>(target+1,-1)); 
    cout<<"Ways to add up the target are "<<waysToAddUp(coins,n-1,target,target,dp)<<"\n"<<endl; 
    return 0; 
}