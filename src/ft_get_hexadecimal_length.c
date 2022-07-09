/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hexadecimal_length.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyalexan <kyalexan@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:41:50 by kyalexan          #+#    #+#             */
/*   Updated: 2022/07/09 17:17:42 by kyalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_hexadecimal_length(unsigned long int unsigned_long_integer)
{
	int	length;

	length = 0;
	if (unsigned_long_integer == 0)
		return (1);
	while (unsigned_long_integer)
	{
		length++;
		unsigned_long_integer /= 16;
	}
	return (length);
}
