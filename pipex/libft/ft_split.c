/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:39:35 by lgomez-b          #+#    #+#             */
/*   Updated: 2021/08/08 00:05:45 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/pipex.h"

static	int	nb_words(char const *s, char c, int *lenght)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			nb += 1;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	*lenght = i;
	return (nb);
}

static	int	set_word(char **out, int nb, int j, int i)
{
	out[nb] = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!out[nb])
	{
		while (out[nb++] != NULL)
		{
			free(out[nb]);
		}
		free(out);
		return (0);
	}
	else
	{
		return (1);
	}
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		nb;
	char	**out;

	i = 0;
	nb = nb_words(s, c, &i);
	out = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!out || nb == -1)
		return (NULL);
	out[nb] = NULL;
	while (i-- >= 0)
	{
		if (s[i] != c)
		{
			j = i;
			while (i >= 0 && s[i] != c)
				i--;
			nb--;
			if (set_word(out, nb, j, i) == 0)
				return (NULL);
			ft_strlcpy(out[nb], &s[i + 1], (j - i + 1));
		}
	}
	return (out);
}
