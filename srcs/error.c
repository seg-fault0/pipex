/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:56:14 by wimam             #+#    #+#             */
/*   Updated: 2025/01/17 15:55:27 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void	error_msg(int msg)
{
	if (msg == 1)
		ft_putstr("ERROR : not enough args\n");
	else if (msg == 2);
	else if (msg == 3);
	else if (msg == 4)
		ft_putstr("EROOR : One Of The Commands Can't Be executed\n");
	else if (msg == 5)
		ft_putstr("EROOR : Allocation Failed\n");
	else if (msg == 6)
		ft_putstr("ERROR : Faild to open fd\n");
}