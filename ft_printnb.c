/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larobbie <larobbie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:08:55 by larobbie          #+#    #+#             */
/*   Updated: 2022/05/04 19:18:17 by larobbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printnb(int nb)
{
	char		*tmp;

	tmp = NULL;
	tmp = ft_itoa(nb);
	ft_putstr_fd(tmp, 1);
	free(tmp);
}
