/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:09:07 by nmizin            #+#    #+#             */
/*   Updated: 2017/11/13 20:42:50 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*stwo;
	size_t	len;

	len = 0;
	while (s1[len])
	{
		len++;
	}
	stwo = (char *)malloc(sizeof(char) * (len + 1));
	if (stwo == NULL)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		stwo[len] = s1[len];
		len++;
	}
	stwo[len] = '\0';
	return (stwo);
}
