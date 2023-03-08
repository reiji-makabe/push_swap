/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:48:45 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/08 14:58:43 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "push_swap_utils.h"
#include "ft_stack.h"

static int	op_put_together(t_list *tmp, char *new);
static int	op_put_together1(t_list *tmp, char *new);
static int	edit_ops(t_list *old, char *new, int flag, t_list **edit);
static void	print_all(t_list *op);

int	print_op(t_list *op)
{
	int		flag;
	t_list	*edit;
	t_list	*old;
	char	*new;

	flag = 1;
	new = (char *)malloc(sizeof(char) * 8);
	if (new == NULL)
		return (0);
	while (flag)
	{
		flag = 0;
		edit = op->next;
		old = op;
		while (edit->next)
		{
			flag = op_put_together(edit, new);
			if (!edit_ops(old, new, flag, &edit))
				old = old->next;
		}
		if (!flag)
			print_all(op);
	}
	free(new);
	return (1);
}

static int	op_put_together(t_list *tmp, char *new)
{
	int		flag;
	char	*next;

	flag = 1;
	ft_strlcpy(new, "\n", 2);
	next = tmp->next->content;
	if (!ft_strcmp(tmp->content, "sa\n") && !ft_strcmp(next, "sb\n"))
		ft_strlcpy(new, "ss\n", 4);
	else if (!ft_strcmp(tmp->content, "ra\n") && !ft_strcmp(next, "rb\n"))
		ft_strlcpy(new, "rr\n", 4);
	else if (!ft_strcmp(tmp->content, "rra\n") && !ft_strcmp(next, "rrb\n"))
		ft_strlcpy(new, "rrr\n", 5);
	else if (!ft_strcmp(tmp->content, "ra\n") && !ft_strcmp(next, "rra\n"))
		flag = 2;
	else if (!ft_strcmp(tmp->content, "rb\n") && !ft_strcmp(next, "rrb\n"))
		flag = 2;
	else if (!ft_strcmp(tmp->content, "pa\n") && !ft_strcmp(next, "pb\n"))
		flag = 2;
	else if (!ft_strcmp(tmp->content, "sa\n") && !ft_strcmp(next, "sa\n"))
		flag = 2;
	else if (!ft_strcmp(tmp->content, "rb\n") && !ft_strcmp(next, "sb\n"))
		flag = 2;
	else
		flag = op_put_together1(tmp, new);
	return (flag);
}

static int	op_put_together1(t_list *tmp, char *new){
	int		flag;
	char	*next;

	flag = 1;
	next = tmp->next->content;
	if (!ft_strcmp(tmp->content, "sb\n") && !ft_strcmp(next, "sa\n"))
		ft_strlcpy(new, "ss\n", 4);
	else if (!ft_strcmp(tmp->content, "rb\n") && !ft_strcmp(next, "ra\n"))
		ft_strlcpy(new, "rr\n", 4);
	else if (!ft_strcmp(tmp->content, "rrb\n") && !ft_strcmp(next, "rra\n"))
		ft_strlcpy(new, "rrr\n", 5);
	else if (!ft_strcmp(tmp->content, "rra\n") && !ft_strcmp(next, "ra\n"))
		flag = 2;
	else if (!ft_strcmp(tmp->content, "rrb\n") && !ft_strcmp(next, "rb\n"))
		flag = 2;
	else if (!ft_strcmp(tmp->content, "pb\n") && !ft_strcmp(next, "pa\n"))
		flag = 2;
	else if (!ft_strcmp(tmp->content, "sb\n") && !ft_strcmp(next, "sb\n"))
		flag = 2;
	else if (!ft_strcmp(tmp->content, "sb\n") && !ft_strcmp(next, "rb\n"))
		flag = 2;
	else
		flag = 0;
	return (flag);
}

static int	edit_ops(t_list *old, char *new, int flag, t_list **edit)
{
	t_list	*now;
	t_list	*connect;

	now = old->next;
	connect = now->next->next;
	if (flag == 1)
	{
		ft_strlcpy(now->content, new, 5);
		ft_lstdelone(now->next, free);
		now->next = connect;
		*edit = connect;
		return (1);
	}
	else if (flag == 2)
	{
		ft_lstdelone(now->next, free);
		ft_lstdelone(now, free);
		old->next = connect;
		*edit = connect;
		return (2);
	}
	else
		*edit = (*edit)->next;
	return (0);
}

static void	print_all(t_list *op)
{
	size_t	size;
	t_list	*now;

	size = ft_lstsize(op) - 1;
	now = op->next;
	while (size--)
	{
		ft_printf("%s", now->content);
		now = now->next;
	}
}
