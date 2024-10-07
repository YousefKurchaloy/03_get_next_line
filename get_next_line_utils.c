/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalshish <yalshish@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:34:24 by yalshish          #+#    #+#             */
/*   Updated: 2024/09/30 20:49:09 by yalshish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char		*dup;
	unsigned int	i;

	if (!s1)
		return (NULL);
	dup = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!dup)

		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char		*sub;
	unsigned int	s_len;

	s_len = ft_strlen((char *)s);
	if (!s)
		return ((char *)NULL);
	if (start >= s_len)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	i = 0;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

unsigned int	ft_strchr_index(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char		*res;
	unsigned int	i;
	unsigned int	s1_len;
	unsigned int	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < (s1_len + s2_len))
	{
		res[i] = s2[i - s1_len];
		i++;
	}
	res[i] = 0;
	return (res);
}