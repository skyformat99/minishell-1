/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmekwa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 11:38:05 by tmekwa            #+#    #+#             */
/*   Updated: 2017/09/09 01:51:36 by tmekwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static	void	print_special_char(char c)
{
	if (c == 'n')
		write(1, "\n", 1);
	else if (c == 't')
		write(1, "\t", 1);
	else if (c == '\"')
		write(1, "\"", 1);
}

static void		echo_env(char *line, char **env)
{
	char	*name;
	int		i;
	int		k;
	int		n;

	i = 1;
	k = 0;
	n = 0;
	name = (char*)malloc(sizeof(char) * (ft_strlen(line)));
	while (line[i])
		name[k++] = line[i++];
	name[k] = '\0';
	while (env[n])
	{
		if (ft_strstr(env[n], name) != 0)
		{
			while (env[n][k] != '=')
				k++;
			k++;
			while (env[n][k])
				write(1, &env[n][k++], 1);
		}
		n++;
	}
	write(1, "\n", 1);
}

static	void	print_echo(char *str)
{
	int	i;
	int	quo;

	i = 0;
	quo = (str[i] == '\"') ? 1 : 0;
	i += (str[i] == '\"');
	while (str[i] != '\0')
	{
		if (str[i] == '\\' && str[i + 1] != '\0')
		{
			if (str[i + 1] == '\\')
				i++;
			if (quo == 1)
				print_special_char(str[i + 1]);
			if (quo == 1)
				i += 2;
			else
				i = 1;
		}
		if (str[i] != '\"')
			ft_putchar(str[i]);
		i++;
	}
}

int				sh_echo(char **argv, t_data *p)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (ft_strcmp(argv[i], "echo") == 0)
		i++;
	if (argv[i] && ft_strcmp(argv[i], "-n") == 0)
		n = i++;
	while (argv[i] && argv[i] != NULL)
	{
		if (ft_strchr(argv[i], '$'))
		{
			echo_env(argv[i++], p->g_env);
			return (1);
		}
		print_echo(argv[i]);
		if (argv[i++ + 1] != NULL)
			write(1, " ", 1);
	}
	if (n == 0)
		write(1, "\n", 1);
	else
		ft_putstr("\e[48;5;254m\e[38;5;0m%\e[0m\n");
	return (1);
}
