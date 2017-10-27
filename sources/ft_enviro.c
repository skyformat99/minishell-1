/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 11:38:13 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/09/09 00:36:43 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_env(char **env)
{
	while (*env != NULL)
	{
		ft_putstr(*env);
		write(1, "\n", 1);
		env++;
	}
	return (1);
}

int		ft_env_loop(char **env, t_data *p)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	p->g_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		p->g_env[i] = ft_strdup(env[i]);
		i++;
	}
	return (1);
}
