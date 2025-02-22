/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_list_resize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:44:19 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/01/28 19:11:06 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cs_list.h"

void	cs_list_resize(t_cs_list *list, int capacity)
{
	void	*mem;
	void	*tmp;

	if (list->free_contate)
		mem = ft_calloc(list->size_of_type, capacity);
	else
		mem = ft_calloc_without_save(list->size_of_type, capacity);
	ft_memcpy(mem, list->contate, list->count * list->size_of_type);
	tmp = list->contate;
	list->contate = mem;
	list->capacity = capacity;
	ft_free(tmp);
}
