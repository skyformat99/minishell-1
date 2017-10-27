/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmekwa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 08:59:38 by tmekwa            #+#    #+#             */
/*   Updated: 2017/08/21 18:25:07 by tmekwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*sh_realloc(char *str2)
{
	char	*nstr;

	if (str2 == NULL)
		return (NULL);
	nstr = (char *)malloc(sizeof(char) * ft_strlen(str2));
	ft_strcpy(nstr, str2);
	return (nstr);
}
