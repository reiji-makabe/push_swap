/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:40:38 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/01 01:01:17 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <limits.h>
# include "libft.h"
# include <stdarg.h>

int	ft_printf(const char *fmt, ...);
int	print_string(va_list *ap, char type);
int	print_pointer(size_t num_ptr);
int	print_decimal(long long num_int);
int	print_hex(unsigned int num_hex, char letter);

#endif
