/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:06:28 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/06 00:10:49 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include <stdio.h>

int	update(t_cub *cub)
{
	calculate_Delta(cub);
	printf("direction: %f \n", cub->player.direction.x);
	printf("velocity.x: %f \n", cub->player.velocity.x);
	printf("velocity.y: %f \n", cub->player.velocity.y);
	printf("delta: %f \n", cub->delta);
	printf("pos.y: %f \n", cub->player.pos.y);
	printf("jump_started: %f \n", cub->player.jump.t_started);
	printf("jump_elapsed: %f \n", cub->player.jump.t_elapsed);

	// VELOCITY(get_velocity())
	if (cub->player.direction.x != 0)
	{
		cub->player.velocity.x += cub->player.direction.x;
		if (cub->player.velocity.x >= 150)
			cub->player.velocity.x = 150;
		if (cub->player.velocity.x <= -150)
			cub->player.velocity.x = -150;
	}
	else if (cub->player.direction.x == 0)
		cub->player.velocity.x = 0;

	// FALLING UNTIL FLOOR (check falling())
	if (cub->player.pos.y < SCREEN_SIZE_Y && cub->player.velocity.y == 0)
	{
		cub->player.velocity.y = 10;
		cub->player.velocity.y += cub->player.velocity.y * GRAVITY * cub->delta;
	}
	if (cub->player.pos.y >= SCREEN_SIZE_Y - 30)
		cub->player.velocity.y = 0;

	// JUMPING (check_jump())
	if (cub->player.jump.active == true)
	{
		if (cub->player.velocity.y == 0)
			cub->player.velocity.y = -200;
		if(cub->player.jump.t_started == 0)
			cub->player.jump.t_started = cub->delta;
		cub->player.jump.t_elapsed += cub->delta;
		if (cub->player.jump.t_elapsed >= cub->player.jump.duration)
		{
			cub->player.velocity.y = 160;
			cub->player.jump.active = false;
			cub->player.jump.t_started = 0;
			cub->player.jump.t_elapsed = 0;
		}
	}
		

	// MOVEMENT (get_movement())
	cub->player.pos.y += cub->player.velocity.y * cub->delta;
	cub->player.pos.x += cub->player.velocity.x * cub->delta;
	return (1);
}

int	renderer(t_cub *cub)
{
	(*cub).image.img = mlx_new_image((*cub).mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y);
	(*cub).image.addr = mlx_get_data_addr((*cub).image.img, &(*cub).image.bits_per_pixel, &(*cub).image.line_length, &(*cub).image.endian);

	t_point middle_screen;
	middle_screen.x = SCREEN_SIZE_X / 2;
	middle_screen.y = SCREEN_SIZE_Y / 2;
	drawrect(&cub->image, cub->player.pos, (t_point){30, 30}, 0xFFFFFFF);

	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->image.img, 0, 0);
	mlx_destroy_image(cub->mlx_ptr, cub->image.img);
	return (1);
}

int	game_loop(t_cub *cub)
{
	update(cub);
	renderer(cub);
	return (1);
}
