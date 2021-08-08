/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:43:29 by lgomez-b          #+#    #+#             */
/*   Updated: 2021/08/07 23:08:21 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*searchPathLine(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (envp[i]);
		i++;
	}
	return (NULL);
}

void	getPath(char *cmd, char *envp[], char **finalPath)
{
	char	**paths;
	char	*path;
	char	*cmdPath;
	int		i;
	int		fd;

	i = 0;
	paths = ft_split(ft_strchr(searchPathLine(envp), '/'), ':');
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		cmdPath = ft_strjoin(path, cmd);
		free(path);
		fd = open(cmdPath, O_RDONLY);
		if (fd >= 0)
		{
			*finalPath = cmdPath;
			close(fd);
			freeArray(paths);
			return ;
		}
		free(cmdPath);
		i++;
	}
	freeArray(paths);
}
