/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:12:41 by krios-fu          #+#    #+#             */
/*   Updated: 2020/01/13 12:40:05 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*sr;

	dest = (unsigned char *)dst;
	sr = (const unsigned char *)src;
	if (dest > sr)
	{
		while (len--)
			dest[len] = sr[len];
	}
	else if (dest < sr)
		ft_memcpy(dst, src, len);
	return (dst);
}
