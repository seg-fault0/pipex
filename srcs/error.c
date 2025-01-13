/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:56:14 by wimam             #+#    #+#             */
/*   Updated: 2025/01/13 17:21:29 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void	error_msg(int msg)
{
	if (msg == 1)
		ft_putstr("ERROR : not enough args\n");
	else if (msg == 2)
		ft_putstr("ERROR : The inFile isn't readable\n");
	else if (msg == 3)
		ft_putstr("ERROR : The outFile isn't writable\n");
	else if (msg = 4)
		ft_putstr("EROOR : One Of The Commands Can't Be executed\n");
}