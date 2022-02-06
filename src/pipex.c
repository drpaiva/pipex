/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:50:51 by dramos-p          #+#    #+#             */
/*   Updated: 2022/02/06 02:42:07 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	close_pipes(t_pipex *p)
{
	close(p->connect[0]);
	close(p->connect[1]);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	p;

	if (argc != 5)
		return (ft_msg("Invalid number of arguments.\n"));
	p.infile = open(argv[1], O_RDONLY);
	if (p.infile < 0)
		ft_error("Error Open File1");
	p.outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0000644);
	if (p.outfile < 0)
		ft_error("Error Open File2");
	if (pipe(p.connect) < 0)
		ft_error("Error Create process");
	p.paths = find_path(envp);
	p.cmd_paths = ft_split(p.paths, ':');
	p.pid1 = fork();
	if (p.pid1 == 0)
		child_proc(p, argv, envp, 1);
	p.pid2 = fork();
	if (p.pid2 == 0)
		child_proc(p, argv, envp, 2);
	close_pipes(&p);
	waitpid(p.pid1, NULL, 0);
	waitpid(p.pid2, NULL, 0);
	p_free(&p);
	return (0);
}
