/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:50:49 by equiana           #+#    #+#             */
/*   Updated: 2019/10/31 17:28:40 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_list	*tmp;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf input_file\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("cann't open file\n");
		return (0);
	}
	tmp = ft_read_file(fd);
	ft_render(tmp, argv[1]);
	close(fd);
	return (0);
}
