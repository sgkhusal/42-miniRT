/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:53:36 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/16 19:54:509 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	set_world(t_world *w)
{
	t_object	*floor;
	t_object	*left_wall;
	t_object	*right_wall;
	t_object	*middle;
	t_object	*right;
	t_object	*left;

	floor = create_object(SPHERE, create_sphere());
	floor->material.color = set_vector(1, 0.9, 0.9);
	floor->material.specular = 0;
	set_transform(floor, scaling_matrix(10, 0.01, 10));
	append_object(&(w->objects), floor);
	left_wall = create_object(SPHERE, create_sphere());
	left_wall->material.color = set_vector(1, 0.9, 0.9);
	left_wall->material.specular = 0;
	set_transform(left_wall, multiply_matrix(translation_matrix(0, 0, 5),
		multiply_matrix(rotation_y_matrix(-M_PI / 4),
		multiply_matrix(rotation_x_matrix(M_PI / 2),
		scaling_matrix(10, 0.01, 10)))));
	append_object(&(w->objects), left_wall);
	right_wall = create_object(SPHERE, create_sphere());
	right_wall->material.color = set_vector(1, 0.9, 0.9);
	right_wall->material.specular = 0;
	set_transform(right_wall, multiply_matrix(translation_matrix(0, 0, 5),
		multiply_matrix(rotation_y_matrix(M_PI / 4),
		multiply_matrix(rotation_x_matrix(M_PI / 2),
		scaling_matrix(10, 0.01, 10)))));
	append_object(&(w->objects), right_wall);
	middle = create_object(SPHERE, create_sphere());
	middle->material.color = set_vector(0.1, 1, 0.5);
	middle->material.diffuse = 0.7;
	middle->material.specular = 0.3;
	set_transform(middle, translation_matrix(-0.5, 1, 0.5));
	append_object(&(w->objects), middle);
	right = create_object(SPHERE, create_sphere());
	right->material.color = set_vector(0.5, 1, 0.1);
	right->material.diffuse = 0.7;
	right->material.specular = 0.3;
	set_transform(right, multiply_matrix(translation_matrix(1.5, 0.5, -0.5),
		scaling_matrix(0.5, 0.5, 0.5)));
	append_object(&(w->objects), right);
	left = create_object(SPHERE, create_sphere());
	left->material.color = set_vector(1, 0.8, 0.1);
	left->material.diffuse = 0.7;
	left->material.specular = 0.3;
	set_transform(left, multiply_matrix(translation_matrix(-1.5, 0.33, -0.75),
		scaling_matrix(0.33, 0.33, 0.33)));
	append_object(&(w->objects), left);
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

void	scene_render_test(void)
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
	rt.world.objects = NULL;
	set_world(&(rt.world));
	rt.camera = set_camera(M_PI / 3, mlx.width, mlx.height);
	rt.world.light.position = set_point(-10, 10, -10);
	rt.world.light.intensity = set_vector(1, 1, 1);
	set_camera_transform(&rt.camera, view_transform(set_point(0, 1.5, -5),
		set_point(0, 1, 0), set_vector(0, 1, 0)));
	render(rt.camera, rt.world, canvas, &mlx);
	free_canvas(canvas);
	free_objects(&(rt.world.objects));
	free_camera(&rt.camera);
	set_mlx_hooks(&mlx);
	mlx_loop(mlx.ptr);
}
