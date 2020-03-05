/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:40:49 by krios-fu          #+#    #+#             */
/*   Updated: 2020/01/27 22:40:26 by krios-fu         ###   ########.fr       */
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

static char		**ft_free_matrix(const char **matrix, size_t len_matrix)
{
	while (len_matrix--)
		free((void *)matrix[len_matrix]);
	free(matrix);
	return (NULL);
}

char			**ft_split(const char *s, char c)
{
	char	**matrix;
	size_t	len;
	size_t	i;
	size_t	sl;
	char	*new_s;

	i = 0;
	sl = 0;
	len = ft_numstring(s, c);
	if (!(matrix = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	new_s = (char *)s;
	while (i < len)
	{
		while (*new_s == c)
			new_s++;
		sl = ft_numchar((const char *)new_s, c);
		if (!(matrix[i] = (char *)malloc(sizeof(char) * sl + 1)))
			return (ft_free_matrix((const char **)matrix, len));
		ft_strlcpy(matrix[i], new_s, sl + 1);
		new_s = (ft_strchr(new_s, (int)c));
		i++;
	}
	matrix[i] = 0;
	return (matrix);
}
