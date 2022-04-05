#include "test.h"

class Solution{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<int>st;
        vector<long long>ans(arr.size(),-1);
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[i] > arr[st.top()]){
                int index = st.top();
                st.pop();
                ans[index] = arr[i];
            }
            st.push(i);
        }
        return ans;
    }
};