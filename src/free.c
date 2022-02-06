/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:50:51 by dramos-p          #+#    #+#             */
/*   Updated: 2022/02/06 02:42:14 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	p_free(t_pipex *p)
{
	int	i;

	i = 0;
	close(p->infile);
	close(p->outfile);
	while (p->cmd_paths[i])
	{
		free(p->cmd_paths[i]);
		i++;
	}
	free(p->cmd_paths);
}

void	child_free(t_pipex *p)
{
	int	i;

	i = 0;
	while (p->cmd_args[i])
	{
		free(p->cmd_args[i]);
		i++;
	}
	free(p->cmd_args);
	free(p->cmd);
}
