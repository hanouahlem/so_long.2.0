/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbey <ahbey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:26:28 by ahbey             #+#    #+#             */
/*   Updated: 2024/05/29 13:12:16 by ahbey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_name_map(char *str)
{
	int	len;
	int	i;

	len = ft_strlen_name(str) - 1;
	i = 0;
	if (str[len] == 'r')
		i++;
	if (str[len - 1] == 'e')
		i++;
	if (str[len - 2] == 'b')
		i++;
	if (str[len - 3] == '.')
		i++;
	if (i == 4)
		return (1);
	else
	{
		ft_printf("Error\nFile's name is not valid !\n");
		return (0);
	}
}
