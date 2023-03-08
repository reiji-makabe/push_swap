/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:48:45 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/08 00:23:29 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "push_swap_utils.h"
#include "ft_stack.h"

static int	op_put_together(t_list *tmp, char *new);
static int	op_put_together1(t_list *tmp, char *new);
//static void	edit_ops(t_list *old, char *new, int flag);
static void	print_all(t_list *op);

int	print_op(t_list *op)
{
	int		size;
	int		flag;
	t_list	*tmp;
	char	*new;

	tmp = op;
	flag = 1;
	new = (char *)malloc(sizeof(char) * 8);
	if (new == NULL)
		return (0);
	while (flag)
	{
		flag = 0;
		size = ft_lstsize(tmp) - 2;
		while (size--)
		{
			flag = op_put_together(tmp->next, new);
//			edit_ops(tmp, new, flag);
			tmp = tmp->next;
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

//static void	edit_ops(t_list *old, char *new, int flag)
//{
//	t_list	*now;
//	t_list	*next;
//
//	now = old->next;
//	next = now->next;
//	if (flag == 1)
//	{
//		now->content = new;
//		ft_lstdelone(now->next, free);
//		now->next = next;
//	}
//	else if (flag == 2)
//	{
//		ft_lstdelone(now->next, free);
//		ft_lstdelone(now, free);
//		old->next = next;
//	}
//}

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
