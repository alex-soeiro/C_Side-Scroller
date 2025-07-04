/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:03:20 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/06 00:09:05 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	cub_init(t_cub *cub)
{
	//INITIALIZE ALL MEHCANICS FIELDS//
	//SEPERATE INIT PER FIELD//
	cub->fd = 0;
	cub->delta = 0;
	cub->last_frame_time = get_time();
	cub->player.direction.x = 0;
	cub->player.direction.y = 0;
	cub->player.pos.x  = SCREEN_SIZE_X / 2;
	cub->player.pos.y = SCREEN_SIZE_Y / 2;
	cub->player.velocity.x = 0;
	cub->player.velocity.y = 0;
	cub->player.jump.active = false;
	cub->player.jump.duration = 0.5f;
	cub->player.jump.t_elapsed = 0;
	cub->player.dash.active = false;
	cub->player.dash.duration = 0.5f;
	cub->player.dash.t_elapsed = 0;
	cub->player.projectile.active = false;
	cub->player.projectile.duration = 6.0f;
	cub->player.projectile.t_elapsed = 0;
	cub->player.attack.active = false;
	cub->player.attack.duration = 4.0f;
	cub->player.attack.t_elapsed = 0;
}
