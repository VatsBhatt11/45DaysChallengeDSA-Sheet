/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1,s2;
        ListNode* t1=l1,*t2=l2;
        while(t1)
        {
            s1.push(t1->val);
            t1=t1->next;
        }
        while(t2)
        {
            s2.push(t2->val);
            t2=t2->next;
        }
        int carry=0;
        ListNode* result=NULL;
        while(!s1.empty() || !s2.empty())
        {
            int a=0,b=0;
            if(!s1.empty())
            {
                a=s1.top();
                s1.pop();
            }
            if(!s2.empty())
            {
                b=s2.top();
                s2.pop();
            }
            int total=a+b+carry;
            ListNode* temp=new ListNode(total%10);
            carry=total/10;
            if(!result)
                result=temp;
            else
            {
                temp->next=result;
                result=temp;
            }
        }
        if(carry!=0)
        {
            ListNode* temp=new ListNode(carry);
            temp->next=result;
            result=temp;
        }
        return result;
    }
};