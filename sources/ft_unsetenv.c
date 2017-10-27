/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmekwa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 11:37:41 by tmekwa            #+#    #+#             */
/*   Updated: 2017/09/09 01:56:29 by tmekwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_unsetenv(char **env, char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	if (str == NULL)
		ft_putstr("unsetenv: not enough arguments.\n");
	else
	{

		while (env[nbr])
			nbr++;
		while (env[i])
		{
			if (ft_strncmp(env[i], str, ft_strlen(str) - 1) == 0)
			{
				while (i < nbr - 1)
				{
					env[i] = sh_realloc(env[i + 1]);
					i++;
				}
				if (env[i] != NULL)
					env[i] = sh_realloc(NULL);
			}
			i++;
		}
	}
	return (1);
}
