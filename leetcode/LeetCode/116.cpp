#include <iostream>

using namespace std;

 struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
public:
    void connect(TreeLinkNode *root) 
    {
        TreeLinkNode* current = root;
        do
        {
            TreeLinkNode* nextLevel = new TreeLinkNode(0);
            TreeLinkNode* np = nextLevel;
            TreeLinkNode* cp = current;
            while (cp != NULL)
            {
                if (cp->left != NULL)
                {
                    np->next = cp->left;
                    np = np->next;
                }
                if (cp->right != NULL)
                {
                    np->next = cp->right;
                    np = np->next;
                }
                cp = cp->next;
            }
            current = nextLevel->next;

        } while (current != NULL);
    }
};

int main()
{
    return 0;
}