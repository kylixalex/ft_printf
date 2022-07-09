#include <unistd.h>

#include "ft_strlen.h"

int	ft_putString(const char *s)
{
	if (s == NULL)
		return (write(STDOUT_FILENO, "(null)", 6));
	return (write(STDOUT_FILENO, s, ft_strlen(s)));
}
