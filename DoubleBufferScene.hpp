/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleBufferScene.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 08:45:49 by smamba            #+#    #+#             */
/*   Updated: 2016/10/27 08:45:50 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENAR7_CLASS_HPP
# define SCENAR7_CLASS_HPP

# include "main.hpp"
# include "MapOps.hpp"

class DoubleBufferScene : public ft42 {
private:

public:
	t_data *	d;

	DoubleBufferScene( void );
	~DoubleBufferScene( void );

	void	InitWater( void );
	void	upWater( void );
	void	go( void );
	
	

private:
	DoubleBufferScene( DoubleBufferScene const & src );
	DoubleBufferScene & operator=( DoubleBufferScene const & rhs );

	void	resetChecked( t_data * d );
	int 	Clamp(int x, int min, int max);
	void	rUpWater(t_data * d, int z, int y, int x, bool line);//, bool checked);
};

#endif
