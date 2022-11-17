/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:24:11 by elraira-          #+#    #+#             */
/*   Updated: 2022/11/16 21:37:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	set_camera(double fov, int hsize, int vsize)
{
	t_camera	camera;
	double		half_view;
	double		aspect;

	camera.fov = fov;
	camera.hsize = hsize;
	camera.vsize = vsize;
	camera.transform = identity_matrix(4);
	camera.inverse = identity_matrix(4);
	half_view = tan(fov / 2);
	aspect = (double)hsize / (double)vsize;
	if (aspect >= 1)
	{
		camera.half_width = half_view;
		camera.half_height = half_view / aspect;
	}
	else
	{
		camera.half_width = half_view * aspect;
		camera.half_height = half_view;
	}
	camera.pixel_size = (camera.half_width * 2) / hsize;
	return (camera);
}

void	free_camera(t_camera *camera)
{
	free_matrix(camera->transform);
	free_matrix(camera->inverse);
}
