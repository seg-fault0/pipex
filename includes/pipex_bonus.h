/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 04:41:33 by wimam             #+#    #+#             */
/*   Updated: 2025/03/20 02:13:49 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

//headers
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "get_next_line_bonus.h"

//Macros
# define BIN_PATH "/usr/bin/"
# define STDIN 0
# define STDOUT 1

//struct
typedef struct s_pipex
{
	char	***cmd;
	int		*children_pid;
	int		infd;
	int		outfd;
	int		count;
	int		max_count;
	int		exit_code;
}	t_pipex;

//utils
char	**ft_split(char const *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
void	close_pipe(int *fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_free2darr(char **arr);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

//core
int		pipex_init(t_pipex *pipe, int argc, char **argv, char **env);
void	ft_start(t_pipex *pipex, int rfd);
void	ft_exit(t_pipex *pipex);
void	free_all(t_pipex *pipex);
void	free_cmd(char ***cmd);
void	error_msg(int msg);

#endif