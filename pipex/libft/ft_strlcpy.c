/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:22:48 by lgomez-b          #+#    #+#             */
/*   Updated: 2019/11/13 09:14:22 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/pipex.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		cnt;
	size_t		lens;

	if (!dst)
		return (dstsize);
	lens = ft_strlen((char *)src);
	if (dstsize == 0)
		return (lens);
	cnt = 0;
	while (dstsize > cnt + 1 && src[cnt])
	{
		dst[cnt] = src[cnt];
		cnt++;
	}
	dst[cnt] = 0;
	return (lens);
}
