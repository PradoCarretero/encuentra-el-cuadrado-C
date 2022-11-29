/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajimene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:39:57 by sajimene          #+#    #+#             */
/*   Updated: 2022/11/23 16:48:46 by sajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void	map_solver(char *map, int ncolumns);
int		find_max(char *map, char ncolumns);
void	find_sqr(int max_loc, int ncolumns, char *map_original, char *map);
int		get_ncolumns(char *map);
char	map_prepare(char *map);

int	check_arg(int argc)
{
	if (argc < 2)
	{
		write(1, "Please introduce an argument", 29);
		return (0);
	}
	return (1);
}

char	*open_map_original(char **argv)
{
	int		fd;
	int		i;
	char	*map_original;

	map_original = malloc(1000);
	if (map_original == NULL)
	{
		write(1, "Problem found saving data", 26);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	if (read(fd, map_original, 1000) == -1)
		write(1, "Problem found reading document", 31);
	close(fd);
	return (map_original);
}

char	*open_map(char **argv)
{
	int		fd;
	int		i;
	char	*map;

	map = malloc(1000);
	if (map == NULL)
	{
		write(1, "Problem found saving data", 26);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	if (read(fd, map, 1000) == -1)
		write(1, "Problem found reading document", 31);
	close(fd);
	return (map);
}

int	main(int argc, char **argv)
{
	char	*map;
	char	*map_original;
	int		ncolumns;
	char	max_loc;
	int		locat_max;

	(void)argc;
	if (check_arg(argc) == 0)
		return (0);
	map_original = open_map_original(argv);
	map = open_map(argv);
	map_prepare(map);
	ncolumns = get_ncolumns(map);
	map_solver(map, ncolumns);
	max_loc = find_max(map, ncolumns);
	find_sqr(max_loc, ncolumns, map_original, map);
	free(map);
	return (0);
}
