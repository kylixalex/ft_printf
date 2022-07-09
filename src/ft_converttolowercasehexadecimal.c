char	ft_convertToLowerCaseHexadecimal(unsigned long int unsignedInteger)
{
	if (unsignedInteger < 10)
		return (unsignedInteger + '0');
	else
		return ('a' + unsignedInteger - 10);
}

