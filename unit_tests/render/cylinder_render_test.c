/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_render_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:06:05 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/27 18:24:129 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	cylinder_rotate(t_object *c, int type)
{
	t_matrix	rotation_x;
	t_matrix	rotation_y;
	t_matrix	rotation_z;

	if (type == 7)
		set_transform(c, rotation_z_matrix(M_PI / 4)); // sentido anti-horário
	else if (type == 8)
		set_transform(c, rotation_z_matrix(M_PI / 2)); // sentido anti-horário
	else if (type == 9)
	{
		rotation_x = rotation_x_matrix(M_PI / 4);
		rotation_z = rotation_z_matrix(M_PI / 4);
		set_transform(c, multiply_matrix(rotation_x, rotation_z)); // dá diferença na ordem
		free_matrix(rotation_x);
		free_matrix(rotation_z);
	}
	else if (type == 10)
	{
		rotation_x = rotation_x_matrix(M_PI / 4);
		rotation_y = rotation_y_matrix(M_PI / 4);
		set_transform(c, multiply_matrix(rotation_y, rotation_x));
		free_matrix(rotation_x);
		free_matrix(rotation_y);
	}
}

static void	transform_cylinder(t_object *c, int type)
{
	t_matrix	translation;
	t_matrix	scaling;

	if (type == 0)
		return ;
	if (type == 1)
		set_transform(c, translation_matrix(1, -3, 1));
	else if (type == 2)
		set_transform(c, scaling_matrix(0.25, 1, 0.25));
	else if (type == 3)
	{
		translation = translation_matrix(1, -3, 1);
		scaling = scaling_matrix(0.25, 1, 0.25);
		set_transform(c, multiply_matrix(translation, scaling));
		free_matrix(translation);
		free_matrix(scaling);
	}
	else if (type == 4)
		set_transform(c, rotation_x_matrix(M_PI / 4)); // vai para trás
	else if (type == 5)
		set_transform(c, rotation_x_matrix(M_PI / 2)); // vai para trás - não está computando a difusa
	else if (type == 6)
		set_transform(c, rotation_y_matrix(M_PI / 4));
	else
		cylinder_rotate(c, type);
}

static t_world	create_world(void)
{
	t_object	*c;
	t_world		world;

	c = create_object(CYLINDER, create_cylinder());
	transform_cylinder(c, 0);
	c->shape.cylinder->min = -1;
	c->shape.cylinder->max = 1;
	c->material.color = set_vector(0.5, 0.2, 1);
	world.objects = NULL;
	append_object(&world.objects, c);
	world.light.position = set_point(-10, 10, -10);
	world.light.intensity = set_vector(1, 1, 1);
	return (world);
}

void	cylinder_render_test(void)
{
	t_mlx		mlx;
	t_rt		rt;
	t_vector	**canvas;

	create_mlx_window(&mlx);
	create_mlx_image(&mlx.img, &mlx);
	canvas = create_canvas();
	rt.world = create_world();
	rt.camera = set_camera(70 * M_PI / 180, WIDTH, HEIGHT);
	rt.camera.origin = set_point(0, 0, -5);
	set_camera_transform(&rt.camera, view_transform(rt.camera.origin,
			rt.camera.orientation, set_vector(0, 1, 0)));
	render(rt.camera, rt.world, canvas, &mlx);
	free_canvas(canvas);
	free_objects(&(rt.world.objects));
	free_camera(&rt.camera);
	set_mlx_hooks(&mlx);
	mlx_loop(mlx.ptr);
}
