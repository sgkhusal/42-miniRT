/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_render_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:06:05 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/17 11:39:48 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	transform_cylinder(t_object *c, int type)
{
	t_matrix	translation;
	t_matrix	scaling;
	t_matrix	rotation_x;
	t_matrix	rotation_z;

	if (type == 1 || type == 3)
		translation = translation_matrix(5, 0, 0);
	if (type == 2 || type == 3)
		scaling = scaling_matrix(0.5, 1, 0.5);
	if (type == 1)
		set_transform(c, translation);
	else if (type == 2)
		set_transform(c, scaling);
	else if (type == 3)
	{
		set_transform(c, multiply_matrix(translation, scaling));
		free_matrix(translation);
		free_matrix(scaling);
	}
	else if (type == 4)
	{
		rotation_x = rotation_x_matrix(M_PI / 4);
		rotation_z = rotation_z_matrix(M_PI / 4);
		set_transform(c, multiply_matrix(rotation_x, rotation_z));
		free_matrix(rotation_x);
		free_matrix(rotation_z);
	}
}

void	cylinder_render_test(void)
{
	t_mlx		mlx;
	t_rt		rt;
	t_object	*c;
	t_vector	**canvas;

	create_mlx_window(&mlx);
	create_mlx_image(&mlx.img, &mlx);
	canvas = create_canvas();
	c = create_object(CYLINDER, create_cylinder());
	transform_cylinder(c, 4);
	c->shape.cylinder->min = -1;
	c->shape.cylinder->max = 4;
	c->material.normalized_color = set_vector(0.5, 0.2, 1);
	rt.world.objects = NULL;
	append_object(&rt.world.objects, c);
	rt.world.light.position = set_point(-10, 10, -10);
	rt.world.light.intensity = set_vector(1, 1, 1);
	rt.camera = set_camera(70 * M_PI / 180, WIDTH, HEIGHT);
	set_camera_transform(&rt.camera, view_transform(set_point(0, 0, -5),
		set_point(0, 0, 0), set_vector(0, 0, 1)));
	render(rt.camera, rt.world, canvas, &mlx);
	free_canvas(canvas);
	free_objects(&(rt.world.objects));
	free_camera(&rt.camera);
	set_mlx_hooks(&mlx);
	mlx_loop(mlx.ptr);
}
