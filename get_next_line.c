/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:44:53 by alex              #+#    #+#             */
/*   Updated: 2024/10/24 14:56:23 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 5
// char	**make_general_buffer(char **general_buffer, char *ready_buffer, char **temp)
// {
// 	int	q_elem;
// 	int	i;

// 	// while ()
// }

// char	**make_memory_general_buffer(char **general_buffer, char *ready_buffer)
// {
// 	char	**temp;
// 	int	q_elem;
// 	int	i;
// 	int	len_buffer;

// 	q_elem = 0;
// 	while (general_buffer[q_elem] != NULL)
// 		q_elem++;
// 	temp = (char **)malloc(sizeof(char *) * (q_elem + 2));
// 	if (!temp)
// 		return (NULL);
// 	temp[q_elem + 1] = NULL;
// 	q_elem = 0;
// 	while (general_buffer[q_elem] != NULL)
// 	{
// 		i = 0;
// 		while (general_buffer[q_elem][i] != '\0')
// 			i++;
// 		temp[q_elem][i] = (char *)malloc(sizeof(char) * (i + 1));
// 		if (!temp[q_elem][i])
// 			return (clean_all(temp));
// 		temp[q_elem][i] = '\0';
// 		q_elem++;
// 	}
// 	return (make_genral_buffer(general_buffer, ready_buffer, temp));
// }

// /* 
// скопировать содержимое буфера в temp
// добавить буферу места на +1 строку
// перекинуть все данные из temp обратно в буфер */

char *get_buffer(char *buffer, ssize_t bytes_read, int *found)
{
	char	*result;
	int		i;
	int		j;

	j = 0;
	i = 0;
	result = NULL;
	while (i < (int)bytes_read)
	{
		if (buffer[i] == '\n')
		{
			*found = 1;
			break ;
		}
		i++;
	}
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	while (j < i)
	{
		result[j] = buffer[j];
		j++;
	}
	result[i] = '\0';
	return (result);
}

int	q_symbols(char **general_buffer)
{
	int		i_elem;
	int		counter;

	i_elem = 0;
	counter = 0;
	while (general_buffer[i_elem] != NULL)
	{
		counter += ft_strlen(general_buffer[i_elem]);
		i_elem++;
	}
	return (counter);
}

char	*ft_join_buffer(char **general_buffer)
{
	int	q_sym;
	int i_elem;
	int	i;
	char	*result;

	q_sym = q_symbols(general_buffer);
	result = (char *)malloc(sizeof(char) * (q_sym + 1));
	if (!result)
		return (NULL);
	i_elem = 0;
	q_sym = 0;
	while (general_buffer[i_elem] != NULL)
	{
		i = 0;
		while (general_buffer[i_elem][i] != '\0')
		{
			result[q_sym] = general_buffer[i_elem][i];
			q_sym++;
			i++;
		}
		i_elem++;
	}
	result[q_sym] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*ready_buffer;
	char	**general_buffer;
	ssize_t	bytes_read;
	int		found;

	found = 0;
	general_buffer = NULL;
	while (1)
	{
		if (found)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(general_buffer);
			return (NULL);
		}
		if (bytes_read == 0 && !general_buffer)
			return (NULL);
		ready_buffer = get_buffer(buffer, bytes_read, &found);
		if (!ready_buffer)
		{
			free(general_buffer);
			return (NULL);
		}
		general_buffer = copy_arr(general_buffer, ready_buffer);
		free(ready_buffer);
	}
	return (ft_join_buffer(general_buffer));
}

int main()
{
	int fd = open("/home/alex/42_leraning/get_next_line/text", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	// for (int i = 0; result[i] != NULL; i++)
	// {
		// printf("%s\n", result[i]);
	// }
}