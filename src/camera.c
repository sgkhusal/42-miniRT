/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:24:11 by elraira-          #+#    #+#             */
/*   Updated: 2022/11/23 18:47:07 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// fov should be in radians
// we receive in the input file a fov in degrees and we need to convert it:
// fov = input_fov * M_PI / 180
// to calculate the true width and height that are seen by the camera, we use
// the fov: tan(fov / 2) = oposite catet / adjacent catet,
// adjacent catet = 1, oposite catet = half_width (for an horizontal fov)
// so half_width = tan(fov / 2)
// we can calculate the half_height using the rule of three:
// half_height = half_width * vsize / hsize
// pixel_size is the size that each pixel represents in the units of real scene
t_camera	set_camera(double fov, int hsize, int vsize)
{
	t_camera	cam;

	cam.fov = fov;
	cam.hsize = hsize;
	cam.vsize = vsize;
	cam.transform = identity_matrix(4);
	cam.inverse = identity_matrix(4);
	cam.half_width = tan(fov / 2);
	cam.half_height = cam.half_width * (double)vsize / (double)hsize;
	cam.pixel_size = (cam.half_width * 2) / (double)hsize;
	return (cam);
}

void	free_camera(t_camera *camera)
{
	free_matrix(camera->transform);
	free_matrix(camera->inverse);
}
