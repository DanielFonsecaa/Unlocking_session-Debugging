/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:15:05 by rde-fari          #+#    #+#             */
/*   Updated: 2025/10/14 20:33:23 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debugSession.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	unsigned char *call;
	size_t i;

	call = malloc(size * nmemb);
	if (!call)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
	{
		call[i] = 0;
		i++;
	}
	return (call);
}

char *ft_substr(char const *s, int start, size_t len)
{
	size_t i;
	char *substr;

	if (!s || start >= ft_strlen(s) || len == 0)
	{
		substr = ft_calloc(sizeof(char), 1);
		return (substr);
	}
	if (((unsigned int)ft_strlen(s) - start) < len)
		len = ft_strlen(s + start);
	substr = ft_calloc(sizeof(char), (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}

int ft_strlen(const char *string)
{
	size_t i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}
void	ft_print_array_n_size(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		printf("Array index [%d] = %s\n", i, array[i]);
		free(array[i]);
		i++;
	}
	free(array);
	printf("Array size = %d\n", i + 1);
}
