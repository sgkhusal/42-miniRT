/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:58:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/03 18:58:32 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	handle_input(int argc, char *input[])
{
	if (argc != 2)
	{
		if (argc < 2)
			printf("Error\nmissing scene file\n");
		else
			printf("Error\ntoo many arguments\n");
		exit(EXIT_FAILURE);
	}
	else
		printf("file name = %s\n", input[0]);
}
