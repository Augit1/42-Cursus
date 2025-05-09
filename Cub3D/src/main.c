/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:32:58 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/06 20:36:53 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "parser.h"
#include "initialisation.h"

int	main(int argc, char **argv)
{
	t_config	*config;

	config = NULL;
	init_args(&config, argc, argv);
	init_display(config);
	free_config(config);
	return (0);
}

//#include <stdio.h>
//static void	print_config(const t_config *config)
//{
//	int	i;
//
//	printf("NO Texture: %s\n", config->no_texture);
//	printf("SO Texture: %s\n", config->so_texture);
//	printf("WE Texture: %s\n", config->we_texture);
//	printf("EA Texture: %s\n", config->ea_texture);
//	printf("Floor Color: %d\n",
//		config->floor_color);
//	printf("Ceiling Color: %d\n",
//		config->ceiling_color);
//	if (config->map)
//	{
//		printf("Map:\n");
//		i = 0;
//		while (config->map[i])
//			printf("%s\n", config->map[i++]);
//	}
//	else
//		printf("Map: NULL\n");
//}
