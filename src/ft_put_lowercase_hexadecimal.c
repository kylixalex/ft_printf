/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_lowercase_hexadecimal.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyalexan <kyalexan@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:42:01 by kyalexan          #+#    #+#             */
/*   Updated: 2022/07/09 17:14:49 by kyalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_convert_to_lowercase_hexadecimal.h"
#include "ft_get_hexadecimal_length.h"

int	ft_put_lowercase_hexadecimal(unsigned int unsigned_integer)
{
	int		numeric_string_indexer;
	char	numeric_string[8];
	int		length;

	length = ft_get_hexadecimal_length(unsigned_integer);
	numeric_string_indexer = 0;
	while (numeric_string_indexer < length)
	{
		numeric_string[length - numeric_string_indexer - 1] = \
			ft_convert_to_lowercase_hexadecimal(unsigned_integer % 16);
		unsigned_integer /= 16;
		numeric_string_indexer++;
	}
	numeric_string[length] = '\0';
	return (write(STDOUT_FILENO, numeric_string, length));
}
