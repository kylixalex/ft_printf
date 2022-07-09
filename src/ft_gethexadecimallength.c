int	ft_getHexadecimalLength(unsigned long int unsignedInteger)
{
	int	length;

	length = 0;
	if (unsignedInteger == 0)
		return (1);
	while (unsignedInteger)
	{
		length++;
		unsignedInteger /= 16;
	}
	return (length);
}
