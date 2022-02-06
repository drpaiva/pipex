/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:50:51 by dramos-p          #+#    #+#             */
/*   Updated: 2022/02/05 17:04:35 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	ft_error(char *err)
{
	perror(err);
	exit(1);
}
