/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:59:59 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/01/29 22:08:01 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_error(int exit_status, int is_input)
{
	static int	status;

	if (is_input)
		status = exit_status;
	if (status == 2)
		return (127);
	return (status);
}
