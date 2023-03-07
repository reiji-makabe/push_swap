/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 01:34:40 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/07 18:36:07 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "push_swap_utils.h"
#include "ft_stack.h"

static t_stack	*put_in_stack_and_add_coord_comp(int argc, char **argv);
static int		*char_a_to_int_a(char *char_a, size_t *size);
static int		*char_2d_a_to_int_a(int argc, char *argv[]);
static t_stack	*int_array_to_stack(int *split, int num);

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		error;

	error = 1;
	if (argc == 1)
		return (0);
	a = put_in_stack_and_add_coord_comp(argc, argv);
	if (a == NULL)
		push_swap_error();
	b = stack_create();
	if (b == NULL)
	{
		stack_clear(a);
		push_swap_error();
	}
	error = push_swap(a, b);
	stack_clear(a);
	stack_clear(b);
	if (!error)
		push_swap_error();
}

static t_stack	*put_in_stack_and_add_coord_comp(int argc, char **argv)
{
	int		*split;
	size_t	size;
	t_stack	*re;

	re = NULL;
	if (argc == 2)
		split = char_a_to_int_a(argv[1], &size);
	else
	{
		split = char_2d_a_to_int_a(argc - 1, argv + 1);
		size = argc - 1;
	}
	if ((split == NULL) || (split_check(split, size)))
	{
		free(split);
		return (NULL);
	}
	re = int_array_to_stack(split, size);
	if (re != NULL)
		coordinate_compress(re, split, size);
	free(split);
	return (re);
}

static int	*char_a_to_int_a(char *char_a, size_t *size)
{
	char	**char_2d;
	char	**tmp;
	int		*re;
	int		num;

	char_2d = ft_split(char_a, ' ');
	if (char_2d == NULL)
		return (NULL);
	tmp = char_2d;
	num = 0;
	while (*tmp++)
		num++;
	re = char_2d_a_to_int_a(num, char_2d);
	*size = num;
	free_2d_array(char_2d);
	return (re);
}

static int	*char_2d_a_to_int_a(int num, char **char_2d)
{
	char	*tmp;
	int		*re;
	int		flag;

	re = (int *)ft_calloc(num, sizeof(int));
	if (re == NULL)
		return (NULL);
	flag = 0;
	while (num--)
	{
		re[num] = ft_atoi(char_2d[num]);
		tmp = ft_itoa(re[num]);
		if ((ft_strlen(tmp) != ft_strlen(char_2d[num]))
			&& !ft_strncmp(tmp, char_2d[num], ft_strlen(tmp)))
			flag = 1;
		free(tmp);
		if (flag)
		{
			free(re);
			re = NULL;
			break ;
		}
	}
	return (re);
}

static t_stack	*int_array_to_stack(int *split, int num)
{
	t_stack	*re;

	re = stack_create();
	if (re == NULL)
		return (NULL);
	while (num--)
	{
		if (!stack_add_back(re, *split))

		{
			stack_clear(re);
			return (NULL);
		}
		split++;
	}
	return (re);
}
