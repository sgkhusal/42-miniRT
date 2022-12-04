/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:24:11 by elraira-          #+#    #+#             */
/*   Updated: 2022/12/04 12:31:49 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function will define the camera's properties.
 *
 * @param transform The camera's transformation matrix (which will default
 * to the identity matrix).
 * @param pixel_size The size that each pixel represents in the units of real
 * scene.
 * @param half_width The half width of the camera.
 * @param half_height The half height of the camera.

 * @param fov An angle that describes how much the camera can see. When the
 * field of view is small, the view will be “zoomed in,” magnifying a smaller
 * area of the scene. FOV will be converted from degrees from the input file to
 * radians (fov = input_fov * M_PI / 180).
 * @param hsize The width of the canvas
 * @param vsize The height of the canvas
 * @return t_camera The created camera.
 */
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

/**
 * @brief frees the matrices stored in the camera struct
 *
 * @param camera camera struct
 */
void	free_camera(t_camera *camera)
{
	if (camera->transform.matrix)
		free_matrix(camera->transform);
	if (camera->inverse.matrix)
		free_matrix(camera->inverse);
}
