/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_prepare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajimene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:22:44 by sajimene          #+#    #+#             */
/*   Updated: 2022/11/23 16:25:20 by sajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char	*map_prepare(char *map)
{
	int		i;
	char	vaccum;
	char	obst;
	char	*original_map;

	i = 0;
	while (map[i] >= '0' && map[i] <= '9')
	{
		i++;
	}
	vaccum = map[i];
	obst = map[i + 1];
	i = i + 2;
	while (map[i])
	{
		if (map[i] == vaccum)
			map[i] = '1';
		if (map[i] == obst)
			map[i] = '0';
		i++;
	}
	return (map);
}
