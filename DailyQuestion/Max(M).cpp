int maxLevelSum(TreeNode* root) {
    if(!root) return 0;
    int MAX_SUM = INT_MIN;
    int maxLevel = 1;
    int currentLevel = 1;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int queueSize = q.size();
        long long queueSum = 0;

        for(int i = 0; i < queueSize; i++){
            TreeNode* temp = q.front();
            q.pop();
            queueSum += temp->val;

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }

        if(MAX_SUM < queueSum){
            MAX_SUM = queueSum;
            maxLevel = currentLevel;
        }

        currentLevel++;

    }

    return maxLevel;
}