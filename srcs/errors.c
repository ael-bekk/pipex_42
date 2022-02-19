/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk <ael-bekk@student.13    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:00:53 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/19 11:02:02 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	exit_with_fail(char *s)
{
	char	*err;

	write(2, WHITE, 7);
	write(2, "shell : ", 8);
	write(2, RESET, 4);
	err = strerror(errno);
	write(2, err, ft_strlen(err));
	write(2, ": ", 2);
	write(2, YELL, 7);
	write(2, s, ft_strlen(s));
	write(2, RESET, 4);
	write(2, " \n", 2);
	exit(EXIT_FAILURE);
}

void	print_error(char *p, char *s)
{
	write(2, WHITE, 7);
	write(2, "shell : ", 8);
	write(2, RESET, 4);
	write(2, s, ft_strlen(s));
	write(2, ": ", 2);
	write(2, YELL, 7);
	write(2, p, ft_strlen(p));
	write(2, RESET, 4);
	write(2, "\n", 2);
}

int	not_a_path(char *s)
{
	if (!ft_strnstr(s, "/", ft_strlen(s)))
		return (TRUE);
	return (FALSE);
}
