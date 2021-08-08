/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:10:57 by lgomez-b          #+#    #+#             */
/*   Updated: 2021/08/07 22:54:25 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/pipex.h"

void	ft_putendl_fd(char *s, int fd)
{
	void	*a;

	if (s)
	{
		while (*s != '\0')
		{
			a = s;
			write(fd, a, 1);
			s++;
		}
		write(fd, "\n", 1);
	}
}