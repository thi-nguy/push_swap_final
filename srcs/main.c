#include "push_swap.h"

int     main(int ac, char **av)
{
    int status;
    int input_array[ac - 1];
    t_push_swap     info;

    status = check_error(ac, av, input_array);
    if (status == 0 || check_ascending(input_array, ac - 1) == 1)
        return (0);
    else if (status == -1)
    {
         write(1, "Error\n", 6);;
         return (0);
    }
    else
    {
        ft_bzero(&info, sizeof(info));
        parse_info(&info, input_array, ac - 1);
        sort_algorithm(&info);
        print_operation_list(info.operation_list);
    }
    return (0);
}

