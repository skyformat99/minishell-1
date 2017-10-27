/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmekwa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 09:08:31 by tmekwa            #+#    #+#             */
/*   Updated: 2017/06/24 20:33:38 by tmekwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 15
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

int			get_next_line(const int fd, char **line);
#endif
