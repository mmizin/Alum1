/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:42:33 by nmizin            #+#    #+#             */
/*   Updated: 2017/11/17 20:15:38 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n)
	{
		(*(unsigned char *)dest) = (*(unsigned char *)src);
		if ((*(unsigned char *)src) == (unsigned char)c)
			return (dest + 1);
		dest++;
		src++;
		n--;
	}
	return (NULL);
}
