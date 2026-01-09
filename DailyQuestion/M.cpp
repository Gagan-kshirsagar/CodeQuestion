public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return helper(root).second;
    }

private:
    pair<int, TreeNode*> helper(TreeNode* node) {
        if (!node) return {0, nullptr};

        pair<int, TreeNode*> left = helper(node->left);
        pair<int, TreeNode*> right = helper(node->right);

        int d1 = left.first;
        int d2 = right.first;
        
        if (d1 == d2) {
            return {d1 + 1, node};
        }
        else if (d1 > d2) {
            return {d1 + 1, left.second};
        }
        else {
            return {d2 + 1, right.second};
        }
    }