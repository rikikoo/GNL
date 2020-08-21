/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:24:25 by rkyttala          #+#    #+#             */
/*   Updated: 2019/11/20 17:48:36 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int				main(int argc, char **argv)
{
	char	**arr;
	int		fd;
	int		ret;

	if (argc > 2)
		return (0);
	if ((arr = (char**)malloc(sizeof(char*) * 2)) == NULL)
		return (0);
	arr[1] = NULL;
	fd = open(argv[1], O_RDONLY);
	if (argc == 1)
		fd = 0;
	while ((ret = get_next_line(fd, &arr[0])))
	{
		if (ret == -1)
			return (-1);
		ft_putnbr(ret);
		ft_putstr("\n");
		ft_putendl(arr[0]);
		if (arr[0] != NULL)
			free(arr[0]);
	}
	ft_putnbr(ret);
	ft_putstr("\n");
	return (0);
}
