/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RainingScene.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 08:45:29 by smamba            #+#    #+#             */
/*   Updated: 2016/10/27 08:45:32 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENAR8_CLASS_HPP
# define SCENAR8_CLASS_HPP

# include "main.hpp"
# include "MapOps.hpp"

class RainingScene : public ft42 {
public:
	t_data *	d;
	char		scenar8Draw;
	bool		Scenar8FirstCall;

	RainingScene( void );
	~RainingScene( void );

	void		initWater(void);
	void		clearBuffer1(void);
	void		clearBuffer2(void);
	void		upWater(void);
	void		rUpWater1(t_data * d, int z, int y, int x);
	void		rUpWater2(t_data * d, int z, int y, int x);
	void		go(void);
	void		hillCopy_1to2(t_data * d);
	void		hillCopy_2to1(t_data * d);
	void		resetChecked(void);
	void		print2Dmap(void);
	void		Rain(t_data *d, bool buffer);
	int			ChoosePath(Point ** oldBuff, Point ** newBuff, int z, int y, int x);
	void 		WaterUp(t_data *d, Point ** buffer );

private:
	RainingScene(RainingScene const &src);
	RainingScene& operator=(RainingScene const &rhs);
};

#endif
