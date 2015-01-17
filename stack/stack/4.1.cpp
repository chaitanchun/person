#include "tree.h"
#include <math.h>

bool checkBalance(Node* top, int& height)
{
    int rHeight = 0;
    int lHeight = 0;
    bool rBalance = true;
    bool lBalance = true;
    if (top->left != nullptr)
        lBalance = checkBalance(top->left, lHeight);
    if (top->right != nullptr)
        rBalance = checkBalance(top->right, rHeight);
    if (lBalance && rBalance)
    {
        if (abs(lHeight - rHeight) > 1)
        {
            return false;
        }
        else
        {
            if (lHeight > rHeight)
                height = lHeight + 1;
            else
                height =  rHeight + 1;
            return true;
        }
    }
    else
        return false;
}
