/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk <ael-bekk@student.13    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 09:05:40 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/19 11:00:54 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define CHILD_PROCESS 0
# define WHITE "\033[0;37m"
# define YELL "\033[0;33m"
# define RESET "\033[0m"

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include "get_next_line.h"

typedef int				t_bool;
typedef unsigned int	t_uint;

///////////////////////		aux			////////////////////////
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);
t_uint	ft_strlen(const char *s);
char	*ft_join(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

///////////////////////		errors		////////////////////////
void	exit_with_fail(char *s);
void	print_error(char *p, char *s);
int		not_a_path(char *s);

///////////////////////		pipx		////////////////////////
void	exit_with_fail(char *s);
void	close_prev_pipe(int *pip, int valid);
void	switch_pipes(int i, int n_pipes, int *pipe1, int *pipe2);
int		fork_from_the_parent(int *pipe2, int i, int n_pipes, int *in_out_file);
void	do_pipe(char ***cmds, char **env, int n_pipes, int *in_out_file);

///////////////////////		parcing		////////////////////////
char	**find_path(char **env);
void	init_cmds(char ***cmds, char **av, int nb_cmd, char **paths);
char	***parcing(int nb_cmd, char **av, char **env);
void	print_error(char *p, char *s);

#endif