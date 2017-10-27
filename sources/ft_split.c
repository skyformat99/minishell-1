/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmekwa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 10:24:48 by tmekwa            #+#    #+#             */
/*   Updated: 2017/09/10 14:45:28 by tmekwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		count_words(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		while (*str && (*str == ' ' || *str == '\n' || *str == '\t'))
			str++;
		if (*str && *str != ' ' && *str != '\n' && *str != '\t')
		{
			i++;
			while (*str && *str != ' ' && *str != '\n' && *str != '\t')
				str++;
		}
	}
	return (i);
}

static char		*malloc_word(char *str)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_split(char *str)
{
	int		words;
	char	**tab;
	int		i;

	words = count_words(str);
	tab = (char **)malloc(sizeof(char*) * (words + 1));
	i = 0;
	while (*str)
	{
		while (*str && (*str == ' ' || *str == '\n' || *str == '\t'))
			str++;
		if (*str && *str != ' ' && *str != '\n' && *str != '\t')
		{
			tab[i] = malloc_word(str);
			i++;
			while (*str && *str != ' ' && *str != '\n' && *str != '\t')
				str++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
