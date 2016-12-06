/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 08:46:22 by smamba            #+#    #+#             */
/*   Updated: 2016/10/27 08:46:22 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CLASS_HPP
# define MAP_CLASS_HPP

# include "main.hpp"
# include "MapOps.hpp"

class Map : public ft42 {
public:
	t_data *	_d;

	Map();
	~Map();

	void	putRandomTo2dMap( void );
	void	print2Dmap( void );
	void    doMapHill( void );
	void	doHillPic(t_data * d, int z, int y, int x );

private:
	Map( Map const & rSource );
	Map & operator=( Map const & rSource );

	void 	doCircle( t_data * d, int z, int startY, int startX );
};

#endif
