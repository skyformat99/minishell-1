/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmekwa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 08:07:04 by tmekwa            #+#    #+#             */
/*   Updated: 2017/08/31 13:34:01 by tmekwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define HOME 		"/goinfre/mnaidoo"
# define BUFF_SIZE 	1000

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <dirent.h>

typedef struct		s_data
{
	char			*old_pwd;
	char			*new_pwd;
	char			**g_env;
}					t_data;

int					sh_execute(char **args, t_data *p);
int					sh_cd(char **args);
int					sh_exit(char **args);
int					sh_clear(void);
int					ft_env(char **env);
int					ft_env_loop(char **env, t_data *p);
int					sh_launch(char **args, char **envp);
int					sh_echo(char **argv, t_data *p);
void				clean_up(char **dir, char *n, char *tmp);
char				*sh_realloc(char *str);
int					ft_unsetenv(char **env, char *str);
char				*ft_path_finder(char **p, char **n);
void				sh_cleaner(char **dir, char *n, char *tmp);
char				*sh_path(char **p, char **n);

char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					get_next_line(int const fd, char **line);
char				*ft_strdup(const char *s1);
void				ft_putstr(const char *s);
size_t				ft_strlen(const char *s);
void				ft_putchar(char c);
void				ft_strdel(char **as);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *big, const char *little);
void				sh_increase_array(char *str, t_data *p);
void				ft_delarray(char **array);
char				**ft_arraydup(char **env);
int					sh_setenv(char *arg, t_data *p);
char				**ft_sstrnew(size_t size);
int					ft_sstrlen(char **s);
char				**ft_split(char *str);

#endif
