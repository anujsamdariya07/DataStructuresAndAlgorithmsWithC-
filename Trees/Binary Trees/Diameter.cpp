// int maxDepth(TreeNode *root)
// {
//     if (root == NULL)
//         return 0;

//     int leftHeight = maxDepth(root->left);
//     int rightHeight = maxDepth(root->right);
//     int height = max(leftHeight, rightHeight) + 1;

//     return height;
// }

// int diameterOfBinaryTree(TreeNode *root)
// {
//     if (root == NULL)
//         return 0;

//     int option1 = diameterOfBinaryTree(root->left);
//     int option2 = diameterOfBinaryTree(root->right);
//     int option3 = maxDepth(root->left) + maxDepth(root->right);
//     int diameter = max(option1, max(option2, option3));

//     return diameter;
// }