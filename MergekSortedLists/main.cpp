#include <iostream>
#include<vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct NewNode
{
    int val;
    ListNode* ln;
    NewNode(int val):val(val),ln(NULL)
    {

    }
    bool operator<(const NewNode& other)const
    {
        return val<other.val;
    }
    bool operator>(const NewNode& other)const
    {
        return val>other.val;
    }
};
/**
 * # No.1:  Heap Sort
 * # No.2:  归并排序
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=NULL,*r;
        if(lists.size()==0)
            return head;
        vector<NewNode> heap;
        heap.clear();
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=NULL) {
                NewNode item(lists[i]->val);
                item.ln = lists[i];
                heap.push_back(item);
            }
        }
        if(heap.size()==0)
            return head;
        make_heap(heap.begin(),heap.end(),greater<NewNode>());
        ListNode *p;
        pop_heap(heap.begin(),heap.end(),greater<NewNode>());
        NewNode first=heap.back();
        head=p=first.ln;
        heap.pop_back();
        if(p->next!=NULL)
        {
            first.ln=first.ln->next;
            first.val=first.ln->val;
            heap.push_back(first);
            push_heap(heap.begin(),heap.end(),greater<NewNode>());
        }
        while(heap.size()>0)
        {
            pop_heap(heap.begin(),heap.end(),greater<NewNode>());
            first=heap.back();
            p->next=first.ln;
            p=p->next;
            heap.pop_back();
            if(p->next!=NULL)
            {
                first.ln=first.ln->next;
                first.val=first.ln->val;
                heap.push_back(first);
                push_heap(heap.begin(),heap.end(),greater<NewNode>());
            }
        }
        return head;
    }
};
void pushList(vector<ListNode*>& input,ListNode a[4],int n)
{
    ListNode* list=NULL,*p;
    for(int i=0;i<n;i++)
    {
        if(list==NULL)
        {
            list=p=&a[i];
        } else
        {
            p->next=&a[i];
            p=p->next;
        }
    }
    p->next=NULL;
    input.push_back(list);
}
int main() {
    ListNode b[1]={0};
    ListNode a[1]={1};
    vector<ListNode*> input;

    pushList(input,a,1);
    pushList(input,b,1);

    Solution s;
    ListNode* result=s.mergeKLists(input);
    ListNode *p;
    p=result;
    while (p!=NULL)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
    return 0;
}