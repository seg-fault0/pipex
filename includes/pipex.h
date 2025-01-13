/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:45:09 by wimam             #+#    #+#             */
/*   Updated: 2025/01/13 17:18:49 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libc.h>

//utils
void	ft_putstr(char *str);

//check
void	error_msg(int msg);
int		is_arg_valid(int argc, char **argv);
char	*ft_strjoin(char const *s1, char const *s2);

//core

#endif