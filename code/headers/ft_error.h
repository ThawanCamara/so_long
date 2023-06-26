/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:52:23 by tde-souz          #+#    #+#             */
/*   Updated: 2022/09/14 02:52:24 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

enum e_error_code
{
	ERROR_MLX = 1,
	ERROR_PARSE_MAP = 2,
	ERROR_ARGS = 3,
	ERROR_SOLVER = 4
};	

void	throw_error(char *msg, int error_code);

#endif
