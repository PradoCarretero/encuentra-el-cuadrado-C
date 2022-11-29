/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajimene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:26:11 by sajimene          #+#    #+#             */
/*   Updated: 2022/11/23 16:39:27 by sajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char	compare(char left, char top, char top_left);
int		get_first_location(char *map);
char	get_symbol_sqr(char *map_original);

void	map_solver(char *map, int ncolumns)
{
	char	top;
	char	left;
	char	top_left;
	char	num_min;
	int		i;

	i = get_first_location(map);
	while (map[i])
	{
		if (map[i] == '\n')
			i = i + 2;
		left = map[i - 1];
		top = map[i - ncolumns];
		top_left = map[i - ncolumns - 1];
		num_min = compare(left, top, top_left);
		if (map[i] != '0')
			map[i] = map[i] + (num_min - '0');
		i++;
	}
}

int	find_max(char *map, char ncolumns)
{
	char	max_num;
	char	max_loc;
	int		i;

	i = 0;
	while (map[i] != '\n')
		i++;
	i++;
	max_num = map[i];
	while (map[i])
	{
		if (map[i + 1] > max_num)
		{
			max_num = map[i + 1];
			max_loc = i + 1;
		}
		i++;
	}
	return (max_loc);
}

void	print_sqr(char *map_original)
{
	int	i;

	i = 0;
	while (map_original[i] != '\n')
		i++;
	if (map_original[i] == '\n')
		i++;
	while (map_original[i])
	{
		write(1, &map_original[i], 1);
		i++;
	}
}

void	find_sqr(int max_loc, int ncolumns, char *map_original, char *map)
{
	char	size_sqr;
	int		x;
	int		y;
	int		i;
	int		current_location;

	i = max_loc;
	size_sqr = map[max_loc];
	size_sqr = size_sqr - '0';
	x = size_sqr;
	y = size_sqr;
	while (y > 0)
	{
		while (x > 0)
		{
			map_original[i] = get_symbol_sqr(map_original);
			i--;
			x--;
		}
		x = size_sqr;
		i = (i + x) - ncolumns;
		y--;
	}
	print_sqr(map_original);
}
