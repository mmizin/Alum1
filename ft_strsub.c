/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 19:16:29 by nmizin            #+#    #+#             */
/*   Updated: 2017/11/24 20:08:43 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *s1;
	char *temp;

	if (!s)
		return (NULL);
	s1 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (NULL);
	s = s + start;
	temp = s1;
	while (len--)
		*s1++ = *s++;
	*s1 = '\0';
	return (temp);
}
