/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:

        int maxWidth(TreeNode *root)
        {
           	// Base case
            if (root == NULL)
                return 0;

           	// Initialize result
            long long result = 0;

           	// Do Level order traversal keeping track of number
           	// of nodes at every level.
            queue<pair<TreeNode*, long long>> q;	//{node,index}
            q.push({ root,
                0 });
            while (!q.empty())
            {
               	// Get the size of queue when the level order
               	// traversal for one level finishes
                long long count = q.size();

               	// Update the maximum node count value
                long long lIndx = q.front().second;
                long long rIndx = q.back().second;

                result = max(result, rIndx - lIndx + 1);

               	// Iterate for all the nodes in the queue currently
                while (count--)
                {
                   	// Dequeue an node from queue
                    pair<TreeNode*, long long > temp = q.front();
                    q.pop();

                   	// Enqueue left and right children of
                   	// dequeued node
                   	//left child index= 2*ind+1 and right : 2*index+2   
                    long long ind = temp.second - lIndx;
                    if (temp.first->left != NULL)
                    {
                        q.push({ temp.first->left,
                            2*ind+1ll });
                    }
                    if (temp.first->right != NULL)
                    {
                        q.push({ temp.first->right,
                            2*ind+2ll});
                    }
                }
            }

            return result;
        }

    int widthOfBinaryTree(TreeNode *root)
    {
        return maxWidth(root);
    }
};