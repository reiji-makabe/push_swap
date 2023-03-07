/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 02:34:46 by rmakabe           #+#    #+#             */
/*   Updated: 2023/02/21 16:28:56 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

void	push_swap_error(void);
void	free_2d_array(char **re);
int		split_check(int *split, int size);
void	coordinate_compress(t_stack *a, int *split, size_t size);

#endif
