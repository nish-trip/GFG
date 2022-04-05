#include "test.h"

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        vector<int>ans;
        unordered_map<int,int>hash;
        for(int i=0; i<n; i++){
            hash[A[i]]++;
            if(i>=k-1){
                ans.push_back(hash.size());
                hash[A[i-k+1]]--;
                if(!hash[A[i-k+1]]){
                    hash.erase(A[i-k+1]);
                }
            }
        }
        return ans;
    }
};