/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:14:59 by abenheni          #+#    #+#             */
/*   Updated: 2022/12/19 19:15:01 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	my_error(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

char	*get_path(char *env[])
{
	int	i;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			return (env[i] + 5);
		}
		i++;
	}
	return (NULL);
}

void	my_free(char *leak[])
{
	int	i;

	i = 0;
	while (leak[i])
	{
		free(leak[i]);
		i++;
	}
	free(leak);
}

char	*check_path(char *paths[], char *commands[])
{
	int		i;
	char	*var1;
	char	*ful;

	i = 0;
	while (paths[i])
	{
		var1 = ft_strjoin("/", commands[0]);
		ful = ft_strjoin(paths[i++], var1);
		if (access(ful, F_OK) == 0)
			return (ful);
		free(ful);
		free(var1);
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (p1[i] && p2[i] && p1[i] == p2[i] && i < n - 1)
	{
		i++;
	}
	return (p1[i] - p2[i]);
}
