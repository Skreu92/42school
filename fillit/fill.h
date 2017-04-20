/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:06:21 by etranchi          #+#    #+#             */
/*   Updated: 2017/04/20 17:07:47 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_H
# define FILL_H

typedef struct s_tuple
{
	int x;
	int y;
}				t_tuple;
typedef struct s_piece
{
	char letter;
	t_tuple *init;
	t_tuple *first;
	t_tuple *second;
	t_tuple *third;
}				t_piece;
#endif
