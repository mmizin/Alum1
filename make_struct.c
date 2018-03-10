/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 20:59:27 by nmizin            #+#    #+#             */
/*   Updated: 2018/03/10 20:59:33 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*read_from_file(char *str, t_list *list, t_list *head)
{
	int		fp;
	char	*line;

	fp = open(str, O_RDONLY);
	if (fp > 0)
	{
		while (get_next_line(fp, &line) > 0)
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

t_list	*make_struct(char *str, t_list *list)
{
	t_list	*head;
	char	*line;

	head = list;
	if (!str)
	{
		while (get_next_line(0, &line) && *line)
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
	}
	else
		return (read_from_file(str, list, head));
	return (head);
}
