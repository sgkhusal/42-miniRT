/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:53:22 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/23 22:44:43 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// FOV : Horizontal field of view in degrees in range [0,180]
double	transform_fov(char *fov_str, int *status)
{
	double	fov;

	if (ft_strlen(fov_str) > 3)
	{
		*status = print_error_msg2("invalid FOV range: ", fov_str);
		return (0);
	}
	fov = ft_atod(fov_str);
	if (fov < 0 || fov > 180)
		*status = print_error_msg2("invalid FOV range: ", fov_str);
	return (fov);
}

static int validate_camera_chars(char **infos)
{
	if (validate_coordinates_chars(infos[1]) == ERROR)
		return (ERROR);
	if (validate_coordinates_chars(infos[2]) == ERROR)
		return (ERROR);
	if (validate_nb_chars(infos[3]) == ERROR)
		return (ERROR);
	return (OK);
}

int	handle_camera(char *line, t_camera *cam)
{
	char	**infos;
	int		status;

	status = OK;
	infos = ft_split(line, ' ');
	if (!infos)
		return (print_error_msg("malloc error on handle_camera"));
	if (total_infos(infos) != 4)
		status = print_error_msg2("to many or few arguments for camera", line);
	else if (validate_camera_chars(infos) == ERROR)
		status = ERROR;
	else
	{
		cam->origin = transform_coordinates(infos[1], &status);
		// ∗ 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
		cam->orientation = set_vector(0,0,1); //
		cam->fov = transform_fov(infos[3], &status);
	}
	free_array(infos);
	return (status);
}
