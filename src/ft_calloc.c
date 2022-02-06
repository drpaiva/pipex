/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:51:17 by dramos-p          #+#    #+#             */
/*   Updated: 2022/02/06 00:01:54 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = n;
	while (n)
	{
		((char *)s)[i - n] = '\0';
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*r;

	r = malloc(count * size);
	if (r == NULL)
		return (NULL);
	ft_bzero(r, count * size);
	return (r);
}
