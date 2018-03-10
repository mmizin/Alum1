/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:31:16 by alukyane          #+#    #+#             */
/*   Updated: 2018/03/10 14:31:19 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		bot(t_list *str_match)
{
	int		count;

	if (str_match->next->num % 4 == 1)
		count = str_match->num % 4 == 0 ? 1 : str_match->num % 4;
	else
	{
		if (str_match->num % 4 == 1)
			count = 1;
		else if (str_match->num % 4 == 0)
			count = 3;
		else
			count = str_match->num % 4 - 1;
	}
	return (count);
}

int		sum_matches(t_list *str_match)
{
	int sum;

	sum = 0;

	while (str_match->next)
	{//printf("STR:%d\n", str_match->num);
		sum += str_match->num;
		str_match = str_match->next;
	}
	return (sum);
}

t_list	*update_board(t_list *str_match, int count)
{
	int res;

	res = str_match->num - count;
	printf("RES:%d\n", res);
	if (res)
		str_match->num = res;
	else
		str_match = str_match->next;
	printf("NUMMMMM:%d\n", str_match->num);
	return (str_match);
}

void	print_result(int move_number)
{
	char	*str;

	if (move_number % 2 == 0)
		str = ft_strdup("****************\n*YOU'RE WINNER!*\n****************\n");
	else
		str = ft_strdup("****************\n*BOT IS WINNER!*\n****************\n");
	write(1, str, ft_strlen(str));
	free(str);
}



int		ask_human(t_list *str_match)
{
	int		count;
	char	*line;
	int		i;

	get_next_line(0, &line);
	i = 0;
	while (!check_answer(line))
	{
		if (i < 3)
			write(1, "Number can be between 1 and 3. Try again ;)\n", 43);
		else if (3 <= i && i <= 5)
			write(1, "BETWEEN 1 and 3 means '1', '2' or '3'!!!\n", 41);
		else
		{
			write(1, "This game is too HARD for you...\n", 33);
			write(1, "+-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+\n", 56);
 			write(1, "|T| |H| |I| |N| |K|   |A| |B| |O| |U| |T|   |I| |T| |!|\n", 56);
 			write(1, "+-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+\n", 56);
		}
		get_next_line(0, &line);
		i++;
	}
	count = ft_atoi(line);
	printf("STRNUM:%d\n", str_match->num);
	while (count > str_match->num)
	{
		write(1, "Number uifeigfed\n", 17);
		get_next_line(0, &line);
		count = ft_atoi(line);
	}

	return (count);
}

int		main(int ac, char **av)
{
	int		move_number;
	t_list	*str_matches;
	int		count_match;
	int sum;

	move_number = 0;
	ac = 0;
	str_matches = (t_list *)malloc(sizeof(t_list));
	str_matches = make_struct(av[1], str_matches);
	if (!(str_matches->num) || str_matches->num > 10000)
	{
		write(1, RED, 6) && write(1, "ERROR\n" , 6) && write(1, RES, 5);
		return (0);
	}
	sum = sum_matches(str_matches);
	printf("SUM:%d\n", sum);
	while (sum)
	{
		printf("%s\n", "----");
		print_board(str_matches);
		printf("%s\n", "****");
		if (move_number % 2 == 0)
			write(1, "The number of matches you want to remove:\n", 42);
		else
			write(1, "Bot's move...\n", 14);
		count_match = move_number % 2 == 0 ? ask_human(str_matches) : bot(str_matches);
		printf("count_match:%d\n", count_match);
		str_matches = update_board(str_matches, count_match);
		sum -= count_match;
		move_number++;
	}
	print_result(move_number);
	return (0);
}