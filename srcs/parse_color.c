/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:47:41 by ejang             #+#    #+#             */
/*   Updated: 2022/08/25 22:33:29 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../libft/libft.h"
#include <math.h>

char	*chopping_str(char	*str, char ***tmp)
{
	char	*chopped_str;
	int		i;
	i = -1;
	while (str[++i])
		if (ft_isdigit(str[i]) == 0 && str[i] != ' ')
		{
			free_split(*tmp);
			print_error("1INVALID COLOR");
		}
		//앞 뒤 공백 날리고
	chopped_str = chop_space(str);
		// 숫자 안에 공백이 있는지 확인
	if (is_space_in_str(chopped_str) == 0)
	{
		free_split(*tmp);
		free(chopped_str);
		print_error("2INVALID COLOR");
	}
	return (chopped_str);
}

//void	convert_rgb(char	*str, char	***tmp, int idx, unsigned int	*color)
unsigned int	convert_rgb(char	*str, char	***tmp, int idx)
{
	char			*chopped_str;
	unsigned int	rgb;

	if (idx == 0)
		chopped_str = chopping_str(str + 1, tmp);
	else
		chopped_str = chopping_str(str, tmp);
	rgb = ft_atoi(chopped_str);
	if (rgb < 0  || rgb > 255)
	{
		free(chopped_str);
		print_error("3INVALID COLOR");
	}
	// if (idx == 0)
	// 	*color += rgb * pow(16 ,4);
	// else if (idx == 1)
	// 	*color += rgb * pow(16 ,2);
	// else
	// 	*color += rgb;
	if (idx == 0)
		return(rgb * pow(16 ,4));
	else if (idx == 1)
		return(rgb * pow(16 ,2));
	else
		return(rgb);
}

unsigned int	cal_color(char *str)
{
	char			**tmp;
	unsigned int	color;
	
	// , 나누기 개수 3개인지 확인
	if (get_count(str, ',') != 3)
		print_error("4INVALID COLOR");
	tmp = ft_split(str, ',');
	color = 0;
	color += convert_rgb(tmp[0], &tmp, 0);
	// chopped_str = chopping_str(tmp[0], &tmp);
	// rgb = ft_atoi(chopped_str);
	// if (rgb < 0  || rgb > 255)
	// {
	// 	free(chopped_str);
	// 	print_error("INVALID MAP");
	// }
	// color += rgb * pow(16 ,4);
	color += convert_rgb(tmp[1], &tmp, 1);
	color += convert_rgb(tmp[2], &tmp, 2);
	return (color);
}
