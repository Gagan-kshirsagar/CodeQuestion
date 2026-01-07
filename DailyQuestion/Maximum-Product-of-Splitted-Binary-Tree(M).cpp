private:
    long long getTotalSum(TreeNode* root){
        if(!root){
            return 0;
        }
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    long long calculateMaxSubTreeSum(TreeNode* root){
        if(!root){
            return 0;
        }

        long long currentSubTreeSum = root->val + calculateMaxSubTreeSum(root->left) + calculateMaxSubTreeSum (root->right);

        long long remainingSum = totalSum - currentSubTreeSum;

        maxprod = max(maxprod, currentSubTreeSum * remainingSum);

        return currentSubTreeSum;

    }

public:
    long long totalSum = 0;
    long long maxprod = 0;
    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);
        calculateMaxSubTreeSum(root);
        return maxprod % 1000000007;
    }
    