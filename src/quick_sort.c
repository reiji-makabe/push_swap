/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:08:10 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/09 08:11:40 by rmakabe          ###   ########.fr       */
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

	rank = stack_size(a) / 2;
	i = 0;
	tmp = a->next;
	while (i++ < rank)
	{
		if (tmp->rank == i - 1)
			move_less_half(a, b, tmp, op);
		tmp = tmp->next;
	}
	sort_three_num(a, &op);
	i = 0;
	while (i++ < stack_size(b))
		pa(a, b, &op);
	print_op(op);
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
		pos++;
	if (pos + 1 <= (size + 1) / 2)
	{
		while (pos--)
			ra(a, &op);
	}
	pb(a, b, &op);
}
