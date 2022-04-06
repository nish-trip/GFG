#include "test.h"

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<bool>>memo(arr.size()+1, vector<bool>(sum+1));
        for(int i=0; i<=arr.size(); i++){
            memo[i][0] = true;
        }
        for(int i=1; i<=arr.size(); i++){
            for(int j=1; j<=sum; j++){
                if(arr[i-1]>j){
                    memo[i][j] = memo[i-1][j];
                }
                else{
                    memo[i][j] = memo[i-1][j] || memo[i-1][j-arr[i-1]];
                }
            }
        }
        return memo[arr.size()][sum];
    }
};