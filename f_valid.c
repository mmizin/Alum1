#include "libft.h"

int	f_valid(char *str, t_list *content)
{
	char *str_r_chr;
	char *tmp;
	int count;

	tmp = ft_strjoin(content->content, str);
	free(content->content);
	content->content = tmp; /* записываем все что есть в файле */

	str_r_chr = ft_strrchr(str, '|'); /* нахожу последнее вхождение символа '|' встроке */

	count = 0;
	while (*str)
	{
		if (*str != '|' && *str != ' ') /* не ' ' и не  '|' выходим из функции */
		{
			write(1, "ERROR\n", 6);
			return (0);
		}
		if (str == str_r_chr) { /* как только мы столкнемся с последним вхождением символа, выходим из цыкла */
			count++;
			break;
		}
		if (*str == '|') /* считаем только символ '|' */
			count++;
		str++;
	}
	if (count <= 0 && count >= 10000) /* проверяем количество '|', оно должно быть от 1 до 10 000 */
		return (0);
	return (1);
}
