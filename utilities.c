/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarrete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:06:20 by pcarrete          #+#    #+#             */
/*   Updated: 2022/11/23 18:06:21 by pcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	compare(char left, char top, char top_left)
{
	char	num_min;

	num_min = top_left;
	if (top <= num_min)
		num_min = top;
	if (left <= num_min)
		num_min = left;
	return (num_min);
}

int	get_first_location(char *map)
{
	int		i;

	i = 0;
	while (map[i] != '\n')
		i++;
	if (map[i] == '\n')
		i++;
	while (map[i] != '\n')
		i++;
	i = i + 2;
	return (i);
}

char	get_symbol_sqr(char *map_original)
{
	int	i;
	int	symb_sqr;

	i = 0;
	while (map_original[i] >= '0' && map_original[i] <= '9')
	{
		i++;
	}
	i = i + 2;
	symb_sqr = map_original[i];
	return (symb_sqr);
}

int	get_ncolumns(char *map)
{
	int	i;
	int	columns;

	i = 0;
	columns = 0;
	while (map[i] != '\n')
		i++;
	i++;
	while (map[i] != '\n')
	{
		columns++;
		i++;
	}
	return (columns + 1);
}
