/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 02:34:14 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/04 20:38:28 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_stack.h"

void	selection_sort(int *split, int size);

void	push_swap_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	free_2d_array(char **re)
{
	int		index;

	if (re)
	{
		index = 0;
		while (re[index] != NULL)
			free(re[index++]);
		free(re);
		re = NULL;
	}
}

int	split_check(int *split, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (split[i] == split[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	coordinate_compress(t_stack *a, int *split, size_t size)
{
	t_stack				*tmp;
	unsigned int		rank;

	selection_sort(split, size);
	tmp = a->next;
	while (tmp != a)
	{
		rank = 0;
		while (split[rank] != tmp->num)
			rank++;
		tmp->rank = split[rank];
		tmp = tmp->next;
	}
}

void	selection_sort(int *split, int size)
{
	int		i;
	int		j;
	int		tmp;
	size_t	min_index;

	i = 0;
	while (i < size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (split[min_index] > split[j])
				min_index = j;
			j++;
		}
		tmp = split[i];
		split[i] = split[min_index];
		split[min_index] = tmp;
		i++;
	}
}
