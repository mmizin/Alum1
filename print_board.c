/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 21:05:54 by nmizin            #+#    #+#             */
/*   Updated: 2018/03/10 21:06:01 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				check_answer(char *str)
{
	int res;

	if (f_valid(str))
	{
		res = ft_atoi(str);
		if (1 <= res && res <= 3)
			return (1);
		else
			return (0);
	}
	return (0);
}

static	int		find_max(t_list *list)
{
	int b_num;

	b_num = 0;
	while (list->next)
	{
		if (b_num == 0 || b_num < list->num)
			(b_num = list->num);
		list = list->next;
	}
	return (b_num);
}

static	int		f_beauty_wright(int num)
{
	int sum;
	int max_ind;
	int center;

	sum = (num * 2) - 1;
	max_ind = sum - 1;
	center = max_ind / 2;
	return (center);
}

static	void	f_heandler(int center, t_list *list, int max)
{
	int c;
	int print_num;

	while (list->next)
	{
		print_num = list->num;
		if (list->num != max)
		{
			(c = center - list->num + 1);
			f_w_e_l(' ', c);
		}
		while (print_num)
		{
			write(1, "|", 1);
			(print_num > 0) && write(1, " ", 1);
			print_num -= 1;
		}
		write(1, "\n", 1);
		list = list->next;
	}
}

void			print_board(t_list *list)
{
	int max;
	int center;

	max = find_max(list);
	center = f_beauty_wright(max);
	f_heandler(center, list, max);
}
