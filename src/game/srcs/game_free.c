/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:39:12 by aait-ham          #+#    #+#             */
/*   Updated: 2021/02/09 19:39:15 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_texture(t_game *this)
{
	if (this->so_texture != NULL)
		free(this->so_texture);
	if (this->ea_texture != NULL)
		free(this->ea_texture);
	if (this->n_texture != NULL)
		free(this->n_texture);
	if (this->we_texture != NULL)
		free(this->we_texture);
	if (this->floor != NULL)
		free(this->floor);
}

void	free_lists(t_game *this)
{
	if (this->lights.arr != NULL)
		this->lights.free(&this->lights, &free_sprite);
	if (this->allocated_sp_tex.arr != NULL)
		this->allocated_sp_tex.free(&this->allocated_sp_tex, &free);
	if (this->errors.free != NULL)
		this->errors.free(&this->errors, &free);
	if (this->sprites.free != NULL)
		this->sprites.free(&this->sprites, &free_sprite);
	if (this->walls.free != NULL)
		this->walls.free(&this->walls, &free_wall);
}

void	free_game(void *t)
{
	t_game *this;

	this = (t_game *)t;
	free_texture(this);
	free_lists(this);
	if (this->parser != NULL && this->parser->free != NULL)
		this->parser->free(this->parser);
	if (this->player.free != NULL)
		this->player.free(&this->player);
	if (this->window.img != NULL)
		mlx_destroy_image(this->window.mlx, this->window.img->img_ptr);
	if (this->window.mlx != NULL && this->window.win != NULL)
	{
		mlx_clear_window(this->window.mlx, this->window.win);
		mlx_destroy_window(this->window.mlx, this->window.win);
	}
}
