/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_list_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:45:20 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/01/28 19:18:55 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector_bonus.h"

t_mem_list	**ft_mem_list(void)
{
	static t_mem_list	*list;

	return (&list);
}
