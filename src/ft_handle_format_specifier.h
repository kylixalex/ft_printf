/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format_specifier.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyalexan <kyalexan@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:41:54 by kyalexan          #+#    #+#             */
/*   Updated: 2022/07/09 17:07:02 by kyalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLE_FORMAT_SPECIFIER_H
# define FT_HANDLE_FORMAT_SPECIFIER_H

# include <stdarg.h>

int	ft_handle_format_specifier(va_list argument_pointer, char format_specifier);

#endif
