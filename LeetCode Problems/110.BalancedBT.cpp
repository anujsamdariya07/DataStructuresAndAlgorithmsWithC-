// int height(TreeNode *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     int leftHeight = height(root->left);
//     int rightHeight = height(root->right);
//     int height = max(leftHeight, rightHeight) + 1;
//     return height;
// }

// bool isBalanced(TreeNode *root)
// {
//     if (root == NULL)
//     {
//         return true;
//     }

//     // Solve current node
//     int leftHeight = height(root->left);
//     int rightHeight = height(root->right);
//     int diff = abs(leftHeight - rightHeight);

//     bool currAns = (diff <= 1);

//     bool leftAns = isBalanced(root->left);
//     bool rightAns = isBalanced(root->right);

//     if (currAns && leftAns && rightAns)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }