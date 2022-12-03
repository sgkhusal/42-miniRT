/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_render_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:11:30 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/01 00:45:01 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	ultimate_transform_plane(t_object *p)
{
	t_matrix	rotation_x;
	t_matrix	rotation_y;
	t_matrix	rotation_z;
	t_matrix	translation;
	t_matrix	rotation;

	rotation_x = rotation_x_matrix(-M_PI / 4);
	rotation_y = rotation_y_matrix(M_PI / 3);
	rotation_z = rotation_z_matrix(-M_PI / 4);
	translation = translation_matrix(0, -1, -1);
	rotation = multiply_matrix(rotation_z, rotation_y);
	free_matrix(rotation_y);
	free_matrix(rotation_z);
	rotation_y = rotation;
	rotation = multiply_matrix(rotation_y, rotation_x);
	free_matrix(rotation_x);
	free_matrix(rotation_y);
	set_transform(p, multiply_matrix(rotation, translation));
	free_matrix(translation);
	free_matrix(rotation);
}

static void	combination_transform(t_object *p, int type)
{
	t_matrix	rotation_x;
	t_matrix	rotation_y;
	t_matrix	rotation_z;
	t_matrix	translation;

	rotation_x = rotation_x_matrix(M_PI / 4);
	rotation_y = rotation_y_matrix(M_PI / 4);
	rotation_z = rotation_z_matrix(M_PI / 4);
	translation = translation_matrix(0, -1, 5);
	if (type == 11)
		set_transform(p, multiply_matrix(translation, rotation_x));
	else if (type == 12)
		set_transform(p, multiply_matrix(translation, rotation_y));
	else if (type == 13)
		set_transform(p, multiply_matrix(translation, rotation_z));
	else
		ultimate_transform_plane(p);
	free_matrix(rotation_x);
	free_matrix(rotation_y);
	free_matrix(rotation_z);
	free_matrix(translation);
}

/*
scaling transformations doesn't affect the plane
translation transformations in x and z axis doesn't affect the plane if it is
not rotated around the x or z axis
rotation transformations around the y axis doesn't affect the plane if it is
not rotated around the x or z axis
*/
static void	transform_plane(t_object *p, int type)
{
	if (type == 0)
		return ;
	else if (type == 1)
		set_transform(p, translation_matrix(0, -0.5, 0));
	else if (type == 2)
		set_transform(p, translation_matrix(0, 1, 0));
	else if (type == 3)
		set_transform(p, translation_matrix(2, 0, 5));
	else if (type == 4)
		set_transform(p, scaling_matrix(0.5, 0.5, 0.5));
	else if (type == 5)
		set_transform(p, rotation_x_matrix(M_PI / 2));
	else if (type == 6)
		set_transform(p, rotation_x_matrix(-M_PI / 4));
	else if (type == 7)
		set_transform(p, rotation_y_matrix(M_PI / 2));
	else if (type == 8)
		set_transform(p, rotation_z_matrix(M_PI / 2));
	else if (type == 10)
		set_transform(p, rotation_z_matrix(45 * M_PI / 180));
	else
		combination_transform(p, type);
}

static t_world	create_world(void)
{
	t_object	*p;
	t_object	*p2;
	t_world		world;

	world.objects = NULL;
	p = create_object(PLANE, create_plane());
	transform_plane(p, 14);
	p->material.color = set_vector(0.4, 0.4, 1);
	p->material.specular = 0.2;
	append_object(&world.objects, p);
	p2 = create_object(PLANE, create_plane());
	transform_plane(p2, 13);
	p2->material.color = set_vector(1, 0.4, 0.4);
	append_object(&world.objects, p2);
	world.light = set_point_light(set_point(0, 10, -10), set_vector(1, 1, 1));
	return (world);
}

void	plane_render_test(void)
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
	rt.camera.orientation = set_vector(0, 0, 1);
	set_camera_transform(&rt.camera, view_transform(rt.camera.origin,
			rt.camera.orientation, set_vector(0, 1, 0)));
	render(rt.camera, rt.world, canvas, &mlx);
	free_canvas(canvas);
	free_objects(&(rt.world.objects));
	free_camera(&rt.camera);
	set_mlx_hooks(&mlx);
	mlx_loop(mlx.ptr);
}
