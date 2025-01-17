/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:45:09 by wimam             #+#    #+#             */
/*   Updated: 2025/01/17 15:33:39 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//headers
# include <libc.h>

//struct
typedef struct s_pipex
{
	char	***cmd;
	int		infd;
	int		outfd;
} t_pipex;

//utils
void	ft_putstr(char *str);
char	**ft_split(char const *s, char c);

//check
void	error_msg(int msg);
char	*ft_strjoin(char const *s1, char const *s2);

//core
t_pipex	*pipex_init(int argc, char *argv[]);
void	ft_exit(t_pipex *pipex);


#endif