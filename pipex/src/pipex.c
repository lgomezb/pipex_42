/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:36:46 by lgomez-b          #+#    #+#             */
/*   Updated: 2021/08/07 23:58:10 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	freeArray(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

static void	firstCmd(int *fd, char **argv, char **envp)
{
	int		fdIn;
	char	**argvSplitted;
	char	*path;

	close(fd[0]);
	fdIn = open(argv[1], O_RDONLY);
	if (fdIn == -1)
	{
		ft_putstr_fd("no such file or directory", 2);
		exit(0);
	}
	dup2(fdIn, STDIN_FILENO);
	close(fdIn);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	argvSplitted = ft_split(argv[2], ' ');
	getPath(argvSplitted[0], envp, &path);
	if (execve(path, argvSplitted, envp) == -1)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(argvSplitted[0], 2);
		free(path);
		freeArray(argvSplitted);
		exit(0);
	}
}

static	void	secondCmd(int *fd, char **argv, char **envp)
{
	int		fdOut;
	char	**argvSplitted;
	char	*path;

	close(fd[1]);
	fdOut = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, S_IRWXU);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(fdOut, STDOUT_FILENO);
	argvSplitted = ft_split(argv[3], ' ');
	getPath(argvSplitted[0], envp, &path);
	if (execve(path, argvSplitted, envp) == -1)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(argvSplitted[0], 2);
		free(path);
		freeArray(argvSplitted);
		exit(0);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	int		fd[2];

	if (argc != 5)
		perror("Example of use: ./pipex file1 cmd1 cmd2 file2\n");
	else
	{
		pipe(fd);
		pid = fork();
		if (pid == -1)
			perror("Fork Error");
		if (pid == 0)
			firstCmd(fd, argv, envp);
		else
			secondCmd(fd, argv, envp);
		waitpid(pid, NULL, 0);
	}
	return (0);
}
