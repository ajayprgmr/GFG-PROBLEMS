// Given the root of a n-ary tree find the number of duplicate subtrees in the n-ary tree. Two trees are duplicates if they have the same structure with the same node values.
// Expected Time Complexity: O(n), n is the total no of nodes
//Expected Space Complexity: O(n2)


//optimal solution code 
class Solution{
public:
    int duplicateSubtreeNaryTree(Node *root){
        map<vector<int>, int> f;
        
        function<vector<int>(Node *)> dfs = [&](Node * node) -> vector<int> {
            vector<int> current = { node -> data, -1 };
            
            for(auto child : node -> children){
                vector<int> next = dfs(child);
                for(auto i : next)
                    current.push_back(i);
            }
            
            current.push_back(-1);
            
            ++f[current];
            
            return current;
        };
        
        dfs(root);
        int ans = 0;
        
        for(auto i : f){
            ans += i.second > 1;
        }
            
        return ans;
    }
};