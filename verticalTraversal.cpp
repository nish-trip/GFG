#include "test.h"

class Solution{
public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int>ans;
        map<int,vector<int>>hash;
        queue<pair<int,Node*>>q;
        q.push(make_pair(0, root));
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto front = q.front();
                q.pop();
                int line = front.first;
                Node* node = front.second;
                hash[line].push_back(node->data);
                if(node->left){
                    q.push(make_pair(line-1, node->left));
                }
                if(node->right){
                    q.push(make_pair(line+1, node->right));
                }
            }
        }
        for(auto i: hash){
            vector<int>vec = i.second;
            for(int num: vec){
                ans.push_back(num);
            }
        }
        return ans;
    }
};