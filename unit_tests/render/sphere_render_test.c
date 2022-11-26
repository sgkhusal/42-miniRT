/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_render_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:06:05 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/26 12:32:04 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	transform_sphere2(t_object *s, int type)
{
	t_matrix	scaling;
	t_matrix	rotation;
	t_matrix	shearing;
	t_shearing	sh;

	scaling = scaling_matrix(0.5, 1, 1);
	if (type == 6)
	{
		rotation = rotation_z_matrix(M_PI / 4);
		set_transform(s, multiply_matrix(rotation, scaling));
		free_matrix(rotation);
	}
	if (type == 7)
	{
		sh.x_y = 1;
		sh.x_z = 0;
		sh.y_x = 0;
		sh.y_z = 0;
		sh.z_x = 0;
		sh.z_y = 0;
		shearing = shearing_matrix(sh);
		set_transform(s, multiply_matrix(shearing, scaling));
		free_matrix(shearing);
	}
	free_matrix(scaling);
}

static void	transform_sphere(t_object *s, int type)
{
	t_matrix	translation;
	t_matrix	scaling;

	if (type == 0)
		return ;
	if (type == 1)
		set_transform(s, translation_matrix(3, -1, 2));
	if (type == 2)
		set_transform(s, scaling_matrix(0.5, 0.5, 0.5));
	if (type == 3)
	{
		translation = translation_matrix(3, -1, 2);
		scaling = scaling_matrix(0.5, 0.5, 0.5);
		set_transform(s, multiply_matrix(translation, scaling));
		free_matrix(translation);
		free_matrix(scaling);
	}
	if (type == 4)
		set_transform(s, scaling_matrix(1, 0.25, 1));
	if (type == 5)
		set_transform(s, scaling_matrix(0.5, 1, 1));
	if (type == 6 || type == 7)
		transform_sphere2(s, type);
}

static t_world	create_world(void)
{
	t_object	*s;
	t_world		world;

	s = create_object(SPHERE, create_sphere());
	transform_sphere(s, 0);
	s->material.color = set_vector(1, 0.2, 1);
	world.objects = NULL;
	append_object(&world.objects, s);
	world.light = set_point_light(set_point(-10, 10, -10),
			set_vector(1, 1, 1));
	return (world);
}

void	sphere_render_test(void)
{
	t_mlx		mlx;
	t_rt		rt;
	t_object	*s;
	t_vector	**canvas;

	create_mlx_window(&mlx);
	create_mlx_image(&mlx.img, &mlx);
	canvas = create_canvas();
	rt.world = create_world();
	rt.camera = set_camera(70 * M_PI / 180, WIDTH, HEIGHT);
	rt.camera.origin = set_point(0, 0, -5); // não está funcionando quando está
	// dentro da esfera, na origem dela; no cilindro também
	set_camera_transform(&rt.camera, view_transform(rt.camera.origin,
			normalize_vector(subtract_points(set_point(0, 0, 0),
			rt.camera.origin)), set_vector(0, 1, 0)));
	render(rt.camera, rt.world, canvas, &mlx);
	free_canvas(canvas);
	free_objects(&(rt.world.objects));
	free_camera(&rt.camera);
	set_mlx_hooks(&mlx);
	mlx_loop(mlx.ptr);
}
