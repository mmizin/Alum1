/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:14:40 by nmizin            #+#    #+#             */
/*   Updated: 2017/11/24 21:33:28 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new;
	char		*temp;
	size_t		sumconcat;

	if (!s1 || !s2)
		return (NULL);
	sumconcat = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (sumconcat + 1));
	if (!new)
		return (NULL);
	temp = new;
	while (*s1)
		*new++ = *s1++;
	while (*s2)
		*new++ = *s2++;
	*new = '\0';
	return (temp);
}
