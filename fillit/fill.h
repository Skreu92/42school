/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:06:21 by etranchi          #+#    #+#             */
/*   Updated: 2017/04/27 15:07:05 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_H
# define FILL_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_tuple
{
	int				x;
	int				y;
}					t_tuple;
typedef struct		s_piece
{
	char			letter;
	t_tuple			*init;
	t_tuple			*first;
	t_tuple			*second;
	t_tuple			*third;
	int				putted;
	struct s_piece	*next;
}					t_piece;
typedef struct		s_map
{
	t_piece			*lst_piece;
	int				size_map;
	int				nb_tetri;
	char			**map;
	char			**best_map;
	int				best_size;
}					t_map;

int					ft_check_plus_plus(char *str, int i);
void				new_map_to_save(t_map *map);
int					init_char_map(t_map *map);
int					get_square(int size);
int					add_placebox(char *str, int i, int j);
void				ft_solve(t_map *map);
int					check_mate(char *str);
char				*ft_read(int argc, char **argv);
int					check_error(int countbox, int placebox);
int					ft_golst(char *str);
int					ft_check(char *str);
t_piece				*malloc_piece(void);
void				set_zero_tuple(t_tuple *tuple);
t_piece				*create_piece(char *str, int nb_tetri);
int					ft_set_tuple(t_piece *piece, int nb, int i);
t_piece				*add_piece_tab(t_piece *lst, t_piece *piece);
t_piece				*init_lst(char *str);
int					check_str(char *str);
t_map				*init_map(t_piece *lst, int size);
int					try_put_piece(t_map *map, int x, int y, int nb_piece);
void				draw_empty_map(t_map *map);
void				ft_may_pose(t_map *map, t_piece *piece, int x, int y);
void				draw_piece(t_map *map, t_piece *piece, int x, int y);
void				clear_piece(t_map *map, t_piece *piece, int x, int y);
int					check_value_tuple(t_map *map, int x, int y, t_tuple *tuple);
void				ft_print_map(t_map *map);
void				check_all_piece_put(t_map *map);
int					ft_scale_map(t_map *map, int size);
int					ft_to_check(t_map *map, t_piece *piece, int x, int y);
void				ft_save(t_map *map);

#endif
