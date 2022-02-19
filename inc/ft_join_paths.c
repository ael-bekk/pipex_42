/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <<ael-bekk@student.1337.ma>>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:54:36 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/13 19:08:44 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_join(char const *s1, char const *s2)
{
	char	*res;
	int		l1;
	int		l2;
	int		i;

	res = NULL;
	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = (char *)malloc(l1 + l2 + 2);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < l1)
		res[i] = s1[i];
	res[i] = '/';
	i = -1;
	while (++i < l2)
		res[i + l1 + 1] = s2[i];
	res[l1 + l2 + 1] = 0;
	return (res);
}
