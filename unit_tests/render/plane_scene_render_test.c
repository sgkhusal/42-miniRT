/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_scene_render_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:02:16 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/03 155:330:01 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	put_left_wall(t_world *w)
{
	t_object	*left_wall;
	t_matrix	translation;
	t_matrix	rotation_x;
	t_matrix	rotation_y;
	t_matrix	rotation;

	left_wall = create_object(PLANE, create_plane());
	left_wall->material.color = set_vector(1, 0.9, 0.9);
	left_wall->material.specular = 0;
	translation = translation_matrix(0, 0, 4.3);
	rotation_x = rotation_x_matrix(M_PI / 2);
	rotation_y = rotation_y_matrix(-M_PI / 5);
	rotation = multiply_matrix(rotation_y, rotation_x);
	set_transform(left_wall, multiply_matrix(translation, rotation));
	append_object(&(w->objects), left_wall);
	free_matrix(rotation);
	free_matrix(rotation_x);
	free_matrix(rotation_y);
	free_matrix(translation);
}

static void	put_right_wall(t_world *w)
{
	t_object	*right_wall;
	t_matrix	translation;
	t_matrix	rotation_x;
	t_matrix	rotation_y;
	t_matrix	rotation;

	right_wall = create_object(PLANE, create_plane());
	right_wall->material.color = set_vector(1, 0.9, 0.9);
	right_wall->material.specular = 0;
	translation = translation_matrix(0, 0, 4.6);
	rotation_x = rotation_x_matrix(M_PI / 2);
	rotation_y = rotation_y_matrix(M_PI / 5);
	rotation = multiply_matrix(rotation_y, rotation_x);
	set_transform(right_wall, multiply_matrix(translation, rotation));
	append_object(&(w->objects), right_wall);
	free_matrix(rotation);
	free_matrix(rotation_x);
	free_matrix(rotation_y);
	free_matrix(translation);
}

static void	create_mlx_window2(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->window = NULL;
	mlx->img.ptr = NULL;
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		minirt_error(mlx, "mlx error initializing mlx");
	mlx->window = mlx_new_window(mlx->ptr, mlx->width, mlx->height, "miniRT");
	if (mlx->window == NULL)
		minirt_error(mlx, "mlx error creating window");
}

static t_world	create_world(void)
{
	t_object	*c;
	t_world		world;
	t_object	*floor;

	world.objects = NULL;
	world.lights = NULL;
	floor = create_object(PLANE, create_plane());
	floor->material.color = set_vector(1, 0.9, 0.9);
	floor->material.specular = 0;
	append_object(&(world.objects), floor);
	put_left_wall(&(world));
	put_right_wall(&(world));
	put_elements(&(world));
	world.lights = create_point_light(set_point(-10, 10, -10),
		set_vector(1, 1, 1));
	return (world);
}

void	plane_scene_render_test(void)
{
	t_mlx		mlx;
	t_rt		rt;
	t_object	*s;
	t_vector	**canvas;

	mlx.width = 1000;
	mlx.height = 500;
	create_mlx_window2(&mlx);
	create_mlx_image(&mlx.img, &mlx);
	canvas = create_canvas();
	rt.world = create_world();
	rt.camera = set_camera(M_PI / 3, mlx.width, mlx.height);
	rt.camera.origin = set_point(0, 1.5, -5);
	rt.camera.orientation = set_vector(0, 0, 1);
	set_camera_transform(&rt.camera, view_transform(rt.camera.origin,
			normalize_vector(subtract_points(set_point(0, 1, 0),
					rt.camera.origin)), set_vector(0, 1, 0)));
	render(rt.camera, rt.world, canvas, &mlx);
	clean_minirt(&rt, canvas);
	set_mlx_hooks(&mlx);
	mlx_loop(mlx.ptr);
}
