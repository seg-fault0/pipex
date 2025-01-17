/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:45:39 by wimam             #+#    #+#             */
/*   Updated: 2025/01/17 16:02:29 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[])
{
	t_pipex *pipex;

	if (argc < 5)
		return (error_msg(1), 1);
	pipex = pipex_init(--argc, ++argv);
	if(!pipex)
		return (1);
	ft_putstr("Success to init \n");
	ft_exit(pipex);
}