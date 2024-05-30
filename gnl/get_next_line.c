/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbey <ahbey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:49:13 by ahbey             #+#    #+#             */
/*   Updated: 2024/05/02 19:16:38 by ahbey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	pos_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (-1);
}

char	*ft_cut(char *buffer)
{
	char	*str;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		str[i] = buffer[i];
	if (buffer[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*read_line(int fd, char *buffer)
{
	char	*stock;
	int		size;

	size = 1;
	stock = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!stock)
		return (NULL);
	while ((pos_nl(buffer) == -1) && size > 0)
	{
		size = read(fd, stock, BUFFER_SIZE);
		if (size < 0)
		{
			free(stock);
			return (NULL);
		}
		stock[size] = '\0';
		buffer = ft_strjoin(buffer, stock);
		if (!buffer)
			return (free(stock), NULL);
	}
	free(stock);
	return (buffer);
}

char	*ft_clean(char *buffer)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (buffer[0] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if ((buffer)[i] != '\0')
		i++;
	j = 0;
	while ((buffer)[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (read_line(fd, buffer));
	if (!buffer)
		return (NULL);
	line = ft_cut(buffer);
	if (line == NULL)
		return (free(buffer), NULL);
	buffer = ft_clean(buffer);
	if (!buffer)
		return (free(line), NULL);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*chaine;

// 	fd = open("test.txt", O_RDONLY);
// 	chaine = get_next_line(fd);
// 	while (chaine)
// 	{
// 		printf("%s\n", chaine);
// 		free(chaine);
// 		chaine = get_next_line(fd);
// 	}
// 	close(fd);
// }
