/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format_specifier.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyalexan <kyalexan@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:41:53 by kyalexan          #+#    #+#             */
/*   Updated: 2022/07/09 17:12:13 by kyalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "ft_put_lowercase_hexadecimal.h"
#include "ft_put_uppercase_hexadecimal.h"
#include "ft_put_unsigned_decimal.h"
#include "ft_put_signed_decimal.h"
#include "ft_put_pointer.h"
#include "ft_put_string.h"
#include "ft_put_char.h"

int	ft_handle_format_specifier(va_list argument_pointer, char format_specifier)
{
	if (format_specifier == 'c')
		return (ft_put_char(va_arg(argument_pointer, int)));
	else if (format_specifier == 's')
		return (ft_put_string(va_arg(argument_pointer, char *)));
	else if (format_specifier == 'd' || format_specifier == 'i')
		return (ft_put_signed_decimal(va_arg(argument_pointer, int)));
	else if (format_specifier == 'u')
		return (ft_put_unsigned_decimal(va_arg(argument_pointer,
					unsigned int)));
	else if (format_specifier == 'x')
		return (ft_put_lowercase_hexadecimal(va_arg(argument_pointer,
					unsigned int)));
	else if (format_specifier == 'X')
		return (ft_put_uppercase_hexadecimal(va_arg(argument_pointer,
					unsigned int)));
	else if (format_specifier == 'p')
		return (ft_put_pointer((unsigned long int) va_arg(argument_pointer,
					void *)));
	else if (format_specifier == '%')
		return (write(STDOUT_FILENO, "%", 1));
	return (0);
}
