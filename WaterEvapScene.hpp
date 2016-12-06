/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WaterEvapScene.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 08:46:07 by smamba            #+#    #+#             */
/*   Updated: 2016/10/27 08:46:08 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENAR4_CLASS_HPP
# define SCENAR4_CLASS_HPP

# include "main.hpp"
# include "MapOps.hpp"

class WaterEvapScene : public ft42 {
public:
	t_data 		*d;
	Point 		**purge;
	bool		firstCall;
	int 		downZ;

	WaterEvapScene();
	~WaterEvapScene();

	void	downWater( void );
	void	reDownX( int z, int y, int x);
	void	go( void );
	void	initWater( void);
	void	resetChecked( void );

private:
	WaterEvapScene( WaterEvapScene const & rSource );
	WaterEvapScene & operator=( WaterEvapScene const & rSource );
};

#endif
