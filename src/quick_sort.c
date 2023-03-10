/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:08:10 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/10 00:12:39 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "push_swap_utils.h"
#include "ft_stack.h"

static void	move_less_half(t_stack *a, t_stack *b, t_stack *tmp, t_list *op);

void	quick_sort(t_stack *a, t_stack *b, t_list *op)
{
	t_stack	*tmp;
	size_t	rank;
	size_t	i;

	rank = stack_size(a) - 4;
	i = 0;
	while (i++ <= rank)
	{
		tmp = a->next;
		while (tmp->rank != i - 1)
			tmp = tmp->next;
		move_less_half(a, b, tmp, op);
	}
	if (!a_is_sorted(a))
		sort_three_num(a, &op);
	i = 0;
	rank = stack_size(b);
	while (i++ < rank)
		pa(a, b, &op);
}

static void	move_less_half(t_stack *a, t_stack *b, t_stack *tmp, t_list *op)
{
	size_t	size;
	size_t	pos;
	t_stack	*now;

	size = stack_size(a);
	now = a->next;
	pos = 0;
	while (now != tmp)
	{
		pos++;
		now = now->next;
	}
	if (pos + 1 <= (size + 1) / 2)
	{
		while (pos--)
			ra(a, &op);
	}
	else
	{
		pos = stack_size(a) - pos;
		while (pos--)
			rra(a, &op);
	}
	pb(a, b, &op);
}
