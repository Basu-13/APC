#include "apc.h"

void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    int carry = 0;   
 
    // loop until both lists end and no carry remains
    while (tail1 != NULL || tail2 != NULL || carry != 0)
    {
        int digit1 = 0, digit2 = 0;   

        if (tail1 != NULL)  // check if first number has digits
        {
            digit1 = tail1->data;  // get digit from first list
            tail1 = tail1->prev;   // move to previous node
        }

        if (tail2 != NULL)  // check if second number has digits
        {
            digit2 = tail2->data;  // get digit from second list
            tail2 = tail2->prev;   // move to previous node
        }

        int sum = digit1 + digit2 + carry;  // add digits and carry

        int result_digit = sum % 10;  // extract last digit of sum
        carry = sum / 10;             // update carry

        // create new node for result digit
        node *new = malloc(sizeof(node));

        new->data = result_digit;  // store result digit
        new->prev = NULL;          // initialize prev pointer
        new->next = NULL;          // initialize next pointer

        // insert node at beginning of result list
        if (*headR == NULL)
        {
            *headR = *tailR = new;  // first node becomes head and tail
        }
        else
        {
            new->next = *headR;     // link new node to current head
            (*headR)->prev = new;   // update previous pointer of head
            *headR = new;           // update head to new node
        }
    }
}