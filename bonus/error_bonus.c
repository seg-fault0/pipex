/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:56:14 by wimam             #+#    #+#             */
/*   Updated: 2025/03/23 00:08:55 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_close(int fd)
{
	if (fd >= 0)
		close(fd);
}

void	error_msg(int msg)
{
	if (msg == 1)
		ft_putstr_fd("ERROR : Not enough args\n", 2);
	else if (msg == 2)
		ft_putstr_fd("ERROR : fd duplication faild\n", 2);
	else if (msg == 3)
		ft_putstr_fd("ERROR : execve failed", 2);
	else if (msg == 4)
		ft_putstr_fd("EROOR : One Of The Commands Can't Be executed\n", 2);
	else if (msg == 5)
		ft_putstr_fd("EROOR : Allocation Failed\n", 2);
	else if (msg == 6)
		ft_putstr_fd("no such file or directory\n", 2);
	else if (msg == 7)
		write(2, "command not found \n", 19);
	else if (msg == 8)
		ft_putstr_fd("ERROR : pipe creation failed \n", 2);
	else if (msg == 9)
		ft_putstr_fd("ERROR : fork failed \n", 2);
	else if (msg == 10)
		ft_putstr_fd("permission denied \n", 2);
	else if (msg == 11)
		ft_putstr_fd("syntaxe error\n", 2);
}
