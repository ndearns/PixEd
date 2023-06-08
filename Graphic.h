
#pragma once
/*----------------------------------------
 * Graphic.h
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


class Graphic {

public:
	//Graphic()=default;
	~Graphic()=default;

	// state enum
	
		// none to declare

	// attributes

		Size m_tile_span;
		Size tile_span() { return m_tile_span; };
		void set_tile_span(Size tile_span) { m_tile_span = tile_span; };
		Size m_grid_span;
		Size grid_span() { return m_grid_span; };
		void set_grid_span(Size grid_span) { m_grid_span = grid_span; };
		Color m_background_color;
		Color background_color() { return m_background_color; };
		void set_background_color(Color background_color) { m_background_color = background_color; };

	// relation navigation

		std::vector<Tile*> m_tiles;
		void tiles_link(Tile* toobj){m_tiles.push_back(toobj);};
		void tiles_unlink(Tile* fromObject){std::erase(m_tiles,fromObject);};
		std::vector<Tile*> tiles() {std::vector<Tile*> tmp;for (auto instance : m_tiles) {	tmp.push_back(instance);}return tmp;}

	// Event receiver functions

		// none to declare

	// procedures/methods

		void initialise(Coord t_res, Coord p_span);
		void add_tile();

	// state actions

		// none to declare

}; // class

// event class definitions

		// none to declare

}; // namespace


