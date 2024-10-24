/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:44:49 by alex              #+#    #+#             */
/*   Updated: 2024/10/24 14:39:47 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
char *get_buffer(char *buffer, ssize_t bytes_read, int *found);
char	*get_next_line(int fd);
char	**free_all(char **arr);
int	ft_strlen(char *str);
char	*copy_string(char *src);
char **copy_arr(char **arr, char *newstr);

#endif
