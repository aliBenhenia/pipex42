/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:14:42 by abenheni          #+#    #+#             */
/*   Updated: 2022/12/19 19:14:44 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>

void	pipex(char ac, char *av[], char *env[]);
void	my_error(char *s);
void	my_free(char *leak[]);
void	first_cmnd(int *fd, char *av[], char *env[]);
void	sc_command(int *fd, char *av[], char *env[]);
void	excuter(char *cmd, char *env[]);
char	*get_path(char *env[]);
char	*check_path(char *paths[], char *commands[]);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif