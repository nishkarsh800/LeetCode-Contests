class Solution {
public:
    ListNode* removeNodes(ListNode* head) 
    {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* myNext= removeNodes(head->next);
        if(myNext->val > head->val) return myNext;
        
        head->next = myNext;
        
        return head;
    }
};