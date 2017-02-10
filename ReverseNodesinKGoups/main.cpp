#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||k==1)
            return head;
        ListNode*p,*q,*r,*start,*end,*before_start,*after_end,*result;
        int count;
        count=1;
        start=p=head;
        while(count<k&&p!=NULL)
        {
            p=p->next;
            count++;
        }
        if(count!=k||p==NULL)
            return head;
        end=p;
        after_end=end->next;
        p=start;
        q=after_end;
        while(p!=after_end)
        {
            r=p->next;
            p->next=q;
            q=p;
            p=r;
        }
        result=q;
        while(true)
        {
            before_start=start;
            start=p=after_end;
            if(start==NULL)
                break;
            else
                count=1;
            while(count<k&&p!=NULL)
            {
                p=p->next;
                count++;
            }
            if(count!=k||p==NULL)
                break;
            end=p;
            after_end=end->next;
            p=start;
            q=after_end;
            while(p!=after_end)
            {
                r=p->next;
                p->next=q;
                q=p;
                p=r;
            }
            before_start->next=end;
        }
        return result;
    }
};
int main() {
    Solution s;
    ListNode*head,*p;
    int k,val;
    while(true)
    {
        cin>>k;
        head=NULL;
        while(k--)
        {
            cin>>val;
            ListNode* pp=new ListNode(val);
            if(head==NULL)
            {
                head=p=pp;
            }else
            {
                p->next=pp;
                p=pp;
            }
        }
        cin>>k;
        p=head=s.reverseKGroup(head,k);
        while(p!=NULL)
        {
            cout<<p->val<<" ";
            head=head->next;
            free(p);
            p=head;
        }
        cout<<endl;
    }
    return 0;
}