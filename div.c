#include "apc.h"

//helper function to get tail(last node)
node *get_tail(node *head)
{
    //checks if empty or not
    if (head == NULL)
        return NULL;

    //traverse until last node
    while (head->next != NULL)
        head = head->next;//move to next node
 
    return head;//returns the last node
}

void division(node *head1, node *head2, node **headR, node **tailR)
{
    //Temporary list to store partial dividend
    node *temp_head = NULL;             
    node *temp_tail = NULL;

    node *cur = head1;//Pointer to traverse dividend
    node *tail2 = get_tail(head2);//Get tail of divisor for subtraction

    *headR = NULL;//Initialize quotient head
    *tailR = NULL;//Initialize quotient tail

    //Check for division by zero
    if (head2 == NULL || (head2->data == 0 && head2->next == NULL))
    {
        printf("Error: Division by zero is not possible\n"); 
        return;
    }

    //Traverse each digit of dividend
    while (cur != NULL)
    {
        //Append current digit to temp
        insert_last(&temp_head, &temp_tail, cur->data);   

        //Remove leading zeros in temp
        remove_pre_zeros(&temp_head);

        //If temp < divisor, quotient digit is 0
        if (compare_list(temp_head, head2) < 0)
        {
            insert_last(headR, tailR, 0);//Add 0 to quotient
        }
        else
        {
            int count = 0;//To store quotient digit

            //Repeat subtraction until temp < divisor
            while (compare_list(temp_head, head2) >= 0)
            {
                node *res_head = NULL;//Head of subtraction result
                node *res_tail = NULL;//Tail of subtraction result

                //Perform temp = temp - divisor
                subtraction(temp_head, temp_tail, head2, tail2, &res_head, &res_tail);

                //Delete old temp list
                delete_list(&temp_head, &temp_tail);      

                //Update temp with new result
                temp_head = res_head;                     
                temp_tail = res_tail;

                count++;//Increment quotient digit
            }

            //Store quotient digit
            insert_last(headR, tailR, count);             
        }

        cur = cur->next;//Move to next digit of dividend
    }

    remove_pre_zeros(headR);//Remove leading zeros in quotient

    delete_list(&temp_head, &temp_tail);//Free temporary list memory
}