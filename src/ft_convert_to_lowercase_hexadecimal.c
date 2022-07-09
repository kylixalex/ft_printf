/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_lowercase_hexadecimal.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyalexan <kyalexan@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:41:44 by kyalexan          #+#    #+#             */
/*   Updated: 2022/07/09 17:20:23 by kyalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_convert_to_lowercase_hexadecimal(
			unsigned long int unsigned_long_integer)
{
	if (unsigned_long_integer < 10)
		return (unsigned_long_integer + '0');
	else
		return ('a' + unsigned_long_integer - 10);
}
