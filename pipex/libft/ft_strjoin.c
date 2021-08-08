/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:13:30 by lgomez-b          #+#    #+#             */
/*   Updated: 2021/08/08 00:06:52 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/pipex.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	int		i;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = ((char *)malloc((len1 + len2 + 1) * sizeof(char)));
	if (!s3)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		s3[i] = s1[i];
		i++;
	}
	i = -1;
	while (i++ < len2)
		s3[len1 + i] = s2[i];
	s3[len1 + i] = '\0';
	return (s3);
}
