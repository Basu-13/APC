#include "apc.h"

void multiplication(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *headR2 = NULL, *tailR2 = NULL;//temp result
    node *head_AR = NULL, *tail_AR = NULL;//addiition result

    //pointer for traversal
    node *temp1 = tail1, *temp2 = tail2;
    int count = 0; //position counting
    int carray = 0;
 
    //traverse 2nd number to last digit
    while(temp2 != NULL)
    {
        int num = temp2->data;
        temp1 = tail1;//reset first number pointer

        carray = 0;
        //adding prevoius partial result
        if(count != 0)
        {
            addition(*tailR, tailR2, &head_AR, &tail_AR);//adds two result
            delete_list(headR, tailR);//deltes old result
            delete_list(&headR2, &tailR2);//deltes temp result

            *headR = head_AR;//update head
            *tailR = tail_AR;//update tail

            //reset addition result
            head_AR = NULL;
            tail_AR = NULL;
        }

        //add zeros
        int pad = count;
        while(pad != 0)
        {
            //insert zeros at first
            insert_first(&headR2, &tailR2, 0);
            pad--;
        }

        //multiply each digits of 1st number
        while(temp1 != NULL)
        {
            int result = carray + temp1->data * num;//multiply and add carry
            if(result > 9)
            {
                carray = result / 10;//extract carry
                result %= 10;//keep single digit
            }
            else
            {
                carray = 0;//else no carry
            }

            if(count == 0)
            {
                //first iteration result
                insert_first(headR, tailR, result);
            }
            else
            {
                //temp result
                insert_first(&headR2, &tailR2, result);
            }

            temp1 = temp1->prev;//move to previous digit
        }

        //if carry remains insert it
        if(carray > 0)
        {
            if(count == 0)
                insert_first(headR, tailR, carray);//insert in main result
            else
                insert_first(&headR2, &tailR2, carray);//insert in temp result
            carray = 0;
        }
        count++;//increment count
        temp2 = temp2->prev;//moves to next digits of second number
    }


    //final addition if temp result exists
    if(*headR != NULL && headR2 != NULL)
    {
        addition(*tailR, tailR2, &head_AR, &tail_AR);//adds final result
        delete_list(headR, tailR);//deletes old result
        delete_list(&headR2, &tailR2);//deletes temp result

        *headR = head_AR;//update head
        *tailR = tail_AR;//update tail
    }
}