/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:55:02 by lgomez-b          #+#    #+#             */
/*   Updated: 2021/08/07 22:54:37 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/pipex.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int		cont;
	int					size;
	unsigned char		*aux1;
	unsigned char		*aux2;

	aux1 = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	cont = 0;
	while ((aux1[cont] != '\0' || aux2[cont] != '\0') && cont < n)
	{
		size = aux1[cont] - aux2[cont];
		if (size != 0)
			return (size);
		cont++;
	}
	return (0);
}
