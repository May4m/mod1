/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UniformWaterScene.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 08:47:41 by smamba            #+#    #+#             */
/*   Updated: 2016/10/27 08:47:42 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UniformWaterScene_HPP
# define UniformWaterScene_HPP

# include "main.hpp"
# include "MapOps.hpp"

class UniformWaterScene : public ft42 {
public:
	t_data *	d;

	UniformWaterScene();
	~UniformWaterScene();
	
	void	upWater(int z);
	void	go(void);

private:
	UniformWaterScene(UniformWaterScene const &rSource);
	UniformWaterScene& operator=(UniformWaterScene const &rSource );

	void	rUpWater(t_data * d, int z, int y, int x);
};

#endif
