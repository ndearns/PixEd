
#pragma once
/*----------------------------------------
 * Palette.h
 *
 * 
 *
 *	Generated with async option
 *
 *----------------------------------------*/

#include <list>
#include <string>
#include "EventQueue.h"
#include "PixelGraphics.h"


namespace PixelGraphics{

	// declare event classes
	
		// none to declare


class Palette {

public:
	//Palette()=default;
	~Palette()=default;

	// state enum
	
		// none to declare

	// attributes

		// none to declare

	// relation navigation

		std::vector<ColorWell*> m_color_wells;
		void color_wells_link(ColorWell* toobj){m_color_wells.push_back(toobj);};
		void color_wells_unlink(ColorWell* fromObject){std::erase(m_color_wells,fromObject);};
		std::vector<ColorWell*> color_wells() {std::vector<ColorWell*> tmp;for (auto instance : m_color_wells) {	tmp.push_back(instance);}return tmp;}

	// Event receiver functions

		// none to declare

	// procedures/methods

		void initialise();
		void add_color_well(Color color);

	// state actions

		// none to declare

}; // class

// event class definitions

		// none to declare

}; // namespace


