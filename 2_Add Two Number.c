/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *result = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = result;
    int remainder = 0;

    while(l1 != NULL || l2 != NULL || remainder != 0)
    {
        int sum = remainder;
        if (l1 != NULL) {
            sum += l1->val;  
            l1 = l1->next;   
        }
        
        if (l2 != NULL) {
            sum += l2->val;  
            l2 = l2->next;   
        }
        
        remainder = sum / 10;
        
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = sum % 10;  
        current->next = NULL;
    }
    
    struct ListNode* results = result->next;
    free(result);  
    return results;
}
