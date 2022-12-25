/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:15:53 by abenheni          #+#    #+#             */
/*   Updated: 2022/12/19 19:15:55 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

static char	*ft_strcpy(char *dst, const char *src)
{
	while (*src)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return (dst);
}

static char	*ft_strcat(char *s1, const char *s2)
{
	s1 = s1 + ft_strlen(s1);
	while (*s2)
	{
		*s1++ = *s2++;
	}
	*s1 = '\0';
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (p == NULL)
	{
		return (NULL);
	}
	ft_strcpy(p, s1);
	ft_strcat(p, s2);
	return (p);
}
