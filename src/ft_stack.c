/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:28:10 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/07 18:33:39 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "push_swap.h"

t_stack	*stack_create(void)
{
	t_stack	*sentinel;

	sentinel = (t_stack *)malloc(sizeof(t_stack));
	if (sentinel == NULL)
		return (NULL);
	sentinel->next = sentinel;
	sentinel->prev = sentinel;
	sentinel->num = 0;
	sentinel->rank = 0;
	return (sentinel);
}

int	stack_add_back(t_stack *sentinel, int n)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (0);
	new->num = n;
	new->prev = sentinel->prev;
	new->next = sentinel;
	new->rank = 0;
	sentinel->prev->next = new;
	sentinel->prev = new;
	return (1);
}

size_t	stack_size(t_stack *sentinel)
{
	size_t	re;
	t_stack	*tmp;

	re = 0;
	tmp = sentinel->next;
	while (tmp != sentinel)
	{
		re++;
		tmp = tmp->next;
	}
	return (re);
}

void	stack_delone(t_stack *sentinel, t_stack *del)
{
	if (sentinel == del)
	{
		del->next->prev = del->prev;
		del->prev->next = del->next;
		free(del);
	}
}

void	stack_clear(t_stack *sentinel)
{
	t_stack	*del;
	t_stack	*tmp;

	del = sentinel->next;
	while (del != sentinel)
	{
		tmp = del->next;
		stack_delone(sentinel, del);
		del = tmp;
	}
}
