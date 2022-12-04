/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:53:55 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/04 14:00:15 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function will handle the field of view of the camera given
 * in the scene file. It will check its validity and transform it from string
 * to integer.
 *
 * @param fov_str field of view in string format
 * @param status status of the parsing
 * @return int field of view in integer format
 */
int	transform_fov(char *fov_str, int *status)
{
	int	fov;

	if (ft_strlen(fov_str) > 3)
	{
		*status = print_error_msg2("invalid FOV range [0-180]: ", fov_str);
		return (0);
	}
	fov = ft_atoi(fov_str);
	if (fov < 0 || fov > 180)
		*status = print_error_msg2("invalid FOV range [0-180]: ", fov_str);
	return (fov);
}

/**
 * @brief This function will take the string containing the camera information
 * from the scene file and go through each of them to check if they are valid.
 * Camera will receive a x,y,z coordinate of the view point, a 3d normalized
 * vector indicating the orientation of the camera, and a horizontal field of
 * view in degrees in range [0,180].
 *
 * @param infos the string containing the camera information
 * @return int OK if the camera is valid, ERROR if not
 */
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

/**
 * @brief This function will set the up vector depending on the orientation
 * vector. This is done to prevent a distortion while calculating the
 * transformation matrix when the cross product of the orientation vector and
 * the up vector is (0, 0, 0) (which is the case when the orientation vector is
 * (0, 1, 0) or (0, -1, 0)). The up vector is set as (0, 0, -1) when the
 * orientation vector is (0, 1, 0) and as (0, 0, 1) when the orientation vector
 * is (0, -1, 0).
 * That should be the result for the true up vector for each case.
 *
 * @param orientation the orientation vector
 * @return t_vector the up vector
 */
t_vector	set_up(t_vector orientation)
{
	if (check_double_values(orientation.y, 1))
		return (normalize_vector(set_vector(0, 0, -1)));
	if (check_double_values(orientation.y, -1))
		return (normalize_vector(set_vector(0, 0, 1)));
	return (set_vector(0, 1, 0));
}

/**
 * @brief This function will set the variables values of the camera struct by
 * transforming each received information from the file into the correct type.
 *
 * @param cam the camera struct
 * @param infos the array of strings with the information of the camera
 * @param status the status of the parsing, returns ERROR if any error occurs
 */
void	fill_camera(t_camera *cam, char **infos, int *status)
{
	double		fov;
	t_matrix	transform;

	fov = transform_fov(infos[3], status);
	*cam = set_camera(fov * M_PI / 180, WIDTH, HEIGHT);
	cam->origin = transform_coordinates(infos[1], status);
	cam->orientation = transform_orientation(infos[2], status);
	if (*status == ERROR)
		return ;
	transform = view_transform(cam->origin, cam->orientation,
			set_up(cam->orientation));
	set_camera_transform(cam, transform);
}

/**
 * @brief This function in the handler of the camera. It will receive the
 * information of the camera, split it by the separator space and call the
 * validation function to check if the information is valid. If it is valid, it
 * will call the function to fill the camera struct.
 *
 * @param line the line of the file with the information of the camera
 * @param cam the camera struct
 * @return int the status of the parsing, returns ERROR if any error occurs
 */
int	handle_camera(char *line, t_camera *cam)
{
	char	**infos;
	int		status;

	status = OK;
	infos = ft_split(line, ' ');
	if (!infos)
		return (print_error_msg("malloc error on handle_camera"));
	if (total_infos(infos) != 4)
		status = print_error_msg2("to many or few arguments for camera: ",
				"[camera origin] [camera orientation] [FOV in degrees]");
	else if (validate_camera_chars(infos) == ERROR)
		status = ERROR;
	else
		fill_camera(cam, infos, &status);
	free_array(infos);
	return (status);
}
