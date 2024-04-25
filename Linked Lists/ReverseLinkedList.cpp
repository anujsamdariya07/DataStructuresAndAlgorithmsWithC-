// ListNode *reverseList(ListNode *head)
// {
//     ListNode *prev = NULL;
//     ListNode *curr = head;

//     while (curr != NULL)
//     {
//         ListNode *temp = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = temp;
//     }
//     head = prev;
//     return head;
// }

// Using recursion

// ListNode *reverseUsingRecursion(ListNode *prev, ListNode *curr)
// {
//     if (curr == NULL)
//     {
//         return prev;
//     }

//     ListNode *temp = curr->next;
//     curr->next = prev;
//     prev = curr;
//     curr = temp;

//     return reverseUsingRecursion(prev, curr);
// }
// ListNode *reverseList(ListNode *head)
// {
//     ListNode *prev = NULL;
//     ListNode *curr = head;
//     return reverseUsingRecursion(prev, curr);
// }