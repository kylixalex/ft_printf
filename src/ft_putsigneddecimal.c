#include <unistd.h>
#include <limits.h>

static int	ft_getSignedDecimalLength(int signedInteger)
{
	int	length;

	length = 0;
	if (signedInteger == 0)
		return (1);
	if (signedInteger < 0)
		length++;
	while (signedInteger)
	{
		length++;
		signedInteger /= 10;
	}
	return (length);
}

int	ft_putSignedDecimal(int signedInteger)
{
	int		numericStringIndexer;
	char	numericString[13];
	int		length;
	int		offset;

	if (signedInteger == INT_MIN)
		return (write(STDOUT_FILENO, "-2147483648", 11));
	length = ft_getSignedDecimalLength(signedInteger);
	numericStringIndexer = 0;
	offset = 0;
	if (signedInteger < 0)
	{
		numericString[0] = '-';
		signedInteger *= -1;
		offset = 1;
	}
	while (numericStringIndexer < length - offset)
	{
		numericString[length - numericStringIndexer - 1] = 
			signedInteger % 10 + '0';
		signedInteger /= 10;
		numericStringIndexer++;
	}
	numericString[length] = '\0';
	return (write(STDOUT_FILENO, numericString, length));
}
