
#include <stdio.h>
#include <mach/boolean.h>
#include <stdbool.h>

#include "libft.h"

int			main(void) {
	/* Проверку на NULL */

	static t_list *list;
	char *line;
	int fp;
	int copy_fp;
	int count_n;

	fp = open("/Users/nmizin/CLionProjects/Alum1/test.txt", O_RDONLY);
	copy_fp = open("/Users/nmizin/CLionProjects/Alum1/test.txt", O_RDONLY);
//	fp = open(argv[1], O_RDONLY);
//	copy_fp = open(argv[1], O_RDONLY);

	if (fp < 0)
		return (0);


	list = ft_lstnew("", 1);
	count_n = 0;
	while (get_next_line(fp, &line) > 0) {
		if (!f_valid(line, list)) {
			free(line);
			return (0);
		} else
			free(line);
		count_n++;
	}

	while (get_next_line(copy_fp, &line) > 0)
	{

		write(1, line, ft_strlen(line)) && write(1, "\n", 1);
		free(line);
	}

	close(fp);
	return (0);
}


