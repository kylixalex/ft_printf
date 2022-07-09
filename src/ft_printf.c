#include <stdarg.h>
#include <unistd.h>

#include "ft_handleformatspecifier.h"
#include "ft_strchr.h"

int	ft_printf(const char *format, ...)
{
	va_list	argumentPointer;
	int			formatIndexer;
	int			bytesWritten;
	 
	va_start(argumentPointer, format);
	formatIndexer = 0;
	bytesWritten	= 0;
	while (format[formatIndexer])
	{
		if (format[formatIndexer] == '%')
		{
			if (ft_strchr("csidupxX%", format[formatIndexer + 1]))
				bytesWritten += ft_handleFormatSpecifier(argumentPointer,
						format[++formatIndexer]);
		}
		else
			bytesWritten += write(STDOUT_FILENO, &format[formatIndexer], 1);
		formatIndexer++;
	}
	va_end(argumentPointer);
	return (bytesWritten);
}
