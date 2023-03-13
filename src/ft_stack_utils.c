/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 05:02:40 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/14 00:00:31 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "push_swap_utils.h"
#include "ft_stack.h"

/*
 1. next change
 2. prev change (information is destroyed. tmp is necessary.)
*/

int	swap_last_two(t_stack *sentinel)
{
	t_stack	*swap_1;
	t_stack	*swap_2;

	if (stack_size(sentinel) <= 1)
		return (0);
	swap_1 = sentinel->next;
	swap_2 = sentinel->next->next;
	sentinel->next = swap_2;
	swap_1->next = swap_2->next;
	swap_1->prev = swap_2;
	swap_2->next = swap_1;
	swap_2->prev = sentinel;
	return (1);
}
/*
int	push_left_last_to_right(t_stack *left, t_stack *right)
{
	t_stack *push;

	if (stack_size(left) <= 0)
		return (0);
	push = left->prev;
	push->prev->next = left;
	left->prev = left->prev->prev;
	push->prev = right->prev;
	push->next = right;
	right->prev->next = push;
	right->prev = push;
	return (1);
}
*/

int	push_left_front_to_right(t_stack *left, t_stack *right)
{
	t_stack	*push;

	if (stack_size(left) <= 0)
		return (0);
	push = left->next;
	push->next->prev = left;
	left->next = push->next;
	push->prev = right;
	push->next = right->next;
	right->next->prev = push;
	right->next = push;
	return (1);
}

int	rotate_stack(t_stack *sentinel)
{
	t_stack	*head;
	t_stack	*last;

	if (stack_size(sentinel) <= 1)
		return (0);
	head = sentinel->next;
	last = sentinel->prev;
	head->next->prev = sentinel;
	sentinel->next = head->next;
	sentinel->prev = head;
	last->next = head;
	head->next = sentinel;
	head->prev = last;
	return (1);
}

int	reverse_rotate_stack(t_stack *sentinel)
{
	t_stack	*head;
	t_stack	*last;

	if (stack_size(sentinel) <= 1)
		return (0);
	head = sentinel->next;
	last = sentinel->prev;
	last->prev->next = sentinel;
	sentinel->prev = last->prev;
	sentinel->next = last;
	head->prev = last;
	last->next = head;
	last->prev = sentinel;
	return (1);
}
