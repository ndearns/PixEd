
/*----------------------------------------
 * Graphic.cpp
 *
 * 
 *
 *	Generated with async option
 *
 *----------------------------------------*/

#include <iostream>
#include <cassert>
#include "PixelGraphics.h"
#include "Graphic.h"

//-------------------------------------------------------------------------
// Related Objects
//-------------------------------------------------------------------------

#include "Tile.h"


using namespace PixelGraphics;

extern PixelGraphics::SWA* swa;

//-------------------------------------------------------------------------
// Event Handlers
//-------------------------------------------------------------------------



//-------------------------------------------------------------------------
// Procedures/Methods
//-------------------------------------------------------------------------

void Graphic::initialise(Coord t_res, Coord p_span)
{
	set_grid_span( p_span );
	set_tile_span( t_res );
	set_background_color( NDEWHITE );
	Tile* tile{new Tile};
	this->tiles_link( tile );
	tile->initialise( this );
}

void Graphic::add_tile()
{
	Tile* tile{new Tile};
	this->tiles_link( tile );
	tile->initialise( this );
}



//-------------------------------------------------------------------------
// State Actions
//-------------------------------------------------------------------------



