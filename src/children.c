/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:50:51 by dramos-p          #+#    #+#             */
/*   Updated: 2022/02/05 17:13:07 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*check_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	child_proc(t_pipex p, char *argv[], char *envp[], int x)
{
	if (x == 1)
	{
		dup2(p.connect[1], 1);
		close(p.connect[0]);
		dup2(p.infile, 0);
		p.cmd_args = ft_split(argv[2], ' ');
		p.cmd = check_cmd(p.cmd_paths, p.cmd_args[0]);
	}
	if (x == 2)
	{
		dup2(p.connect[0], 0);
		close(p.connect[1]);
		dup2(p.outfile, 1);
		p.cmd_args = ft_split(argv[3], ' ');
		p.cmd = check_cmd(p.cmd_paths, p.cmd_args[0]);
	}
	if (!p.cmd)
	{
		child_free(&p);
		ft_msg("Command not found\n");
		exit(1);
	}
	execve(p.cmd, p.cmd_args, envp);
}
