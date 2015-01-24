#include <iostream>
#include <vector>
using namespace std;
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(ListNode* f, ListNode* s)
{
    ListNode* ret;
    if (f == NULL || s == NULL)
    {
        if (s == NULL)
            ret = f;
        else
            ret = s;
        return ret;
    }
    if (f->val > s->val)
    {
        ret = s;
        s = s->next;
    }
    else
    {
        ret = f;
        f = f->next;
    }
    ListNode* it = ret;
    while (f != NULL && s != NULL)
    {
        if (f->val < s->val)
        {
            it->next = f;
            f = f->next;
            it = it->next;
        }
        else
        {
            it->next = s;
            s = s->next;
            it = it->next;
        }
    }
    if (f != NULL)
        it->next = f;
    if (s != NULL)
        it->next = s;
    return ret;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode* ret = NULL;
    if (lists.size() > 2)
    {
        vector<ListNode*> firstPart(lists.size() / 2);
        copy(lists.begin(), lists.begin() + lists.size() / 2, firstPart.begin());
        vector<ListNode*> secondPart(lists.size() - lists.size() / 2);
        copy(lists.begin() + lists.size() / 2, lists.end(), secondPart.begin());
        ListNode* first = mergeKLists(firstPart);
        ListNode* second = mergeKLists(secondPart);
        ret = merge(first, second);
    }
    else if (lists.size() == 1)
    {
        ret = lists[0];
    }
    else if (lists.size() == 2)
    {
        ret = merge(lists[0], lists[1]);
    }
    return ret;
}

int main()
{
    vector<ListNode*> list;
    ListNode* l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(2);
    list.push_back(l);
    l = new ListNode(1);
    l->next = new ListNode(1);
    l->next->next = new ListNode(2);
    list.push_back(l);
    l = mergeKLists(list);
    return 0;
}