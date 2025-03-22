/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:45:09 by wimam             #+#    #+#             */
/*   Updated: 2025/03/22 21:29:17 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//headers
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>

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
char	*ft_strjoin(char const *s1, char const *s2);
void	close_pipe(int *fd);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_free2darr(char **arr);
int		ft_strlen(const char *str);

//core
int		pipex_init(t_pipex *pipex, int argc, char **argv, char **env);
void	ft_start(t_pipex *pipex, int rfd);
void	ft_exit(t_pipex *pipex);
void	free_all(t_pipex *pipex);
void	free_cmd(char ***cmd);
void	error_msg(int msg);

#endif