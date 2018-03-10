/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:21:30 by nmizin            #+#    #+#             */
/*   Updated: 2017/11/14 16:33:15 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	count;

	count = 0;
	while (s1[count])
		count++;
	i = count;
	count = 0;
	while (count < n && s2[count] != '\0')
	{
		s1[i] = s2[count];
		i++;
		count++;
	}
	s1[i] = '\0';
	return (s1);
}
