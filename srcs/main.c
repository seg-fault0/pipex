/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:45:39 by wimam             #+#    #+#             */
/*   Updated: 2025/01/17 21:28:02 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[])
{
	t_pipex *pipex;
	int		process_nbr;
	int		pfd[2];

	if (argc < 5)
		return (error_msg(1), 1);
	pipex = pipex_init(--argc, ++argv);
	if(!pipex)
		return (1);
	process_nbr = argc - 2;
	pipe(pfd);
	ft_pipex(pipex, pfd, 0, process_nbr);
	return (0);
}