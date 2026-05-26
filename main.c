/*NAME :- Basavaraj Pagad
Submission date :- 9/4/2026
Description :- The Arbitrary Precision Calculator (APC) is a software-based calculator designed to 
perform arithmetic operations on very large integers that cannot be handled using standard data 
types like int, long, or long long. This project uses dynamic memory allocation and linked list data 
structures to store and manipulate numbers of unlimited length, enabling high-precision computations.*/

#include "apc.h"

int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;
 
    // Validation
	if(cla_validation(argc, argv) == FAILURE)
	{
		return 0;
	}

	//+1 for positive and -1 for negative
	int sign1 = 1, sign2 = 1;

	//check sign of first number
	if(argv[1][0] == '-')
	{
		sign1 = -1;
		argv[1]++;
	}

	//check sign of second number
	if(argv[3][0] == '-')
	{
		sign2 = -1;
		argv[3]++;
	}
 
    // Create 2 lists of operands
	create_list(argv[1], &head1, &tail1);
	create_list(argv[3], &head2, &tail2);

    // Remove pre zeros
	remove_pre_zeros(&head1);
	remove_pre_zeros(&head2);

    char oper = argv[2][0];

    switch(oper)
    {

		case '+':
			printf("Output is -> ");
			if (sign1 == sign2)//Same sign → addition
			{
				addition(tail1, tail2, &headR, &tailR);//addition function

				if (sign1 == -1)//Result negative
					printf("-");
			}
			else//Different signs → subtraction
			{
				if (compare_list(head1, head2) >= 0)
				{
					subtraction(head1, tail1, head2, tail2, &headR, &tailR);//substraction function

					if (sign1 == -1)
						printf("-");
				}
				else
				{
					subtraction(head2, tail2, head1, tail1, &headR, &tailR);//substraction function

					if (sign2 == -1)
						printf("-");
				}
			}

			remove_pre_zeros(&headR);//removing zeros
			print_list(headR);//print output
			break;

		case '-':
			printf("Output is -> ");
			if (sign1 != sign2)//Different signs → addition
			{
				addition(tail1, tail2, &headR, &tailR);//addition function

				if (sign1 == -1)
					printf("-");
			}
			else//Same signs → subtraction
			{
				if (compare_list(head1, head2) >= 0)
				{
					subtraction(head1, tail1, head2, tail2, &headR, &tailR);//substraction function

					if (sign1 == -1)
						printf("-");
				}
				else
				{
					subtraction(head2, tail2, head1, tail1, &headR, &tailR);//substraction function

					if (sign1 == 1)
						printf("-");
				}
			}

			remove_pre_zeros(&headR);//removing zeros
			print_list(headR);//print output
			break;

		case 'x':
		case 'X':
			printf("Output is -> ");
			multiplication(tail1, tail2, &headR, &tailR);//multiplication function

			if(sign1 != sign2)
			{
				printf("-");
			}
			
			remove_pre_zeros(&headR);//removing zeros
			print_list(headR);//print output
			break;

		case '/':
			printf("Output is -> ");
			division(head1, head2, &headR, &tailR);//dividion function

			if(sign1 != sign2)
			{
				printf("-");
			}

			remove_pre_zeros(&headR);//removing zeros
			print_list(headR);//print output
			break;

		default:
			printf("Invalid operator\n");
    }
}

