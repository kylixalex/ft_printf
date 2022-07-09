#include <unistd.h>

static int	ft_getUnsignedDecimalLength(unsigned int unsignedInteger)
{
	int	length;

	length = 0;
	if (unsignedInteger == 0)
		return (1);
	while (unsignedInteger)
	{
		length++;
		unsignedInteger /= 10;
	}
	return (length);
}

int	ft_putUnsignedDecimal(unsigned int unsignedInteger)
{
	int		numericStringIndexer;
	char	numericString[12];
	int		length;

	length = ft_getUnsignedDecimalLength(unsignedInteger);
	numericStringIndexer = 0;
	while (numericStringIndexer < length)
	{
		numericString[length - numericStringIndexer - 1] = 
			unsignedInteger % 10 + '0';
		unsignedInteger /= 10;
		numericStringIndexer++;
	}
	numericString[length] = '\0';
	return (write(STDOUT_FILENO, numericString, length));
}
