/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:35:23 by ejang             #+#    #+#             */
/*   Updated: 2022/05/19 02:35:38 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int press_esc_key(int key, void *p)
{
    if (key == 53)//in linux it meas esc key
        exit(0);
    return 0;
}

// int zoom_in(int mouse, void *p)
// {

// }

// int zoom_out(int mouse, void *p)
// {

// }