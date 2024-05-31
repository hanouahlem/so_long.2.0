/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbey <ahbey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:52:55 by ahbey             #+#    #+#             */
/*   Updated: 2024/05/31 20:41:29 by ahbey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char *str)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	line = "d";
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			count++;
		free(line);
	}
	close(fd);
	return (count);
}

char	**stock_map(t_game *game, char *str)
{
	int		fd;
	char	**tab;
	int		i;

	i = 0;
	game->nb_line = count_line(str);
	if (game->nb_line == 0)
		return (NULL);
	tab = malloc(sizeof(char *) * (game->nb_line + 1));
	if (!tab)
		return (NULL);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nFile invalide\n"), exit(1), NULL);
	while (i < game->nb_line)
	{
		tab[i] = get_next_line(fd);
		i++;
	}
	tab[i] = 0;
	free(get_next_line(fd));
	close(fd);
	return (tab);
}
