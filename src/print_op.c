/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:48:45 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/09 18:15:58 by rmakabe          ###   ########.fr       */
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
static int	print_all(t_list *op, char *new);

int	print_op(t_list *op)
{
	int		flag;
	int		size;
	t_list	*edit;
	t_list	*old;
	char	*new;

	new = (char *)malloc(sizeof(char) * 8);
	if (new == NULL)
		return (0);
	flag = 1;
	while (flag)
	{
		flag = 0;
		size = ft_lstsize(op);
		edit = op->next;
		old = op;
		while (edit && edit->next)
		{
			flag = op_put_together(edit, new);
			if (!edit_ops(old, new, flag, &edit))
				old = old->next;
		}
		flag = (size != ft_lstsize(op));
	}
	return (print_all(op, new));
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

static int	op_put_together1(t_list *tmp, char *new)
{
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
	t_list	*connect;

	connect = old->next->next->next;
	if (flag == 1)
	{
		ft_strlcpy(old->next->content, new, 5);
		ft_lstdelone(old->next->next, free);
		old->next->next = connect;
		*edit = connect;
		return (1);
	}
	else if (flag == 2)
	{
		ft_lstdelone(old->next->next, free);
		ft_lstdelone(old->next, free);
		old->next = connect;
		*edit = connect;
		return (2);
	}
	else
		*edit = (*edit)->next;
	return (0);
}

static int	print_all(t_list *op, char *new)
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
	free(new);
	return (1);
}
