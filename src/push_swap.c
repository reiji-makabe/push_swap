/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:09:36 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/07 18:43:48 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "push_swap_utils.h"
#include "ft_stack.h"

static int	a_is_sorted(t_stack *a);
static void	sort_three_num(t_stack *a, t_list **op);

int	push_swap(t_stack *a, t_stack *b)
{
	int		a_size;
	int		re;
	t_list	*op;

	re = 0;
	op = ft_lstnew("sentinel\n");
	if (op != NULL)
	{
		if (a_is_sorted(a))
			return (0);
		a_size = stack_size(a);
		if (a_size == 2)
			ft_printf("ra\n");
		else if (a_size <= 3)
			sort_three_num(a, &op);
		else
			binary_radix_sort(a, b, op);
		re = print_op(op);
	}
	ft_lstclear(&op, free);
	return (re);
}

static int	a_is_sorted(t_stack *a)
{
	t_stack	*tmp_p;
	int		tmp_num;

	tmp_p = a->next;
	tmp_num = tmp_p->num;
	while (tmp_p != a)
	{
		if (tmp_num > tmp_p->num)
			return (1);
		tmp_p = tmp_p->next;
		tmp_num = tmp_p->num;
	}
	return (0);
}

/*
 * sort last three number
 * explain, argc=2, argv[1]="3 1 2", * a->prev->num = 2. a->prev->prev->num = 1.
 */
static void	sort_three_num(t_stack *a, t_list **op)
{
	if (a->prev->num > a->prev->prev->num)
	{
		if (a->prev->num > a->prev->prev->prev->num)
			sa(a, op);
		else
			ra(a, op);
	}
	else
	{
		if (a->prev->prev->num < a->prev->prev->prev->num)
		{
			sa(a, op);
			rra(a, op);
		}
		else
		{
			if (a->prev->num > a->prev->prev->prev->num)
			{
				sa(a, op);
				ra(a, op);
			}
			else
				rra(a, op);
		}
	}
}
/*
static int	get_median(t_stack *a, t_stack *b, int a_size)
{
	t_stack	*tmp_p;
	int		*array;
	int		tmp;

	array = (int *)ft_calloc(sizeof(int), a_size);
	if (array == NULL)
	{
		stack_clear(a);
		stack_clear(b);
		push_swap_error();
	}
	tmp = 0;
	tmp_p = a->next;
	while (tmp_p != a)
	{
		array[tmp++] = tmp_p->num;
		tmp_p = tmp_p->next;
	}
}
*/
