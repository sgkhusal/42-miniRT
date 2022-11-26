/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:56:53 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/25 21:29:58 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

double	degrees_to_radians(double degrees)
{
	return (degrees * M_PI / 180);
}

double	radians_to_degrees(double radians)
{
	return (radians * 180 / M_PI);
}

int	main(void)
{
	printf("Checking atan return values:\n");
	printf("atan(0) = %f\n", radians_to_degrees(atan(0)));
	printf("atan(1) = %f\n", radians_to_degrees(atan(1)));
	printf("atan(-1) = %f\n", radians_to_degrees(atan(-1)));
	printf("atan(0.5) = %f\n", radians_to_degrees(atan(0.5)));
	printf("atan(-0.5) = %f\n", radians_to_degrees(atan(-0.5)));
	printf("atan(0.25) = %f\n", radians_to_degrees(atan(0.25)));
	printf("atan(-0.25) = %f\n", radians_to_degrees(atan(-0.25)));
	printf("Checking tan return values:\n");
	printf("tan(0) = %f\n", tan(0));
	printf("tan(%f) = %f\n", radians_to_degrees(M_PI / 4), tan(M_PI / 4));
	printf("tan(%f) = %f\n", radians_to_degrees(M_PI / 2), tan(M_PI / 2));
	printf("tan(%f) = %f\n", radians_to_degrees(3 * M_PI / 4), tan(3 * M_PI / 4));
	printf("tan(%f) = %f\n", radians_to_degrees(M_PI), tan(M_PI));
	printf("tan(%f) = %f\n", radians_to_degrees(-M_PI / 4), tan(-M_PI / 4));
	printf("tan(%f) = %f\n", radians_to_degrees(-M_PI / 2), tan(-M_PI / 2));
	printf("tan(%f) = %f\n", radians_to_degrees(-3 * M_PI / 4), tan(-3 * M_PI / 4));
	printf("tan(%f) = %f\n", radians_to_degrees(-M_PI), tan(-M_PI));
	printf("atan(1/2) = %f\n", radians_to_degrees(atan(1/2)));
	return (0);
}
