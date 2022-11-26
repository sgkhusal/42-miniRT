/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_render_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:11:30 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/26 15:31:38 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	ultimate_transform_plane(t_object *p, int type)
{
	t_matrix	rotation_x;
	t_matrix	rotation_y;
	t_matrix	rotation_z;
	t_matrix	translation;
	t_matrix	tmp;

	rotation_x = rotation_x_matrix(-M_PI / 4);
	rotation_y = rotation_y_matrix(M_PI / 4);
	rotation_z = rotation_z_matrix(-M_PI / 10);
	translation = translation_matrix(0, 13, -10);
	tmp = multiply_matrix(rotation_z, rotation_y);
	set_transform(p, multiply_matrix(rotation_z, translation));
	free_matrix(rotation_x);
	free_matrix(rotation_y);
	free_matrix(rotation_z);
	free_matrix(tmp);
}

//when plane is horizontal, rotating it around y axis should not produce any
//visible change, because the plane is parallel to the y axis, but this changes
// if the plane is already rotated around the x or z axis
// scaling and translating in x and z axis the plane should not produce any
// visible change if the plane is horizontal, but this changes if the plane
// is already rotated
static void	transform_plane(t_object *p, int type)
{
	t_matrix	translation;
	t_matrix	scaling;

	if (type == 0) // por que fica amarelão?
		return ;
	if (type == 1)
		set_transform(p, translation_matrix(0, -5, 0));
	if (type == 2)
		set_transform(p, scaling_matrix(0.5, 0.5, 0.5)); // não tem efeito
	else if (type == 3)
		set_transform(p, rotation_x_matrix(3 * M_PI / 4)); // comparar se tem efeito de sombra nos dos outros
	else if (type == 4)
		set_transform(p, rotation_y_matrix(M_PI / 2)); // não tem efeito
	else if (type == 5)
		set_transform(p, rotation_z_matrix(M_PI / 10)); // M_PI / 2 dá um efeito estranho
	else if (type == 6)
		ultimate_transform_plane(p, PLANE);
}

static t_world	create_world(void)
{
	t_object	*p;
	t_object	*p2;
	t_world		world;

	world.objects = NULL;
	p = create_object(PLANE, create_plane());
	transform_plane(p, 1);
	p->material.color = set_vector(0.4, 0.4, 1); //azul
	append_object(&world.objects, p);
	p2 = create_object(PLANE, create_plane());
	transform_plane(p2, 6);
	p2->material.color = set_vector(1, 0.4, 0.4); // rosa
	append_object(&world.objects, p2);
	world.light = set_point_light(set_point(-10, 10, -10),
			set_vector(1, 1, 1));
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
	// camera em y = 0  e plano sem transformação tem um efeito diferente...
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
