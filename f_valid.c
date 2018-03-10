#include "libft.h"
#include <stdio.h>

int		f_valid(char *str)
{
	if (!*str)
	{
		//write(1, "ERROR\n", 6);
		return  (0);
	}
	while (*str)
	{

		if (*str < '0' || *str > '9')
		{
			//write(1, "ERROR\n", 6);
			return  (0);
		}

		else
			str++;
	}
	return (1);
}