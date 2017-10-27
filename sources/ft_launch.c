/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmekwa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 14:57:42 by tmekwa            #+#    #+#             */
/*   Updated: 2017/08/30 14:32:43 by tmekwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		sh_launch(char **args, char **envp)
{
	pid_t		pid;
	int			status;
	char		*tmp;

	pid = fork();
	if (pid == 0)
	{
		tmp = sh_path(envp, args);
		execve(tmp, args, envp);
		ft_putstr("zsh: command not found: ");
		ft_putstr(args[0]);
		ft_putstr("\n");
		free(tmp);
		exit(0);
	}
	else
		waitpid(pid, &status, WUNTRACED);
	return (1);
}