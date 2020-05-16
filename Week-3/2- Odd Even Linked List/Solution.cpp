
// Created on 16 May, 2020

// Title : Odd Even Linked List

// Author : Shiwangi Garg

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return head;
        }
        ListNode *odd,*even,*oddTail,*evenTail;
        odd = head;
        even = head->next;
        oddTail = odd;
        evenTail = even;
        int i = 1;
        while(oddTail->next != NULL && evenTail != NULL){
            if(i%2 == 1){
                if(evenTail->next != NULL){
                    oddTail->next = evenTail->next;
                    oddTail = oddTail->next;
                }else{
                    oddTail->next = NULL;
                }
            }else{
                evenTail->next = oddTail->next;
                evenTail = evenTail->next;
            }
            i++;
        }
        evenTail->next = NULL;
        oddTail->next = even;
        return odd;
    }
};
