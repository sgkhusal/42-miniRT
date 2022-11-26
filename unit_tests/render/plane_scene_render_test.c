/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_scene_render_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:02:16 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/26 15:28:47 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	put_elements(t_world *w)
{
	t_object	*middle;
	t_object	*right;
	t_object	*left;

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

static void	set_world(t_world *w)
{
	t_object	*floor;
	t_object	*backdrop_wall;
	t_object	*ceiling;

	floor = create_object(PLANE, create_plane());
	floor->material.color = set_vector(1, 0.9, 0.9);
	floor->material.specular = 0;
	append_object(&(w->objects), floor);
	backdrop_wall = create_object(PLANE, create_plane());
	backdrop_wall->material.color = set_vector(1, 1, 0);
	backdrop_wall->material.specular = 0;
	set_transform(backdrop_wall, multiply_matrix(translation_matrix(0, 0, 3),
			rotation_x_matrix(M_PI / 2)));
	append_object(&(w->objects), backdrop_wall);
	ceiling = create_object(PLANE, create_plane());
	ceiling->material.color = set_vector(0, 0, 0);
	ceiling->material.specular = 0;
	set_transform(ceiling, translation_matrix(0, 4, 0));
	append_object(&(w->objects), ceiling);
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

	world.objects = NULL;
	set_world(&(world));
	put_elements(&(world));
	world.light.position = set_point(-10, 3, -10);
	world.light.intensity = set_vector(1, 1, 1);
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
	rt.camera = set_camera(M_PI / 2, mlx.width, mlx.height);
	rt.camera.origin = set_point(0, 1.5, -5);
	set_camera_transform(&rt.camera, view_transform(rt.camera.origin,
			normalize_vector(subtract_points(set_point(0, 1, 0),
					rt.camera.origin)), set_vector(0, 1, 0)));
	render(rt.camera, rt.world, canvas, &mlx);
	free_canvas(canvas);
	free_objects(&(rt.world.objects));
	free_camera(&rt.camera);
	set_mlx_hooks(&mlx);
	mlx_loop(mlx.ptr);
}
