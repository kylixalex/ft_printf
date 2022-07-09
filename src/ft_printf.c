/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyalexan <kyalexan@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:41:56 by kyalexan          #+#    #+#             */
/*   Updated: 2022/07/09 17:11:06 by kyalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "ft_handle_format_specifier.h"
#include "ft_strlen.h"

static char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return ((char *) s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) s + i);
		i++;
	}
	return (NULL);
}

int	ft_printf(const char *format, ...)
{
	va_list	argument_pointer;
	int		format_indexer;
	int		bytes_written;

	va_start(argument_pointer, format);
	format_indexer = 0;
	bytes_written = 0;
	while (format[format_indexer])
	{
		if (format[format_indexer] == '%')
		{
			if (ft_strchr("csidupxX%", format[format_indexer + 1]))
				bytes_written += ft_handle_format_specifier(argument_pointer,
						format[++format_indexer]);
		}
		else
			bytes_written += write(STDOUT_FILENO, &format[format_indexer], 1);
		format_indexer++;
	}
	va_end(argument_pointer);
	return (bytes_written);
}
