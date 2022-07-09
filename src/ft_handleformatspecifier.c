#include <stdarg.h>
#include <unistd.h>

#include "ft_putlowercasehexadecimal.h"
#include "ft_putuppercasehexadecimal.h"
#include "ft_putunsigneddecimal.h"
#include "ft_putsigneddecimal.h"
#include "ft_putpointer.h"
#include "ft_putstring.h"
#include "ft_putchar.h"

int	ft_handleFormatSpecifier(va_list argumentPointer, char formatSpecifier)
{
	if (formatSpecifier == 'c')
		return (ft_putChar(va_arg(argumentPointer, int)));
	else if (formatSpecifier == 's')
		return (ft_putString(va_arg(argumentPointer, char *)));
	else if (formatSpecifier == 'd' || formatSpecifier == 'i')
		return (ft_putSignedDecimal(va_arg(argumentPointer, int)));
	else if (formatSpecifier == 'u')
		return (ft_putUnsignedDecimal(va_arg(argumentPointer, unsigned int)));
	else if (formatSpecifier == 'x')
		return (ft_putLowerCaseHexadecimal(va_arg(argumentPointer, unsigned int)));
	else if (formatSpecifier == 'X')
		return (ft_putUpperCaseHexadecimal(va_arg(argumentPointer, unsigned int)));
	else if (formatSpecifier == 'p')
		return (ft_putPointer((unsigned long int) va_arg(argumentPointer, void *)));
	else if (formatSpecifier == '%')
		return (write(STDOUT_FILENO, "%", 1));
	return (0);
}
