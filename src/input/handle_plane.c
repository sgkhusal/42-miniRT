/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:54:33 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/04 09:36:03 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief This function will check if the scene file has all the mandatory
 * information to create a plane from the scene file and if the information is
 * valid. The plane infomation must be in the following format: first the
 * the x, y, z coordinate of the plane, then the normalized orientation vector
 * in double format, then the color of the plane in RGB format.
 *
 * @param infos the information of the plane
 * @return int 0 if the information is valid, 1 otherwise
 */
static int	validate_plane_chars(char **infos)
{
	if (validate_coordinates_chars(infos[1]) == ERROR)
		return (ERROR);
	if (validate_coordinates_chars(infos[2]) == ERROR)
		return (ERROR);
	if (validate_color_chars(infos[3]) == ERROR)
		return (ERROR);
	return (OK);
}

/**
 * @brief This function will set the transformation matrices for the
 * plane. It will set the translation matrix and the rotation matrix. Using the
 * set_transform function, it will apply the result of the multiplication of the
 * matrices to the transformation matrix of the plane. After that, it will
 * free the matrices.
 *
 * @param o the object plane
 * @param center the center of the plane
 * @param orientation the orientation of the plane
 */
static void	set_plane_matrixes(t_object *o, t_point center,
					t_vector orientation)
{
	t_matrix	translation;
	t_matrix	rotation;
	t_matrix	transform;

	translation = translation_matrix(center.x, center.y, center.z);
	rotation = get_rotation_matrix(orientation);
	transform = multiply_matrix(translation, rotation);
	set_transform(o, transform);
	free_matrix(translation);
	free_matrix(rotation);
}

/**
 * @brief This function will create the plane object. It will allocate memory
 * for the plane and transform the information in the correct type. Then, it
 * will set the t_plane struct properties of the plane by transforming the
 * information from the scene files. A specific specular is set for the plane
 * because we are considering that the plane is floor, a wall or a ceiling so
 * it will not reflect the light as much as the other objects. After that, it
 * will set the transformation matrices for the plane. Finally, it will add the
 * plane to the scene if everything is valid and no error occurs.
 *
 * @param objs the list of objects of the scene
 * @param infos the information of the plane
 * @param status the status of the parsing
 */
static void	create_and_append_plane(t_object **objs, char **infos, int *status)
{
	t_object	*pl;
	t_point		xyz;
	t_vector	orientation;

	pl = create_object(PLANE, create_plane());
	xyz = transform_coordinates(infos[1], status);
	orientation = transform_orientation(infos[2], status);
	pl->material.color = transform_color(infos[3], status);
	pl->material.specular = 0.2;
	set_plane_matrixes(pl, xyz, orientation);
	if (*status == ERROR)
		free_objects(&pl);
	else
		append_object(objs, pl);
}

/**
 * @brief This is the main handler for the plane. It will split the line
 * containing the plane information from the scene file and check if the
 * information is valid. If it is valid, it will create the plane and append it
 * to the scene. If it is not valid, it will set the status to ERROR.
 *
 * @param line the line containing the plane information
 * @param objs the list of objects of the scene
 * @return int 0 if the information is valid, 1 otherwise
 */
int	handle_plane(char *line, t_object **objs)
{
	char		**infos;
	int			status;

	status = OK;
	infos = ft_split(line, ' ');
	if (!infos)
		return (print_error_msg("malloc error on handle_plane"));
	if (total_infos(infos) != 4)
		status = print_error_msg2("to many or few arguments for plane: \
		[x,y,z coordinates] [orientation] [RGB color]: ", line);
	else if (validate_plane_chars(infos) == ERROR)
		status = ERROR;
	else
		create_and_append_plane(objs, infos, &status);
	free_array(infos);
	return (status);
}
