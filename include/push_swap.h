/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 01:34:45 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/07 19:15:39 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <ft_stack.h>
# include "libft.h"

void	sa(t_stack *a, t_list **op);
void	sb(t_stack *b, t_list **op);
void	ss(t_stack *a, t_stack *b, t_list **op);
void	pa(t_stack *a, t_stack *b, t_list **op);
void	pb(t_stack *a, t_stack *b, t_list **op);
void	ra(t_stack *a, t_list **op);
void	rb(t_stack *b, t_list **op);
void	rr(t_stack *a, t_stack *b, t_list **op);
void	rra(t_stack *a, t_list **op);
void	rrb(t_stack *b, t_list **op);
void	rrr(t_stack *a, t_stack *b, t_list **op);
int		push_swap(t_stack *a, t_stack *b);
int		print_op(t_list	*op);

#endif
