class Solution {
public:
    int ans = 0;

    // returns {sum of subtree, number of nodes in subtree}
    pair<int, int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        auto [leftSum, leftCount] = dfs(root->left);
        auto [rightSum, rightCount] = dfs(root->right);

        int sum = leftSum + rightSum + root->val;
        int count = leftCount + rightCount + 1;

        // Integer division automatically rounds down
        if (root->val == sum / count) {
            ans++;
        }

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
