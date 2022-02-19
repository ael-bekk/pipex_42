/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk <ael-bekk@student.13    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:39:59 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/19 11:25:32 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	close_prev_pipe(int *pip, int valid)
{
	if (valid)
	{
		close(pip[0]);
		close(pip[1]);
	}
}

void	switch_pipes(int i, int n_pipes, int *pipe1, int *pipe2)
{
	if (i)
	{
		close_prev_pipe(pipe1, i > 1);
		pipe1[0] = pipe2[0];
		pipe1[1] = pipe2[1];
	}
	if (i + 1 != n_pipes && pipe(pipe2) == ERROR)
		exit_with_fail("pipe");
}

int	fork_from_the_parent(int *pipe2, int i, int n_pipes, int *in_out_file)
{
	int	pid;

	if (i + 1 == n_pipes)
			pipe2[1] = in_out_file[1];
	pid = fork();
	if (pid == ERROR)
		exit_with_fail("fork");
	return (pid);
}

void	redirection_fd(int *pipe1, int *pipe2)
{
	if (pipe1[0] == ERROR)
		exit(EXIT_FAILURE);
	if (dup2(pipe1[0], STDIN_FILENO) == ERROR)
		exit_with_fail("dup");
	if (dup2(pipe2[1], STDOUT_FILENO) == ERROR)
		exit_with_fail("dup");
	close_prev_pipe(pipe1, TRUE);
	close_prev_pipe(pipe2, TRUE);
}

void	do_pipe(char ***cmds, char **env, int n_pipes, int *in_out_file)
{
	int	pipe1[2];
	int	pipe2[2];
	int	pid;
	int	i;

	i = -1;
	pipe1[0] = in_out_file[0];
	while (++i < n_pipes)
	{
		switch_pipes(i, n_pipes, pipe1, pipe2);
		pid = fork_from_the_parent(pipe2, i, n_pipes, in_out_file);
		if (pid == CHILD_PROCESS)
		{	
			redirection_fd(pipe1, pipe2);
			if (execve(cmds[i][0], cmds[i], env) == ERROR && cmds[i][0])
				exit_with_fail(cmds[i][0]);
			exit(EXIT_FAILURE);
		}
	}
	close_prev_pipe(pipe1, TRUE);
	while (wait(NULL) != ERROR)
		;
}
