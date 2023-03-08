/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:31:00 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/07 21:49:46 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "push_swap_utils.h"
#include "ft_stack.h"

void	sa(t_stack *a, t_list **op)
{
	swap_last_two(a);
	ft_lstadd_back(op, ft_lstnew("sa\n"));
}

void	sb(t_stack *b, t_list **op)
{
	swap_last_two(b);
	ft_lstadd_back(op, ft_lstnew("sb\n"));
}

void	ss(t_stack *a, t_stack *b, t_list **op)
{
	swap_last_two(a);
	swap_last_two(b);
	ft_lstadd_back(op, ft_lstnew("ss\n"));
}

void	pa(t_stack *a, t_stack *b, t_list **op)
{
	push_left_front_to_right(b, a);
	ft_lstadd_back(op, ft_lstnew("pa\n"));
}

void	pb(t_stack *a, t_stack *b, t_list **op)
{
	push_left_front_to_right(a, b);
	ft_lstadd_back(op, ft_lstnew("pb\n"));
}
