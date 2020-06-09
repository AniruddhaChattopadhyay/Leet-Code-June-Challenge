You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1
 

Note:

You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer


class Solution {
public:
//     int helper(int amount, int *arr,int size,vector<vector<int>> &dp){
//          if(size == 0 && amount == 0 )
//            return 1;
//        if(size == 0 )
//            return 0;
//         if(amount < 0){
//             return 0;
//         }
//         if(amount ==0)
//             return 1;
//         if(dp[amount][size]!=-1){
//             return dp[amount][size];
//         }
//         //cout<<amount<<endl;
//         int ans1 = helper(amount - arr[0],arr,size,dp);
//         int ans2 = helper(amount,arr+1,size-1,dp);
//         dp[amount][size] =  ans1 + ans2;
//         return ans1 + ans2;
        
//     }
    int change(int amount, vector<int>& coins) {
        int *arr  = new int[coins.size()];
        //copy(coins.begin(),coins.end(),arr);
        // vector<vector<int>> dp(amount+1,vector<int>(coins.size()+1,-1));
        // return helper(amount , arr , coins.size(),dp);
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,0));
        dp[0][0] = 1;
        for(int i=0;i<=coins.size();i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        // for(int i=0;i<=coins.size();i++){
        //     for(int j=0;j<=amount;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[coins.size()][amount];
    }
};