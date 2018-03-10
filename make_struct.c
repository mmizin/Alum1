

#include "libft.h"

t_list *read_from_file(char *str, t_list *list, t_list *head)
{
	int fp;
	char *line;

	fp = open(str, O_RDONLY);
	if (fp > 0)
	{
		while(get_next_line(fp, &line) > 0)
		{
			list->num = f_valid(line) ? ft_atoi(line) : 0;
			if (list->num < 1 || list->num > 10000)
			{
				list->next = NULL;
				return (list);
			}
			list->next = (t_list *)malloc(sizeof(t_list));
			list = list->next;
		}
		list->next = NULL;
		return (head);
	}
	return (list);

}

t_list *make_struct(char *str, t_list *list)
{
	//static	t_list *list;
	t_list	*head;
	char 	*line;

	//list = (t_list *)malloc(sizeof(t_list));
	head = list;
	if (!str)
	{
		while (get_next_line(0, &line) && *line) {
			list->num = f_valid(line) ? ft_atoi(line) : 0;

			if (list->num < 1 || list->num > 10000)
			{
				list->next = NULL;
				return (list);
			}
			list->next = (t_list *) malloc(sizeof(t_list));
			list = list->next;
		}
		list->next = NULL;
	}
	else
		return(read_from_file(str, list, head));
	return (head);
}