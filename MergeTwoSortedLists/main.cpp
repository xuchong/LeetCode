#include <iostream>
using namespace std;

struct ListNode {
   int val;
   ListNode* next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode*p,*q,*r,*result;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        p=l1;
        q=l2;
        if(p->val<q->val)
        {
            result=r=p;
            p=p->next;
        } else {
            result=r=q;
            q=q->next;
        }
        while (p!=NULL&&q!=NULL)
        {
            if(p->val<q->val)
            {
                r->next=p;
                r=p;
                p=p->next;
            } else
            {
                r->next=q;
                r=q;
                q=q->next;
            }
        }
        if(p==NULL)
        {
            while(q!=NULL)
            {
                r->next=q;
                r=q;
                q=q->next;
            }
        }else
        {
            while(p!=NULL)
            {
                r->next=p;
                r=p;
                p=p->next;
            }
        }
        return result;
    }
};
int main() {
    Solution s;
    ListNode* l1,*l2,*p,*q;
    int n;
    int val;
    while (true)
    {
        cin>>n;
        while (n--)
        {
            ListNode* item=(ListNode*)malloc(sizeof(ListNode));
            cin>>val;
            item->val=val;
            item->next=NULL;
            if(l1==NULL)
            {
                l1=p=item;
            } else
            {
                p->next=item;
                p=p->next;
            }
        }
        cin>>n;
        while (n--)
        {
            ListNode* item=(ListNode*)malloc(sizeof(ListNode));
            cin>>val;
            item->val=val;
            item->next=NULL;
            if(l2==NULL)
            {
                l2=q=item;
            } else
            {
                q->next=item;
                q=q->next;
            }
        }
        p=s.mergeTwoLists(l1,l2);
        while(p!=NULL)
        {
            cout<<p->val<<" ";
            q=p->next;
            free(p);
            p=q;
        }
        cout<<endl;
    }
    return 0;
}