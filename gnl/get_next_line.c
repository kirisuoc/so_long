/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:35:13 by erikcousill       #+#    #+#             */
/*   Updated: 2024/11/29 15:48:54 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	has_newline(char *string)
{
	while (string && *string != '\0')
	{
		if (*string == '\n')
			return (1);
		string++;
	}
	return (0);
}

static char	*problem_reading(char *buffer, char **remainder)
{
	char	*line;

	free(buffer);
	if (*remainder && **remainder != '\0')
	{
		line = extract_line(*remainder);
		*remainder = update_remainder(*remainder);
		return (line);
	}
	free(*remainder);
	*remainder = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*remainder;
	int			bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!has_newline(remainder))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (problem_reading(buffer, &remainder));
		buffer[bytes_read] = '\0';
		remainder = join_strings(remainder, buffer);
		if (!remainder)
			return (free_memory(remainder));
	}
	free (buffer);
	line = extract_line(remainder);
	remainder = update_remainder(remainder);
	return (line);
}
