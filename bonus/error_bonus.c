/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:56:14 by wimam             #+#    #+#             */
/*   Updated: 2025/02/19 05:22:43 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_msg(int msg)
{
	if (msg == 1)
		ft_putstr_fd("ERROR : wrong args\n", 2);
	else if (msg == 2)
		ft_putstr_fd("ERROR : fd duplication faild\n", 2);
	else if (msg == 3)
		ft_putstr_fd("ERROR : execve failed", 2);
	else if (msg == 4)
		ft_putstr_fd("EROOR : One Of The Commands Can't Be executed\n", 2);
	else if (msg == 5)
		ft_putstr_fd("EROOR : Allocation Failed\n", 2);
	else if (msg == 6)
		ft_putstr_fd("ERROR : Faild to open fd\n", 2);
	else if (msg == 7)
		ft_putstr_fd("command not found \n", 2);
	else if (msg == 8)
		ft_putstr_fd("ERROR : pipe creation failed \n", 2);
	else if (msg == 9)
		ft_putstr_fd("ERROR : fork failed \n", 2);
	else if (msg == 10)
		ft_putstr_fd("permission denied \n", 2);
}
