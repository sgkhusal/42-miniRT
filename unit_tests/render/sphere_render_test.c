/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_render_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellrairaira-a- <elralra-aira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:06:05 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/15 11:28:26 by elralraira-a-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	transform_sphere(t_object *s, int type)
{
	t_matrix	translation;
	t_matrix	scaling;

	if (type == 0)
		return ;
	if (type == 1 || type == 3)
		translation = translation_matrix(5, -3, 2);
	if (type == 2 || type == 3)
		scaling = scaling_matrix(0.5, 0.5, 0.5);
	if (type == 1)
		set_transform(s, translation);
	else if (type == 2)
		set_transform(s, scaling);
	else if (type == 3)
	{
		set_transform(s, multiply_matrix(translation, scaling));
		free_matrix(translation);
		free_matrix(scaling);
	}
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
	s = create_object(SPHERE, create_sphere());
	transform_sphere(s, 0);
	s->material.color = set_vector(1, 0.2, 1);
	rt.world.objects = NULL;
	append_object(&rt.world.objects, s);
	rt.world.light.position = set_point(-10, 10, -10);
	rt.world.light.intensity = set_vector(1, 1, 1);
	rt.camera = set_camera(70 * M_PI / 180, WIDTH, HEIGHT);
	rt.camera.origin = set_point(0, 0, -5);
	set_camera_transform(&rt.camera, view_transform(rt.camera.origin,
		set_point(0, 0, 0), set_vector(0, 1, 0)));
	render(rt.camera, rt.world, canvas, &mlx);
	free_canvas(canvas);
	free_objects(&(rt.world.objects));
	free_camera(&rt.camera);
	set_mlx_hooks(&mlx);
	mlx_loop(mlx.ptr);
}
