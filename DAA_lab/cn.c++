int maxsum(i,x,y,z,a[],b[]){
    if(i == n) return 0;

    if(dp[i][x][y][z] != -1) return dp[i][x][y][z];

    ans = maxSum(i+1,x,y,z,a,b) - b[i];
    if(x-1 >=0 && y-1 >= 0){
        ans = max(ans,maxSum(i+1,x-1,y-1,z,a,b) + a[i]*x-1*y-1*z);
    }
    if(y-1 >=0 && z-1 >= 0 ){
        ans = max(ans,maxSum(i+1,x,y-1,z-1,a,b) + a[i]*x*y-1*z-1);
    }
    return dp[i][x][y][z] = ans;
}


x.start,y.start,z.start,n,a[],b[]
vector<vector<int>>prev_dp(x.start+1,vector<int>(z.start+1,INT_MIN));
prev_dp[0][0] = 0;

for i= 0 to n:
    vector<vector<int>>curr_dp(x.start +1 , vector<int>(z.start +1 , INT_MIN));
    for j = 0 to x.start:
        for k = 0 to z.start:
            if(prev_dp[j][k] == INT_MIN) continue;

            op1 -> curr_dp[j][k] = max(curr_dp[j][k] , prev_dp[j][k] - b[i]);
            x.curr = x.start - j;
            z.curr = z.start - k;
            y.curr = y.start - (j+k);

            op2 -> if(x.curr > 0 && y.curr > 0)
                    curr_dp[j+1][k] = max(curr_dp[j+1][k] , (prev_dp[j+1][k] + a[i] * (x.curr-1) * (y.curr-1) * z.curr))

            op3 ->  if(z.curr > 0 && y.curr > 0)
                    curr_dp[j+1][k] = max(curr_dp[j][k+1] , (prev_dp[j][k+1] + a[i] * x.curr * (y.curr-1) * (z.curr-1)))
    copy(curr_dp.begin(),curr_dp.end() , prev_dp.end());

max_sum =0;

for j =0 to x.start:
    for k = 0 to z.start:
        if(prev_dp[j][k] > max_sum)
            max_sum = prev_dp[j][k];

ans = max_sum % (1e9 + 7);
if(ans < 0)
    ans += 1e9+7;
return ans;

t.c = O(nxz)

s.c = o(xz)
