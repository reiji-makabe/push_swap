/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 02:34:46 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/09 07:26:21 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

void	push_swap_error(void);
void	free_2d_array(char **re);
int		split_check(int *split, int size);
void	coordinate_compress(t_stack *a, int *split, size_t size);
void	binary_radix_sort(t_stack *a, t_stack *b, t_list *op);
void	sort_three_num(t_stack *a, t_list **op);
void	quick_sort(t_stack *a, t_stack *b, t_list *op);

#endif
