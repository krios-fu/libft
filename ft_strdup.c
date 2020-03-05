/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:38:07 by krios-fu          #+#    #+#             */
/*   Updated: 2020/02/05 14:48:27 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	void	*snew;

	len = ft_strlen((char *)s1) + 1;
	snew = (char *)malloc(len);
	if (snew == NULL)
		return (NULL);
	snew = ft_memcpy(snew, s1, len);
	return ((char *)snew);
}
