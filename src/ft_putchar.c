#include <unistd.h>

int	ft_putChar(char character)
{
	return (write(STDOUT_FILENO, &character, 1));
}
