/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b,
                                struct ListNode* list2) {
    struct ListNode *locA = list1, *locB = list1, *temp, *tail;
    
    // Find the node before the insertion point 'a'
    for (int i = 0; i < a - 1; i++) {
        locA = locA->next;
    }
    
    // Find the node at the end of the range 'b'
    for (int i = 0; i < b + 1; i++) {
        locB = locB->next;
    }
    
    // Connect the node before 'a' to the head of list2
    locA->next = list2;
    
    // Find the tail of list2
    tail = list2;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    
    // Connect the tail of list2 to the node after 'b'
    tail->next = locB;
    
    return list1;
}
