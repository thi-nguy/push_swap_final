#include "push_swap.h"

int     get_search_range(int size)
{
    //int range;

    //if (size < 300)
    //    range = 3;
    //else
    //    range = 5;
    //return (range);


    //int		size_tmp;
	//double	radius;

	//size_tmp = 100;
	//radius = 3;
	//while (size_tmp < size)
	//{
	//	size_tmp *= 2.24;
	//	radius++;
	//}
	//return (radius);

    return (3);
}

int     is_stack_increasing(t_stack *stack)
{
    int tmp;

    tmp = stack->data;
    stack = stack->next;
    while (stack != NULL)
    {

        if (tmp < stack->data)
        {
            tmp = stack->data;
            stack = stack->next;
        }
        else
            return (0);
    }
    //printf("Stack is increasing.\n");
    return (1);

}


