/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk <ael-bekk@student.13    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:39:03 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/19 11:42:39 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

t_bool	match_strings(char *s1, char *s2, int lent, char fin)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (!fin && !s1[i] && !s2[i] && i == lent)
		return (TRUE);
	if (fin && s1[i] == '\n' && i == lent)
		return (TRUE);
	return (FALSE);
}

t_bool	args_control(int ac, char **arg2)
{
	if (ac < 5)
	{
		write(2, "Error : [few args]\n", 19);
		exit(EXIT_FAILURE);
	}
	if (match_strings(arg2[1], "here_doc", 8, '\0'))
	{
		if (ac < 6)
		{
			write(2, "Error : [few args]\n", 19);
			exit(EXIT_FAILURE);
		}
		return (TRUE);
	}
	return (FALSE);
}

void	read_from_here_doc(int fd, char *limiter, int pip)
{
	int		i;
	t_bool	cont;
	char	*line;

	i = 0;
	line = NULL;
	cont = FALSE;
	while (cont == FALSE)
	{
		if (!i || (line && ft_strnstr(line, "\n", ft_strlen(line))))
		{
			i = -1;
			while (++i < pip)
				write(1, "pipe ", 6);
			write(1, "heredoc> ", 10);
		}
		line = get_next_line(0);
		if (line)
			cont = (t_bool)match_strings(line, limiter, ft_strlen(limiter), 10);
		if (cont == FALSE)
			write(fd, line, ft_strlen(line));
		free(line);
	}
	close(fd);
	return ;
}

int	main(int ac, char **av, char **env)
{
	char	***cmds;
	int		fd[2];
	int		first_cmd;

	if (args_control(ac, av))
	{
		if (pipe(fd) == ERROR)
			exit_with_fail("pipe");
		read_from_here_doc(fd[1], av[2], ac - 5);
		fd[1] = open(av[ac - 1], O_CREAT | O_APPEND | O_WRONLY, 0644);
		first_cmd = 3;
	}
	else
	{
		fd[0] = open(av[1], O_RDONLY);
		fd[1] = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (access(av[1], R_OK) == ERROR)
		{
			print_error(av[1], strerror(errno));
			av[2][0] = -1;
		}
		first_cmd = 2;
	}
	cmds = parcing(ac - 1 - first_cmd, &av[first_cmd], env);
	do_pipe(cmds, env, ac - 1 - first_cmd, fd);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
