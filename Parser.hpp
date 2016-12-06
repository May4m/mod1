/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 08:47:27 by smamba            #+#    #+#             */
/*   Updated: 2016/10/27 08:47:28 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

# include "main.hpp"
# include "MapOps.hpp"

class Parser : public ft42
{
  public:
    Parser(char *path);
    ~Parser();

    Point fileToTab(void);
    void printMap(void);
    void sortByZ_minToMax(void);
    void resizeValue(void);

    class ErrorParse : public std::exception
    {
      public:
	virtual const char *what() const throw();
    };

  private:
    char *_pathToSource;
    t_data *_d;
    Parser(Parser const &rSource);
    Parser &operator=(Parser const &rSource);
    Parser();
};

#endif
