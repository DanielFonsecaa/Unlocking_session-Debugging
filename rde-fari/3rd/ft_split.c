/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:34:25 by rde-fari          #+#    #+#             */
/*   Updated: 2025/10/14 19:35:58 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debugSession.h"

static size_t ft_count_words(const char *string, char delim)
{
	size_t index;
	size_t word_count;

	index = 0;
	word_count = 0;
	while (string[index])
	{
		while (string[index] == delim && string[index])
			index++;
		if (string[index] != delim && string[index])
		{
			word_count++;
			while (string[index] != delim && string[index])
				index++;
		}
	}
	return (word_count);
}

static size_t ft_wordlen(char const *string, size_t start_index, char delim)
{
	size_t len;
	size_t index;

	len = 0;
	index = start_index;
	while (string[index] != delim && string[index])
	{
		len++;
		index++;
	}
	return (len);
}

static void ft_clean(char **split, size_t i)
{
	size_t n;

	n = 0;
	while (n < i)
		free(split[n++]);
	free(split);
}

static char **ft_splitting(char **split, char const *s, char c)
{
	size_t len;
	size_t i;
	size_t index;

	i = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] == c && s[index])
			index++;
		if (s[index] != c && s[index])
		{
			len = ft_wordlen(s, index, c);
			split[i] = ft_substr(s, index, len);
			if (!split[i])
			{
				ft_clean(split, i);
				return (NULL);
			}
			index += len;
			i++;
		}
	}
	return (split);
}

char **ft_split(char const *s, char c)
{
	char **split;
	size_t wc;

	if (!s)
		return (NULL);
	wc = ft_count_words(s, c);
	split = (char **)ft_calloc(wc + 1, sizeof(char *));
	if (!split)
		return (NULL);
	split = ft_splitting(split, s, c);
	if (!split)
		return (NULL);
	return (split);
}
