/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:52:34 by tde-souz          #+#    #+#             */
/*   Updated: 2022/09/14 02:52:35 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RENDER_H
# define FT_RENDER_H

# include "so_long.h"

int		game_loop(void *p);
void	render_game(void *p, int (*f)(void *, void *, void *, int, int));
void	init_images(void *instance, void *(*f)(void *, char *, int *, int *));

#endif
