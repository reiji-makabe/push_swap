/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_op_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:18:02 by rmakabe           #+#    #+#             */
/*   Updated: 2023/02/11 21:21:25 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "push_swap_utils.h"
#include "ft_stack.h"

void	ra(t_stack *a, t_list **op)
{
	rotate_stack(a);
	ft_lstadd_back(op, ft_lstnew("ra\n"));
}

void	rb(t_stack *b, t_list **op)
{
	rotate_stack(b);
	ft_lstadd_back(op, ft_lstnew("rb\n"));
}

void	rr(t_stack *a, t_stack *b, t_list **op)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_lstadd_back(op, ft_lstnew("rr\n"));
}

