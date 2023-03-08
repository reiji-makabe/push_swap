/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_radix_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:14:47 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/07 23:12:32 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "push_swap_utils.h"
#include "ft_stack.h"

static size_t	return_binary_digit(t_stack *a);

void	binary_radix_sort(t_stack *a, t_stack *b, t_list *op)
{
	size_t	size;
	size_t	digit;
	size_t	compare;

	digit = return_binary_digit(a);
	compare = 1;
	while (digit--)
	{
		size = stack_size(a);
		while (size--)
		{
			if (!(compare & a->next->rank))
				pb(a, b, &op);
			else
				ra(a, &op);
		}
		size = stack_size(b);
		while (size--)
			pa(a, b, &op);
		compare <<= 1;
	}
}

static size_t	return_binary_digit(t_stack *a)
{
	size_t	digit;
	size_t	size;
	size_t	tmp;

	tmp = 1;
	digit = 1;
	size = stack_size(a);
	while (tmp < size)
	{
		digit++;
		tmp <<= 1;
	}
	return (digit);
}
