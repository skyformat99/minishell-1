/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmekwa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 18:01:21 by tmekwa            #+#    #+#             */
/*   Updated: 2017/06/30 18:49:16 by tmekwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		readmethod(const int fd, char **line)
{
	int		i;
	char	*needle;
	char	*buffer;

	buffer = (char *)malloc(sizeof(*buffer) * (BUFF_SIZE + 1));
	i = ft_strlen(needle);
	if (!buffer)
		return (-1);
	i = read(fd, buffer, BUFF_SIZE);
	if (i > 0)
	{
		buffer[i] = '\0';
		needle = ft_strjoin(*line, buffer);
		if (!(needle))
			return (-1);
		free(*line);
		*line = needle;
	}
	if (buffer)
		free(buffer);
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static char *str = NULL;
	int			i;
	char		*temp;

	if (!line || (!str && (str = (char *)malloc(sizeof(*str))) == NULL))
		return (-1);
	temp = ft_strchr(str, '\n');
	while (temp == NULL)
	{
		if ((i = readmethod(fd, &str)) == 0)
		{
			if (ft_strlen(str) == 0)
				return (0);
			str = ft_strjoin(str, "10");
		}
		if (i < 0)
			return (-1);
		else
			temp = ft_strchr(str, '\n');
	}
	*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(temp));
	temp = ft_strdup(temp + 1);
	free(str);
	str = temp;
	return (1);
}
