/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WaterBufferScene.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 08:48:56 by smamba            #+#    #+#             */
/*   Updated: 2016/10/27 08:48:57 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENAR3_CLASS_HPP
# define SCENAR3_CLASS_HPP

# include "main.hpp"
# include "MapOps.hpp"

class WaterBufferScene : public ft42 {
public:
	t_data *	d;
	char		scenar3Draw;
	bool		Scenar3FirstCall;
	int			move;
	int 		upZ3;

	WaterBufferScene(void);
	~WaterBufferScene(void);

	void	initWater(void);
	void	clearBuffer1(void);
	void	clearBuffer2(void);
	void	upWater( void );
	void	rUpWater1(t_data *d, int z, int y, int x);
	void	rUpWater2(t_data *d, int z, int y, int x);
	void	go( void );
	void	hillCopy_1to2(t_data *d);
	void	hillCopy_2to1(t_data *d);
	void	resetChecked( void );
	void	print2Dmap( void );

private:
	WaterBufferScene(WaterBufferScene const &src);
	WaterBufferScene & operator=(WaterBufferScene const &rhs);
};

#endif
