/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_decimal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyalexan <kyalexan@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:42:14 by kyalexan          #+#    #+#             */
/*   Updated: 2022/07/09 17:09:28 by kyalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_get_unsigned_decimal_length(unsigned int unsigned_integer)
{
	int	length;

	length = 0;
	if (unsigned_integer == 0)
		return (1);
	while (unsigned_integer)
	{
		length++;
		unsigned_integer /= 10;
	}
	return (length);
}

int	ft_put_unsigned_decimal(unsigned int unsigned_integer)
{
	int		numeric_string_indexer;
	char	numeric_string[12];
	int		length;

	length = ft_get_unsigned_decimal_length(unsigned_integer);
	numeric_string_indexer = 0;
	while (numeric_string_indexer < length)
	{
		numeric_string[length - numeric_string_indexer - 1] = \
			unsigned_integer % 10 + '0';
		unsigned_integer /= 10;
		numeric_string_indexer++;
	}
	numeric_string[length] = '\0';
	return (write(STDOUT_FILENO, numeric_string, length));
}
