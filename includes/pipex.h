/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:45:09 by wimam             #+#    #+#             */
/*   Updated: 2025/03/06 13:29:27 by wimam            ###   ########.fr       */
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
	int		infd;
	int		outfd;
	char	**cmd1;
	char	**cmd2;
	int		exit_code;
}	t_pipex;

//utils
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	close_pipe(int *fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);

//core
t_pipex	*pipex_init(int argc, char **argv);
void	ft_start(t_pipex *pipex);
void	ft_exit(t_pipex *pipex);
void	free_all(t_pipex *pipex);
void	free_cmd(char ***cmd);
void	error_msg(int msg);

#endif