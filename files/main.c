/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk <ael-bekk@student.13    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 09:09:32 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/20 10:01:30 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	args_control(int ac)
{
	if (ac != 5)
	{
		if (ac > 5)
			write(2, "Error : [a lot of args]\n", 24);
		else
			write(2, "Error : [few args]\n", 19);
		exit(1);
	}
}

int	main(int ac, char **av, char **env)
{
	char	***cmds;
	int		fd[2];

	args_control(ac);
	fd[0] = open(av[1], O_RDONLY);
	fd[1] = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (access(av[1], R_OK) == ERROR)
	{
		print_error(av[1], strerror(errno));
		av[2][0] = -1;
	}
	cmds = parcing(2, &av[2], env);
	do_pipe(cmds, env, 2, fd);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
