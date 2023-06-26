/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:52:25 by tde-souz          #+#    #+#             */
/*   Updated: 2022/09/14 02:53:31 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_KEYS_H
# define FT_KEYS_H

# ifdef __linux__

enum e_keys
{
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_ARROW_UP = 65362,
	KEY_ARROW_LEFT = 65361,
	KEY_ARROW_DOWN = 65363,
	KEY_ARROW_RIGHT = 65364
};
# else

enum e_keys
{
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_ARROW_UP = 126,
	KEY_ARROW_LEFT = 123,
	KEY_ARROW_DOWN = 124,
	KEY_ARROW_RIGHT = 125
};
# endif
#endif
