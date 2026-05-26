#include "apc.h"

// Function definitions

//function to validate arguments
int cla_validation(int argc, char *argv[])
{ 
    //checking for no. of arguments
    if(argc != 4)
    { 
        printf("Invalid arguments\n");
        printf("INFO : Addition : ./a.out 124 + 12\n");
        printf("INFO : Substraction : ./a.out 123 - 111\n");
        printf("INFO : Multiplication : ./a.out 123 x 2\n");
        printf("INFO : Division : ./a.out 12 / 2\n");
        return FAILURE;
    } 

    //check first operand
    int i=0;
    if(argv[1][0] == '-')//allow negative sign
    {
        i=1;
    }

    //checking the 1st argument contains only digits
    for(; argv[1][i] != '\0'; i++)
    {
        if(!isdigit(argv[1][i]))
        {
            printf("PLEASE ENTER DIGITS ONLY\n");
            printf("INFO : ./a.out -12 + -12\n");
            return FAILURE;
        }
    }

    //check second operand
    i=0;
    if(argv[3][0] == '-')//allow negative sign
    {
        i=1;
    }

    //checking the 3rd argument contains only digits
    for(; argv[3][i] != '\0'; i++)
    {
        if(!isdigit(argv[3][i]))
        {
            printf("PLEASE ENTER DIGITS ONLY\n");
            printf("INFO : ./a.out -12 + -12\n");
            return FAILURE;
        }
    }
    return SUCCESS;
}

//creating list
void create_list(char *opr, node **head, node **tail)
{
    //traversing
    for(int i=0; opr[i] != '\0'; i++)
    {
        //insert_last function
        if(!insert_last(head, tail, opr[i] - '0'))
        {
            printf("Operation failed\n");
            return;
        }
    }
}

//insert node at first
int insert_first(node **head, node **tail, int data)
{
    //allocate the memory
    node *new = malloc(sizeof(node));

    if(!new)
    {
        return FAILURE;
    }

    new->data = data;//assign data
    new->prev = NULL;

    //if list is empty
    if(*head == NULL)
    {
        new->next = NULL;
        *head = new;//update head
        *tail = new;//update tail
    }
    else
    {
        new->next = *head;//link to new node
        (*head)->prev = new;
        *head = new;//update head
    }

    return SUCCESS;
}

//insert node at last
int insert_last(node **head, node **tail, int data)
{
    //allocate the memory
    node *new = malloc(sizeof(node));

    if(!new)
    {
        return FAILURE;
    }

    new->data = data;//assign data
    new->next = NULL;

    //if list is empty
    if(*head == NULL)
    {
        new->prev = NULL;
        *head = new;//update head
        *tail = new;//update tail
    }
    else
    {
        new->prev = *tail;//link with prevoius tail
        (*tail)->next = new;
        *tail = new;//update tail
    }

    return SUCCESS;
}

//delete entire list
int delete_list(node **head, node **tail)
{
    //check list empty or not
    if(*head == NULL)
    {
        return FAILURE;
    }

    node *temp = *head;

    //traverse and free nodes
    while(temp != NULL)
    {
        //take another pointer
        node *next = temp->next;
        free(temp);//free temp
        temp = next;
    }

    *head = NULL;//reset head
    *tail = NULL;//reset tail

    return SUCCESS;
}

//print linked list
void print_list(node *head)
{
    //checkin the list is empty or not
    if(head == NULL)
    {
        printf("INFO: List is empty\n");
    }
    else
    {
        while(head)
        {
            //printing the list
            printf("%d", head->data);

            //traverseing in forward direction
            head = head->next;
        }
        printf("\n");
    }
}

//remove extra zeros from list
void remove_pre_zeros(node **head)
{
    //checks empty or not
    if(*head == NULL)
    {
        return;
    }

    //start from head nodes
    node *temp = *head;

    //remove leading zeros
    while(temp->data == 0 && temp->next != NULL)
    {
        //store current zero node
        node *del = temp;
        temp = temp->next;//move to next node

        free(del);//free zero node
        temp->prev = NULL;//update prev pointer
    }

    *head = temp;//update head
}

//checks for the lenght for nodes
int list_len(node *head)
{
    int count = 0;

    //traverse to until reaching null
    while(head != NULL)
    {
        count++;//increment count
        head = head->next;//move to next
    }

    return count;
}

//compares two lists 
int compare_list(node *head1, node *head2) 
{ 
    int len1 = list_len(head1);//length of list1 
    int len2 = list_len(head2);//length of list2 
    
    //comparing list1 and list2 
    if(len1 > len2) 
    { 
        return 1; 
    } 
    else if(len1 < len2) 
    { 
        return -1; 
    } 
    
    //if length is equal compare digit by digit 
    while(head1 && head2) 
    { 
        if(head1->data > head2->data) 
        { 
            return 1; 
        } 
        else if(head1->data < head2->data) 
        { 
            return -1; 
        } 
        
        head1 = head1->next; 
        head2 = head2->next; 
    } 
    return SAME; 
}