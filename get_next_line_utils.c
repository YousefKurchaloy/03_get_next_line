/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalshish <yalshish@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:15:56 by yalshish          #+#    #+#             */
/*   Updated: 2024/12/11 23:06:52 by yalshish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// This function counts the number of characters in the string s.
// It returns 0 if the string is NULL.
// else it iterates through the string and counts the characters.
// till it reaches the null terminator.
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

// This function searches for the first occurrence of the character c.
// It returns a pointer to the character
// or NULL if the character is not found.
char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
		if (!*s++)
			return (NULL);
	return ((char *)s);
}

// This function creates a new string from the string s.
// It returns NULL if the string s is NULL or if the length is 0,
// or if the start index is greater than the length of the string.
// It starts from the index start and copies len characters.
// If the length of the string is less than len:
// it will copy the whole string.
// else:
// it will copy len characters.
// + 1 for the null terminator.
// It returns the new string.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*src;
	size_t	reslen;

	if (!s || ft_strlen(s) < (size_t)start || len == 0)
		return (NULL);
	src = s + start;
	if (ft_strlen(src) < len)
		reslen = ft_strlen(src) + 1;
	else
		reslen = len + 1;
	res = malloc(reslen);
	if (!res)
		return (NULL);
	ft_strlcpy(res, src, reslen);
	return (res);
}

// This function copies the string src to the string dst.
// It copies at most (size - 1) characters from src to dst.
// If the size is 0 it will return the length of the string src.
// It returns the length of the string src.
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

// This function joins 2 strings together,
// it only returns NULL when the malloc fails.
// It also reproduces the behaviour of ft_strdup("")
// where if the string is NULL it will allocate 2 bytes to make an empty string.
// The allocation is for:
// Sum of the lengths of the 2 strings + 1 for the null terminator.
// If the allocation fails it will free the first string and return NULL.
// It also frees the first string passed as an argument.
// It returns the new string.
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(2);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}
