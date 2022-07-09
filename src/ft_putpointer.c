#include <unistd.h>

#include "ft_converttolowercasehexadecimal.h"
#include "ft_gethexadecimallength.h"

static char	*ft_strcpy(char *destination, const char *source)
{
	int	stringIndexer;

	stringIndexer = 0;
	while (source[stringIndexer])
	{
		destination[stringIndexer] = source[stringIndexer];
		stringIndexer++;
	}
	destination[stringIndexer] = '\0';
	return (destination);
}

int	ft_putPointer(unsigned long int address)
{
	int		numericStringIndexer;
	char	numericString[17];
	int		length;

	if (address == 0)
		return (write(STDOUT_FILENO, "(nil)", 5));
	numericStringIndexer = 0;
	length = ft_getHexadecimalLength(address);
	ft_strcpy(numericString, "0x");
	while (numericStringIndexer < length)
	{
		numericString[length - numericStringIndexer + 1] =
			ft_convertToLowerCaseHexadecimal(address % 16);
		address /= 16;
		numericStringIndexer++;
	}
	return (write(STDOUT_FILENO, numericString, length + 2));
}
/*
#include <stdio.h>
int	main(void)
{
	ft_putPointer(17);
	printf("\n%p\n", (void *) 17);
	return (0);
}
*/
