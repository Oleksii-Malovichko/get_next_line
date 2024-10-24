/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:44:45 by alex              #+#    #+#             */
/*   Updated: 2024/10/24 14:58:08 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	**free_all(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

int	ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*copy_string(char *src)
{
	char *dest;
	int	src_len;
	int i;

	i = 0;
	src_len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!dest)
		return (NULL);
	while (src[i] != '\0' && i < src_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[src_len] = '\0';
	return (dest);
}

char **copy_arr(char **arr, char *newstr)
{
	char **temp;
	int q_elem;

	q_elem = 0;
	if (!arr)
	{
		temp = (char **)malloc(sizeof(char *) * 2);
		if (!temp)
			return (NULL);
		temp[0] = copy_string(newstr);
		if (!temp[0])
		{
			free(temp);
			return (NULL);
		}
		temp[1] = NULL;
		return (temp);
	}
	while (arr[q_elem] != NULL)
		q_elem++;
	temp = (char **)malloc(sizeof(char *) * (q_elem + 2));
	if (!temp)
		return (NULL);
	q_elem = 0;
	while (arr[q_elem] != NULL)
	{
		temp[q_elem] = copy_string(arr[q_elem]);
		if (!temp[q_elem])
			return (free_all(temp));
		q_elem++;
	}
	temp[q_elem] = copy_string(newstr);
	if (!temp[q_elem])
		return (free_all(temp));
	temp[q_elem + 1] = NULL;
	free_all(arr);
	return (temp);
}
