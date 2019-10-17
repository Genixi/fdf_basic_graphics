/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:50:49 by equiana           #+#    #+#             */
/*   Updated: 2019/10/16 21:33:39 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

int main(int argc, char **argv)
{
	int fd;
	
	if (argc != 2)
	{
		ft_putstr("invalid arguments\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("cann't open file\n");
		return (0);
	}
	display_lst(ft_read_file(fd));
	close(fd);
	return (0);
}
