/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_signed_decimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyalexan <kyalexan@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:42:09 by kyalexan          #+#    #+#             */
/*   Updated: 2022/07/09 17:10:03 by kyalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

static int	ft_get_signed_decimal_length(int signed_integer)
{
	int	length;

	length = 0;
	if (signed_integer == 0)
		return (1);
	if (signed_integer < 0)
		length++;
	while (signed_integer)
	{
		length++;
		signed_integer /= 10;
	}
	return (length);
}

int	ft_put_signed_decimal(int signed_integer)
{
	int		numeric_string_indexer;
	char	numeric_string[13];
	int		length;
	int		offset;

	if (signed_integer == INT_MIN)
		return (write(STDOUT_FILENO, "-2147483648", 11));
	length = ft_get_signed_decimal_length(signed_integer);
	numeric_string_indexer = 0;
	offset = 0;
	if (signed_integer < 0)
	{
		numeric_string[0] = '-';
		signed_integer *= -1;
		offset = 1;
	}
	while (numeric_string_indexer < length - offset)
	{
		numeric_string[length - numeric_string_indexer - 1] = \
			signed_integer % 10 + '0';
		signed_integer /= 10;
		numeric_string_indexer++;
	}
	numeric_string[length] = '\0';
	return (write(STDOUT_FILENO, numeric_string, length));
}
