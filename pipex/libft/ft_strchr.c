/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:47:50 by lgomez-b          #+#    #+#             */
/*   Updated: 2019/11/12 08:53:55 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/pipex.h"

char	*ft_strchr(const char *s, int c)
{
	char	*aux;

	aux = (char *)s;
	while (*aux != '\0')
	{
		if (*aux == c)
			return (aux);
		else
			aux++;
	}
	if (*aux == 0 && c == 0)
		return (aux);
	else if (c != *aux)
		return (0);
	return (0);
}
