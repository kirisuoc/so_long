/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:48:20 by ecousill          #+#    #+#             */
/*   Updated: 2024/11/11 15:03:42 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir el archivo");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

char	**allocate_memory(size_t size, char *error_message)
{
	char	**ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		perror(error_message);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

size_t	ft_linelen(char *s)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != '\n')
		len++;
	return (len);
}

int	check_map_name(char *s)
{
	size_t	l;

	l = ft_strlen(s) - 1;
	if (s[l] = 'r' && s[l - 1] == 'e' && s[l - 2] == 'b' && s[l - 3] == '.')
		return (0);
	return (1);
}
