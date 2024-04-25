// int getLength(ListNode *head)
// {
//     ListNode *temp = head;
//     int length = 0;
//     while (temp != NULL)
//     {
//         temp = temp->next;
//         length++;
//     }
//     return length;
// }

// ListNode *middleNode(ListNode *head)
// {
    // Hare and Tortoise Method
    // ListNode *slow = head;
    // ListNode *fast = head;

    // while (fast != NULL)
    // {
    //     fast = fast->next;
    //     if (fast != NULL)
    //     {
    //         fast = fast->next;
    //         slow = slow->next;
    //     }
    // }
    // return slow;

    // Iterative approach 
//     // int length = getLength(head);

//     // ListNode* temp = head;
//     // int i = 1, position = length/2 + 1;
//     // while (i != position) {
//     //     temp = temp->next;i++;
//     // }
//     // return temp;
// }