/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:45:09 by wimam             #+#    #+#             */
/*   Updated: 2025/01/21 01:14:41 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//headers
# include <libc.h>

//Macros
# define BIN_PATH "/usr/bin/"
# define STDIN 0
# define STDOUT 1

//struct
typedef struct s_pipex
{
	char	***cmd;
	int		infd;
	int		outfd;
	int		count;
	int		max_count;
} t_pipex;

//utils
void	ft_putstr(char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	close_pipe(int *fd);

//core
t_pipex	*pipex_init(int argc, char *argv[]);
void	ft_start(t_pipex *pipex, int rfd);
void	ft_exit(t_pipex *pipex);
void	free_cmd(char ***cmd);
void	error_msg(int msg);

#endif