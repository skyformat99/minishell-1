/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmekwa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 11:37:49 by tmekwa            #+#    #+#             */
/*   Updated: 2017/09/09 00:28:06 by tmekwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		sh_cd(char **argv)
{
	if (argv[1] == NULL || ft_strcmp("~", argv[1]) == 0)
	{
		if (chdir(HOME) != 0)
			ft_putstr("HOME");

	}
	else
	{
		if (chdir(argv[1]) != 0)
		{
			ft_putstr("cd: no such file or directory: ");
			ft_putstr(argv[1]);
			ft_putstr("\n");
		}
	}
	return (1);
}
