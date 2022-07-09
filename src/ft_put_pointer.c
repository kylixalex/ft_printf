/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyalexan <kyalexan@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:42:06 by kyalexan          #+#    #+#             */
/*   Updated: 2022/07/09 17:19:08 by kyalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_convert_to_lowercase_hexadecimal.h"
#include "ft_get_hexadecimal_length.h"

static char	*ft_strcpy(char *destination, const char *source)
{
	int	string_indexer;

	string_indexer = 0;
	while (source[string_indexer])
	{
		destination[string_indexer] = source[string_indexer];
		string_indexer++;
	}
	destination[string_indexer] = '\0';
	return (destination);
}

int	ft_put_pointer(unsigned long int unsigned_long_integer)
{
	int		numeric_string_indexer;
	char	numeric_string[17];
	int		length;

	if (unsigned_long_integer == 0)
		return (write(STDOUT_FILENO, "(nil)", 5));
	numeric_string_indexer = 0;
	length = ft_get_hexadecimal_length(unsigned_long_integer);
	ft_strcpy(numeric_string, "0x");
	while (numeric_string_indexer < length)
	{
		numeric_string[length - numeric_string_indexer + 1] = \
			ft_convert_to_lowercase_hexadecimal(unsigned_long_integer % 16);
		unsigned_long_integer /= 16;
		numeric_string_indexer++;
	}
	return (write(STDOUT_FILENO, numeric_string, length + 2));
}
