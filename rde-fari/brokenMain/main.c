/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:11:33 by rde-fari          #+#    #+#             */
/*   Updated: 2025/10/14 19:35:36 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debugSession.h"

int main(void)
{
	char **result;
	int i;

	i = 0;
	printf("Testing ft_split with indexes:\n");

	// Test 1: Normal case
	result = ft_split("hello,world,test", ',');
	if (result)
	{
		printf("Test 1 - Split 'hello,world,test' by ',':\n");
		i = 0;
		while (result[i])
		{
			printf("  [%d]: '%s'\n", i, result[i]);
			free(result[i]);
			i++;
		}
		free(result);
	}

	// Test 2: Multiple delimiters
	result = ft_split("  hello   world  test  ", ' ');
	if (result)
	{
		printf("\nTest 2 - Split '  hello   world  test  ' by ' ':\n");
		i = 0;
		while (result[i])
		{
			printf("  [%d]: '%s'\n", i, result[i]);
			free(result[i]);
			i++;
		}
		free(result);
	}

	// Test 3: Empty string
	result = ft_split("", ',');
	if (result)
	{
		printf("\nTest 3 - Split empty string:\n");
		printf("  Result is empty array (as expected)\n");
		free(result);
	}

	return (0);
}
