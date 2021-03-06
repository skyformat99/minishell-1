/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmekwa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 21:55:59 by tmekwa            #+#    #+#             */
/*   Updated: 2017/07/31 13:10:37 by tmekwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		a;
	int		b;
	char	*fresh;
	char	*typcast;
	size_t	n;

	n = ft_strlen(s);
	typcast = (char *)malloc(sizeof(typcast) * (n));
	fresh = (char *)s;
	a = 0;
	b = 0;
	if (!typcast)
		return (NULL);
	while (ft_space(fresh[a]))
		a++;
	while (fresh[a] != '\0')
	{
		typcast[b] = fresh[a];
		a++;
		b++;
	}
	b = b - 1;
	while (ft_space(typcast[b]))
		b--;
	typcast[b + 1] = '\0';
	return (typcast);
}
