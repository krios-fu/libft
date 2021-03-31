/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:40:49 by krios-fu          #+#    #+#             */
/*   Updated: 2021/03/31 16:41:34 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_numstring(const char *s, char c)
{
	size_t	count;
	size_t	flag;

	count = 0;
	flag = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s == c)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	ft_numchar(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (s[count] != c && s[count] != '\0')
		count++;
	return (count);
}

static char	**ft_free_matrix(const char **matrix, size_t len_matrix)
{
	while (len_matrix--)
		free((void *)matrix[len_matrix]);
	free(matrix);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**matrix;
	size_t	len;
	size_t	i;
	size_t	sl;

	i = 0;
	sl = 0;
	len = ft_numstring(s, c);
	matrix = (char **)malloc(sizeof(char *) * (len + 1));
	if (!matrix)
		return (NULL);
	while (i < len)
	{
		while (*s == c)
			s++;
		sl = ft_numchar((const char *)s, c);
		matrix[i] = (char *)malloc(sizeof(char) * sl + 1);
		if (!matrix[i])
			return (ft_free_matrix((const char **)matrix, len));
		ft_strlcpy(matrix[i], s, sl + 1);
		s = (ft_strchr(s, (int)c));
		i++;
	}
	matrix[i] = 0;
	return (matrix);
}
