
#pragma once
/*----------------------------------------
 * Tile.h
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


class Tile {

public:
	//Tile()=default;
	~Tile()=default;

	// state enum
	
		// none to declare

	// attributes

		Size m_span;
		Size span() { return m_span; };
		void set_span(Size span) { m_span = span; };
		ImageRef m_image_ref;
		ImageRef image_ref() { return m_image_ref; };
		void set_image_ref(ImageRef image_ref) { m_image_ref = image_ref; };

	// relation navigation

		Graphic* m_graphic;
		void graphic_link(Graphic* toobj){m_graphic = toobj;};
		void graphic_unlink(Graphic* fromObject=nullptr){m_graphic = nullptr;};
		Graphic* graphic() { return m_graphic;}
		std::vector<Pixel*> m_pixels;
		void pixels_link(Pixel* toobj){m_pixels.push_back(toobj);};
		void pixels_unlink(Pixel* fromObject){std::erase(m_pixels,fromObject);};
		std::vector<Pixel*> pixels() {std::vector<Pixel*> tmp;for (auto instance : m_pixels) {	tmp.push_back(instance);}return tmp;}

	// Event receiver functions

		// none to declare

	// procedures/methods

		void initialise(Graphic* graphic);
		void make_pixel(Coord n);

	// state actions

		// none to declare

}; // class

// event class definitions

		// none to declare

}; // namespace


