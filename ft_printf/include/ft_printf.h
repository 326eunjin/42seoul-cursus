/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:15:02 by ejang             #+#    #+#             */
/*   Updated: 2022/02/23 00:28:09 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_print_str(char *str);
int		ft_print_nbr(int nbr);
int		ft_print_unnbr(unsigned int nbr);
int		ft_print_pointer(unsigned long long pointer);
int		ft_print_hex_upper2(unsigned int nbr);
int		ft_print_hex_lower2(unsigned int nbr);

#endif