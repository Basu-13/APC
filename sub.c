#include "apc.h"

void subtraction(node *head1, node *tail1, node *head2, node *tail2, node **headR, node **tailR)
{
    int borrow = 0;//to store borrow value

    *headR = NULL;//initialize result head
    *tailR = NULL;//initialize result tail

    //traverse to last digit
    while(tail1 != NULL || tail2 != NULL)
    {
        int digit1 = (tail1) ? tail1->data : 0;//get digit from first number
        int digit2 = (tail2) ? tail2->data : 0;//get digit from second number

        int diff = digit1 - digit2 - borrow;//performs substraction

        //if result is negative
        if(diff < 0)
        {
            diff = diff + 10;//extract carry
            borrow = 1;//set borrow for next digit
        }
        else
        {
            borrow = 0;//else no borrow
        }

        //store result at first
        insert_first(headR, tailR, diff);

        //moves to previous digit in number1
        if(tail1)
            tail1 = tail1->prev;
        
        //moves to previous digit in number2
        if(tail2)
            tail2 = tail2->prev;
    }
    remove_pre_zeros(headR);
} 
