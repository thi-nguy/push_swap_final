#include "push_swap.h"

void	move_when_size_b_is_small(t_push_swap *info, int position)
{
	int	b1;
	int	b2;

	if (info->size_b < 2)
	{
		if (position == 1)
			execute_command(info, SA);
		else if (position == 2)
			execute_command(info, RA);
		else
			execute_command(info, RRA);
	}
	else if (info->size_b == 2)
	{
		b1 = info->b_head->data;
		b2 = info->b_head->next->data;
		if (position == 1 && b1 < b2)
			execute_command(info, SS);
		else if (position == 1)
			execute_command(info, SA);
		else if (position == 2)
			execute_command(info, RA);
		else
			execute_command(info, RRA);
	}
}

void	move_when_size_b_is_big(t_push_swap *info, int position)
{
	int	b1;
	int	b2;
	int	b_end;

	b1 = info->b_head->data;
	b2 = info->b_head->next->data;
	b_end = info->b_end->data;
	if (position == 1 && b1 < b2)
		execute_command(info, SS);
	else if (position == 2 && b1 < b2 && b1 < b_end)
		execute_command(info, RR);
	else if (position == 1)
		execute_command(info, SA);
	else
		execute_command(info, RRA);
}

void	move_up_smaller_number(t_push_swap *info, int position)
{
	int	b1;
	int	b2;
	int	b_end;

	if (info->size_b < 2)
		move_when_size_b_is_small(info, position);
	else
		move_when_size_b_is_big(info, position);
}
