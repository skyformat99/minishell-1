/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmekwa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 10:27:51 by tmekwa            #+#    #+#             */
/*   Updated: 2017/09/09 01:54:39 by tmekwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static	char		**split_path(char *path)
{
	char	**arr;
	char	**tmp;

	tmp = ft_strsplit(path, '=');
	arr = ft_strsplit(tmp[1], ':');
	free(path);
	ft_delarray(tmp);
	return (arr);
}

void				sh_cleaner(char **dir, char *n, char *tmp)
{
	int		i;

	i = 0;
	free(tmp);
	free(n);
	while (dir[i++])
		free(dir[i]);
	free(dir);
}

static	char		*sh_locate_path(char **path)
{
	int		i;

	i = 0;
	while (path[i] != '\0')
	{
		if (ft_strncmp(path[i], "PATH", 4) == 0)
			return (path[i]);
		i++;
	}
	return (NULL);
}

char				*sh_path(char **p, char **n)
{
	char	**dir;
	char	*d;
	char	*tmp;
	char	*p_t;
	int		i;

	if (access(*n, F_OK) == 0)
		return (*n);
	p_t = sh_locate_path(p);
	dir = split_path(p_t);
	i = 0;
	d = ft_strjoin("/", *n);
	if (dir == NULL)
		return (NULL);
	while (dir[i] != NULL)
	{
		tmp = ft_strjoin(dir[i], d);
		if (access(tmp, X_OK) != -1)
			return (tmp);
		ft_strdel(&tmp);
		i++;
	}
	ft_delarray(dir);
	free(d);
	return (NULL);
}
