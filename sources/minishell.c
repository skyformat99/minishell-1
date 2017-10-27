/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmekwa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 08:08:48 by tmekwa            #+#    #+#             */
/*   Updated: 2017/09/09 00:27:20 by tmekwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_delarray(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_strdel(&array[i]);
		i++;
	}
	free(array);
}

int		main(int argc, char **argv, char **env)
{
	t_data		p;
	char		*line;
	char		**arg;

	argv = NULL;
	argc = 1;
	ft_env_loop(env, &p);
	ft_putstr("             THATO MEKWA               ");
	ft_putstr("              MINISHELL                ");
	ft_putstr("                 42                    ");
	ft_putchar('\n');
	while (argc)
	{
		ft_putstr("\033[33;36m");
		ft_putstr("minishell$>");
		if (get_next_line(0, &line) < 0)
			ft_putstr("error");
		arg = ft_split(line);
		ft_strdel(&line);
		argc = sh_execute(arg, &p);
		line = NULL;
		ft_delarray(arg);
	}
	ft_delarray(p.g_env);
	return (0);
}
