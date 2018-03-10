/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:40:11 by nmizin            #+#    #+#             */
/*   Updated: 2017/11/26 15:29:13 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**argv;
	int		j;
	int		i;
	int		n;

	if (!s)
		return (NULL);
	if (!(argv = (char **)malloc(sizeof(char *) * my_ft_wordcount(s, c) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < my_ft_wordcount(s, c))
	{
		n = 0;
		if (!(argv[i] = ft_strnew(my_ft_lettercount(&s[i], c) + 1)))
			return (NULL);
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			argv[i][n++] = s[j++];
		argv[i++][n] = '\0';
	}
	argv[i] = NULL;
	return (argv);
}
