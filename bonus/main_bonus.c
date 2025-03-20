/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:45:39 by wimam             #+#    #+#             */
/*   Updated: 2025/03/20 02:15:03 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc < 5)
		return (error_msg(1), 1);
	if (pipex_init(&pipex, --argc, ++argv, env))
		return (1);
	ft_start(&pipex, pipex.infd);
	ft_exit(&pipex);
	return (0);
}
