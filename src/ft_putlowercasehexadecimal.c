#include <unistd.h>

#include "ft_converttolowercasehexadecimal.h"
#include "ft_gethexadecimallength.h"

int	ft_putLowerCaseHexadecimal(unsigned int unsignedInteger)
{
	int		numericStringIndexer;
	char	numericString[8];
	int		length;

	length = ft_getHexadecimalLength(unsignedInteger);
	numericStringIndexer = 0;
	while (numericStringIndexer < length)
	{
		numericString[length - numericStringIndexer - 1] =
			ft_convertToLowerCaseHexadecimal(unsignedInteger % 16);
		unsignedInteger /= 16;
		numericStringIndexer++;
	}
	numericString[length] = '\0';
	return (write(STDOUT_FILENO, numericString, length));
}
