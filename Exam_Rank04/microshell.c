/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwen <gwen@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:10:31 by gwen              #+#    #+#             */
/*   Updated: 2024/04/09 15:32:23 by gwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : microshell
Expected files   : microshell.c
Allowed functions: malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp
--------------------------------------------------------------------------------------

Write a program that will behave like executing a shell command
- The command line to execute will be the arguments of this program
- Executable's path will be absolute or relative but your program must not build a path (from the PATH variable for example)
- You must implement "|" and ";" like in bash
	- we will never try a "|" immediately followed or preceded by nothing or "|" or ";"
- Your program must implement the built-in command cd only with a path as argument (no '-' or without parameters)
	- if cd has the wrong number of argument your program should print in STDERR "error: cd: bad arguments" followed by a '\n'
	- if cd failed your program should print in STDERR "error: cd: cannot change directory to path_to_change" followed by a '\n' with path_to_change replaced by the argument to cd
	- a cd command will never be immediately followed or preceded by a "|"
- You don't need to manage any type of wildcards (*, ~ etc...)
- You don't need to manage environment variables ($BLA ...)
- If a system call, except execve and chdir, returns an error your program should immediatly print "error: fatal" in STDERR followed by a '\n' and the program should exit
- If execve failed you should print "error: cannot execute executable_that_failed" in STDERR followed by a '\n' with executable_that_failed replaced with the path of the failed executable (It should be the first argument of execve)
- Your program should be able to manage more than hundreds of "|" even if we limit the number of "open files" to less than 30.

for example this should work:
$>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
microshell
i love my microshell
$>

Hints:
Don't forget to pass the environment variable to execve

Hints:
Do not leak file descriptors!*/


#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int	ft_error(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (1);
}

int	ft_cd(char *argv[], int i)
{
	if (i != 2)
		return (ft_error("error: cd: bad arguments\n"));
	else if (chdir(argv[1]) == -1)
		return (ft_error("error: cd: cannot change directory to "), ft_error(argv[1]), ft_error("\n"));
	return (0);
}

int	ft_exec(char *argv[], char *env[], int i)
{
	int	fd[2];
	int	status;
	int	is_pipe;
	int	pid;

	is_pipe = argv[i] && !strcmp(argv[i], "|");
	if (is_pipe && pipe(fd) == -1)
		return (ft_error("error: fatal\n"));
	pid = fork();
	if (pid == 0)
	{
		argv[i] = 0;
		if (is_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return (ft_error("error: fatal\n"));
		execve(*argv, argv, env);
		return (ft_error("error: cannot execute "), ft_error(argv[i]), ft_error("\n"));
	}
	waitpid(pid, &status, 0);
	if (is_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return (ft_error("error: fatal\n"));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int argc, char *argv[], char *env[])
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	if (argc > 1)
	{
		while (argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
				i++;
			if (!strcmp(*argv, "cd"))
				status = ft_cd(argv, i);
			else if (i)
				status = ft_exec(argv, env, i);
		}
	}
	return (status);
}
