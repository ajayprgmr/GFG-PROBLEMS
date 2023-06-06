// C++ Solution
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        pre = floor(root, key);
        suc = ceil(root, key);
    }
    

    Node* ceil(Node* root, int x)
    {
        Node* res = nullptr;
        while (root != nullptr) {
            if (root->key > x) {
                res = root;
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        return res;
    }

Node* floor(Node* root, int x)
{
    Node* res = nullptr;
    while (root != nullptr) {
        if (root->key >= x) {
            root = root->left;
        }
        else {
            res = root;
            root = root->right;
        }
    }
    return res;
}

};
