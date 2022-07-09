#include <unistd.h>

#include "ft_gethexadecimallength.h"

static char	ft_convertToUpperCaseHexadecimal(unsigned int unsignedInteger)
{
	if (unsignedInteger < 10)
		return (unsignedInteger + '0');
	else
		return ('A' + unsignedInteger - 10);
}

int	ft_putUpperCaseHexadecimal(unsigned int unsignedInteger)
{
	int		numericStringIndexer;
	char	numericString[8];
	int		length;

	length = ft_getHexadecimalLength(unsignedInteger);
	numericStringIndexer = 0;
	while (numericStringIndexer < length)
	{
		numericString[length - numericStringIndexer - 1] =
			ft_convertToUpperCaseHexadecimal(unsignedInteger % 16);
		unsignedInteger /= 16;
		numericStringIndexer++;
	}
	numericString[length] = '\0';
	return (write(STDOUT_FILENO, numericString, length));
}
