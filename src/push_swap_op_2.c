/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacl_op_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:21:46 by rmakabe           #+#    #+#             */
/*   Updated: 2023/02/11 21:23:38 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "push_swap_utils.h"
#include "ft_stack.h"

void	rra(t_stack *a, t_list **op)
{
	reverse_rotate_stack(a);
	ft_lstadd_back(op, ft_lstnew("rra\n"));
}

void	rrb(t_stack *b, t_list **op)
{
	reverse_rotate_stack(b);
	ft_lstadd_back(op, ft_lstnew("rrb\n"));
}

void	rrr(t_stack *a, t_stack *b, t_list **op)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	ft_lstadd_back(op, ft_lstnew("rrr\n"));
}
