/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:33:47 by krios-fu          #+#    #+#             */
/*   Updated: 2021/03/31 15:45:32 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_isspace(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (&str[i]);
}

int	ft_cmp_p_n(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag++;
		i++;
	}
	if (flag % 2 == 0)
		return (1);
	return (-1);
}

char	*ft_position(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	return (&str[i]);
}

int	ft_atoi(const char *str)
{
	char		*ptr;
	int			i;
	int			j;
	int			nb;
	long		plus;

	i = 0;
	ptr = ft_position(ft_isspace((char *)str));
	if (ptr[0] < '0' || ptr[0] > '9')
		return (0);
	j = 0;
	while (ptr[j] >= '0' && ptr[j] <= '9')
		j++;
	i = 0;
	plus = 0;
	while (i < j)
	{
		nb = ptr[i] - '0';
		plus += nb;
		if (i < j - 1)
			plus *= 10;
		i++;
	}
	plus *= ft_cmp_p_n(ft_isspace((char *)str));
	return (plus);
}
