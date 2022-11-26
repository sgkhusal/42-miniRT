/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:53:55 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/26 12:58:56 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// FOV : Horizontal field of view in degrees in range [0,180]
int	transform_fov(char *fov_str, int *status)
{
	int	fov;

	if (ft_strlen(fov_str) > 3)
	{
		*status = print_error_msg2("invalid FOV range: ", fov_str);
		return (0);
	}
	fov = ft_atoi(fov_str);
	if (fov < 0 || fov > 180)
		*status = print_error_msg2("invalid FOV range: ", fov_str);
	return (fov);
}

static int	validate_camera_chars(char **infos)
{
	if (validate_coordinates_chars(infos[1]) == ERROR)
		return (ERROR);
	if (validate_coordinates_chars(infos[2]) == ERROR)
		return (ERROR);
	if (validate_nb_chars(infos[3]) == ERROR)
		return (ERROR);
	return (OK);
}

t_vector	set_up(t_vector orientation)
{
	if (check_double_values(fabs(orientation.y), 1))
		return (normalize_vector(set_vector(0.1, 1, 0))); /////
	return (set_vector(0, 1, 0));
}

void	fill_camera(t_camera *cam, char **infos, int *status)
{
	double		fov;
	t_matrix	transform;

	fov = transform_fov(infos[3], status);
	*cam = set_camera(fov * M_PI / 180, WIDTH, HEIGHT);
	cam->origin = transform_coordinates(infos[1], status);
	cam->orientation = transform_orientation(infos[2], status);
	if (*status == ERROR)
	{
		free_camera(cam);
		return ;
	}
	transform = view_transform(cam->origin, cam->orientation,
			set_up(cam->orientation));
	set_camera_transform(cam, transform);
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
		fill_camera(cam, infos, &status);
	free_array(infos);
	return (status);
}
