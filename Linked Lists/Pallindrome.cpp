// ListNode *middleNode(ListNode *head)
// {
//     ListNode *slow = head;
//     ListNode *fast = head;

//     while (fast->next != NULL)
//     {
//         fast = fast->next;
//         if (fast->next != NULL)
//         {
//             fast = fast->next;
//             slow = slow->next;
//         }
//     }
//     return slow;
// }

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

// bool compareLL(ListNode *head, ListNode *head2)
// {
//     while (head2 != NULL)
//     {
//         if (head->val != head2->val)
//         {
//             return false;
//         }
//         else
//         {
//             head = head->next;
//             head2 = head2->next;
//         }
//     }
//     return true;
// }

// bool isPalindrome(ListNode *head)
// {
//     // Break into 2 halves
//     ListNode *midNode = middleNode(head);

//     ListNode *head2 = midNode->next;
//     midNode->next = NULL;

//     // Reverse 2nd list
//     ListNode *curr = head2;
//     ListNode *prev = NULL;
//     head2 = reverseUsingRecursion(prev, curr);

//     // Compare linked lists
//     bool answer = compareLL(head, head2);
//     return answer;
// }