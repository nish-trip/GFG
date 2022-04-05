#include "test.h"

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_set<int>s;
      for(int i=0; i<N; i++){
          s.insert(arr[i]);
      }
      int ans = 1;
      for(int i=0; i<N; i++){
          if(s.count(arr[i]-1)) continue;
          if(s.count(arr[i]+1)){
              int cur = 1;
              int num = arr[i];
              while(s.count(++num)){
                  cur++;
              }
              ans = max(ans, cur);
          }
      }
      return ans;
    }
};