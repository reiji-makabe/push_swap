/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 01:42:39 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/07 18:41:56 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stddef.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				num;
	unsigned int	rank;
}					t_stack;

t_stack	*stack_create(void);
int		stack_add_back(t_stack *sentinel, int n);
size_t	stack_size(t_stack *sentinel);
void	stack_delone(t_stack *sentinel, t_stack *del);
void	stack_clear(t_stack *sentinel);

int	swap_last_two(t_stack *sentinel);
int	push_left_last_to_right(t_stack *left, t_stack *right);
int	rotate_stack(t_stack *sentinel);
int	reverse_rotate_stack(t_stack *sentinel);

#endif
