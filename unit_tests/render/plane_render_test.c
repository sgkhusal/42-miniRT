/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_render_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:11:30 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/20 15:00:09 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	ultimate_transform_plane(t_object *p, int type)
{
	t_matrix	rotation_x;
	t_matrix	rotation_y;
	t_matrix	rotation_z;
	t_matrix	tmp;

	rotation_x = rotation_x_matrix(-M_PI / 4);
	rotation_y = rotation_y_matrix(M_PI / 4);
	rotation_z = rotation_z_matrix(M_PI / 4);
	tmp = multiply_matrix(rotation_z, rotation_y);
	set_transform(p, multiply_matrix(tmp, rotation_x));
	free_matrix(rotation_x);
	free_matrix(rotation_y);
	free_matrix(rotation_z);
	free_matrix(tmp);
}

//when plane is horizontal, rotating it aroun y axis should not produce any
//visible change, because the plane is parallel to the y axis, but this changes
// if the plane is already rotated around the x or z axis
static void	transform_plane(t_object *p, int type)
{
	t_matrix	translation;
	t_matrix	scaling;

	if (type == 0) // por que fica amarelão?
		return ;
	if (type == 1)
		set_transform(p, translation_matrix(0, -3, 0));
	if (type == 2)
		set_transform(p, scaling_matrix(0.5, 0.5, 0.5)); // não tem efeito e fica amarelão
	else if (type == 3)
		set_transform(p, rotation_x_matrix(M_PI / 4)); // comparar se tem efeito de sombra nos dos outros
	else if (type == 4)
		set_transform(p, rotation_y_matrix(M_PI / 2));
	else if (type == 5)
		set_transform(p, rotation_z_matrix(M_PI / 4));
	else if (type == 6)
		ultimate_transform_plane(p, PLANE);
}

void	plane_render_test(void)
{
	t_mlx		mlx;
	t_rt		rt;
	t_object	*p;
	t_vector	**canvas;

	create_mlx_window(&mlx);
	create_mlx_image(&mlx.img, &mlx);
	canvas = create_canvas();
	p = create_object(PLANE, create_plane());
	transform_plane(p, 6);
	p->material.color = set_vector(1, 1, 0);
	rt.world.objects = NULL;
	append_object(&rt.world.objects, p);
	rt.world.light = set_point_light(set_point(-10, 10, -10),
		set_vector(1, 1, 1));
	rt.camera = set_camera(70 * M_PI / 180, WIDTH, HEIGHT);
	rt.camera.origin = set_point(0, 0, -5); // não está funcionando quando está dentro da esfera, na origem dela
	set_camera_transform(&rt.camera, view_transform(rt.camera.origin,
		normalize_vector(subtract_points(set_point(0, 0, 0), rt.camera.origin)),
		set_vector(0, 1, 0)));
	render(rt.camera, rt.world, canvas, &mlx);
	free_canvas(canvas);
	free_objects(&(rt.world.objects));
	free_camera(&rt.camera);
	set_mlx_hooks(&mlx);
	mlx_loop(mlx.ptr);
}

