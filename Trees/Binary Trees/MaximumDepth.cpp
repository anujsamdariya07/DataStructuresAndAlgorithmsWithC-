// int maxDepth(TreeNode *root)
// {
//     if (root == NULL)
//         return 0;

//     int leftHeight = maxDepth(root->left);
//     int rightHeight = maxDepth(root->right);
//     int height = max(leftHeight, rightHeight) + 1;

//     return height;
// }