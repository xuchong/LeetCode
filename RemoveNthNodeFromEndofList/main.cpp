#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};
class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode*head,int n)
    {
        if(head==NULL)
            return head;
        ListNode* data=head;
        ListNode* p,*r;
        int i,total=0;
        while (data!=NULL)
        {
            total++;
            data=data->next;
        }
        data=head;
        if(total<n)
            return head;
        if(total==n)
            return head->next;
        for(i=1;i<total-n;i++)
        {
            data=data->next;
        }
        r=data->next;
        if(r!=NULL)
        {
            p=r->next;
            data->next=p;
            free(r);
        }
        return head;
    }
};
int main() {
    Solution s;
    int val;
    int n;
    ListNode* head,*p,*r;
    while(true)
    {
        cin>>n;
        p=head=NULL;
        while(n--)
        {
            cin>>val;
            ListNode* item=(ListNode*)malloc(sizeof(ListNode));
            item->val=val;
            item->next=NULL;
            if(head==NULL)
            {
                p=head=item;
            }else
            {
                p->next=item;
                p=p->next;
            }
        }
        cin>>n;
        p=s.removeNthFromEnd(head,n);
        while(p!=NULL)
        {
            cout<<p->val<<" ";
            r=p->next;
            free(p);
            p=r;
        }
        cout<<endl;
    }
    return 0;
}