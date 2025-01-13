/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:55:22 by wimam             #+#    #+#             */
/*   Updated: 2025/01/13 17:24:40 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	are_args_usable(int argc, char **argv)
{
	int		i;
	char	*cmd;

	if (access(argv[0], R_OK) != 0)
		return (error_msg(2), 1);
	else if (access(argv[argc - 1], W_OK) != 0)
		return (error_msg(3), 1);
	i = 1;
	while(i < argc - 1)
	{
		cmd = ft_strjoin("/usr/bin/", argv[i]);
		if (access(cmd, X_OK) != 0)
			return (free(cmd), error_msg(4), 1);
		free(cmd);
		i++;
	}
	return (0);
}

int	is_arg_valid(int argc, char **argv)
{
	if (argc < 4)
		return (error_msg(1), 1);
	if (are_args_usable(argc, argv))
		return (1);
	return (0);
}