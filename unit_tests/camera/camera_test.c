/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:24:11 by elraira-          #+#    #+#             */
/*   Updated: 2022/11/13 16:3502 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	set_camera_test1(void)
{
	t_camera	camera;

	printf(GREY "set_camera_test 1: " END);
	camera = set_camera(M_PI / 2, 160, 120);
	if (camera.fov == M_PI / 2 && camera.hsize == 160 && camera.vsize == 120)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_camera(&camera);
}

void	set_camera_test2(double fov, int hsize, int vsize, double expected)
{
	t_camera	camera;
	static int	n = 2;

	printf(GREY "set_camera_test %d: " END, n);
	camera = set_camera(fov, hsize, vsize);
	if (check_double_values(camera.pixel_size, expected))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
	free_camera(&camera);
}

void	camera_tests(void)
{
	double	fov;
	int		hsize;
	int		vsize;
	double	psize;

	printf(YELLOW "Camera tests: " END "\n");
	set_camera_test1();
	set_camera_test2(M_PI / 2, 200, 125, 0.01);
	set_camera_test2(M_PI / 2, 125, 200, 0.016);
	ray_for_pixel_tests();
}
