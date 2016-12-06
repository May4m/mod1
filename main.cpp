/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 08:45:21 by smamba            #+#    #+#             */
/*   Updated: 2016/10/27 08:45:22 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "string.h"
#include "iostream"
#include "Event.hpp"
#include "Parser.hpp"

using namespace std;

char	**get_args(int ac, char **av) {
	if (ac == 2)
	{
		char **argv = new char*[3];
		argv[0] = strdup(av[0]);
		argv[1] = strdup(av[1]);
		argv[2] = strdup("1");
		av = argv;
	}
	else if (ac == 1 || ac > 3) {
		std::cerr << "Request only 2 arguments: file.mod1 scene number" << std::endl;
		exit(0);
	}
	return av;
}

int      main(int ac, char **av) {

	av = get_args(ac, av);
	getData();							// init BigData
	Event			event;				// Call mainEvent
	try
	{
		event.initEvent(av);			// Init object, alloc maps, open debugg
		event.d->parser->fileToTab(); 	// put Source File to list of pts
	}
	catch (std::exception &e)
	{
		std::cerr << "Initilisation error..." << std::endl;
		return -1;
	}
	event.initMap();					// initmap with default values
	event.initRender(ac, av);			// init Opengl
	event.renderScene();				// show scenars

	return 0;
}
