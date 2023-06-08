
/*----------------------------------------
 * Harness.cpp
 *
 * 
 *
 *	Generated with async option
 *
 *----------------------------------------*/

#include <iostream>
#include <cassert>
#include "PixelGraphics.h"
#include "Harness.h"

//-------------------------------------------------------------------------
// Related Objects
//-------------------------------------------------------------------------

#include "Raylib.h"
#include "Graphic.h"
#include "Tile.h"
#include "Palette.h"
#include "Pixel.h"
#include "ColorWell.h"


using namespace PixelGraphics;

extern PixelGraphics::SWA* swa;

//-------------------------------------------------------------------------
// Event Handlers
//-------------------------------------------------------------------------



//-------------------------------------------------------------------------
// Procedures/Methods
//-------------------------------------------------------------------------

int main()
{
	Harness* the_harness{new Harness};
	Raylib* the_ui{new Raylib};
	Graphic* the_graphic{new Graphic};
	Palette* the_palette{new Palette};
	the_harness->initialise();
	the_harness->ui_link( the_ui );
	the_graphic->initialise( the_harness->t_res(), the_harness->p_span());
	the_harness->graphic_link( the_graphic );
	the_harness->set_working_tile_index(0);
	the_harness->working_tile_link( the_graphic->tiles()[0]);
	the_harness->palette_link( the_palette );
	the_palette->initialise();
	the_harness->start();
	the_harness->ui_unlink();
	return ExitCode :: Ok;
}

void Harness::initialise()
{
	set_t_res(24);
	set_p_span(32);
	set_x_tile((3* p_span()));
	set_y_tile((3* p_span()));
	set_x_palette((3* p_span())+( t_res()* p_span())+(1* p_span()));
	set_y_palette((3* p_span()));
	set_x_add_tile((3* p_span())+( t_res()* p_span())+(1* p_span()));
	set_y_add_tile((3* p_span())+( t_res()* p_span())-(2* p_span()));
	set_x_del_tile((3* p_span())+( t_res()* p_span())+(2* p_span()));
	set_y_del_tile((3* p_span())+( t_res()* p_span())-(2* p_span()));
	set_x_next_tile((3* p_span())+( t_res()* p_span())+(2* p_span()));
	set_y_next_tile((3* p_span())+( t_res()* p_span())-(3* p_span()));
	set_x_prev_tile((3* p_span())+( t_res()* p_span())+(1* p_span()));
	set_y_prev_tile((3* p_span())+( t_res()* p_span())-(3* p_span()));
	set_x_save_tile((3* p_span())+( t_res()* p_span())+(1* p_span()));
	set_y_save_tile((3* p_span())+( t_res()* p_span())-(1* p_span()));
	set_x_load_tile((3* p_span())+( t_res()* p_span())+(2* p_span()));
	set_y_load_tile((3* p_span())+( t_res()* p_span())-(1* p_span()));
}

void Harness::start()
{
	ui()->init_window((3* p_span())+( t_res()* p_span())+(7* p_span()),(3* p_span())+( t_res()* p_span())+(3* p_span()),"PixelGraphics domain harness");
	ui()->set_target_fps(60);

	// foreach														
	for( FrameCount i = 0; 0<= i &&! ui()->window_should_close(); i++) {								
		 do_frame( i );												
	}																

	ui()->close_window();
}

void Harness::do_frame(FrameCount frame_number)
{
	set_mdown( false );

	if (ui()->mouse_button_is_down(0)) {  set_mdown( true ); };

	if (! mpressed()&& ui()->mouse_button_pressed(0)) {  set_mpressed( true ); };
	set_mpos( ui()->get_mouse_position());
	set_sdown( ui()->is_key_down( KEY_LEFT_SHIFT ));
	Boolean tile_hit{mdown_in_grid( x_tile(), y_tile(), t_res(), t_res())};

	if (mdown()&& tile_hit &&! sdown()) { paint_pixel_under_mouse(); };

	if (mdown()&& tile_hit && sdown()) { erase_pixel_under_mouse(); };
	Boolean palette_hit{mdown_in_grid( x_palette(), y_palette(),3,9)};

	if (mdown()&& palette_hit ) { select_color_well_under_mouse(); };
	Boolean add_button_hit{mdown_on_tile_at( x_add_tile(), y_add_tile())};

	if (mpressed()&& add_button_hit ) { graphic()->add_tile(); };

	if (mpressed()&& add_button_hit ) { set_working_tile_index( graphic()->tiles().size()-1); };

	if (mpressed()&& add_button_hit ) { working_tile_link( graphic()->tiles()[ working_tile_index()]); };
	Boolean prev_button_hit{mdown_on_tile_at( x_prev_tile(), y_prev_tile())};

	if (mpressed()&& prev_button_hit &&0< working_tile_index()) { set_working_tile_index( working_tile_index()-1); };

	if (mpressed()&& prev_button_hit &&0<= working_tile_index()) { working_tile_link( graphic()->tiles()[ working_tile_index()]); };
	Boolean next_button_hit{mdown_on_tile_at( x_next_tile(), y_next_tile())};

	if (mpressed()&& next_button_hit && working_tile_index()< graphic()->tiles().size()-1) { set_working_tile_index( working_tile_index()+1); };

	if (mpressed()&& next_button_hit && working_tile_index()< graphic()->tiles().size()) { working_tile_link( graphic()->tiles()[ working_tile_index()]); };
	Boolean save_button_hit{mdown_on_tile_at( x_save_tile(), y_save_tile())};

	if (mpressed()&& save_button_hit ) { save_graphic(); };
	Boolean load_button_hit{mdown_on_tile_at( x_load_tile(), y_load_tile())};

	if (mpressed()&& load_button_hit ) { load_graphic(); };

	if (mpressed()) {  set_mpressed( false ); };
	EventQueue :: defaultEQ()->service_queue();
	ui()->begin_drawing();
	ui()->clear_background( WHITE );
	draw_time();
	draw_working_tile();
	draw_palette();
	draw_button_at("<<", x_prev_tile(), y_prev_tile());
	draw_button_at(">>", x_next_tile(), y_next_tile());
	draw_button_at("+", x_add_tile(), y_add_tile());
	draw_button_at("-", x_del_tile(), y_del_tile());
	draw_button_at("S", x_save_tile(), y_save_tile());
	draw_button_at("L", x_load_tile(), y_load_tile());
	ui()->end_drawing();
}

Boolean Harness::mdown_on_tile_at(Coord x, Coord y)
{
	Boolean result{false};
	Coord dx{0};
	dx = x + p_span();
	Coord dy{0};
	dy = y + p_span();

	if (x < mpos().x && mpos().x < dx && y < mpos().y && mpos().y < dy ) { result = true; };
	return result;
}

void Harness::select_color_well_under_mouse()
{
	Coord x{0};
	Coord y{0};
	x =( mpos().x - x_palette())/ p_span();
	y =( mpos().y - y_palette())/ p_span();
	set_bcolor( palette()->color_wells()[ y *3+ x ]->color());
}

Boolean Harness::mdown_in_grid(Coord x1, Coord y1, Coord dx, Coord dy)
{
	Boolean result{false};
	Coord x2{0};
	x2 = x1 +( p_span()* dx );
	Coord y2{0};
	y2 = y1 +( p_span()* dy );

	if (x1 < mpos().x && mpos().x < x2 && y1 < mpos().y && mpos().y < y2 ) { result = true; };
	return result;
}

void Harness::paint_pixel_under_mouse()
{
	Coord pixel_span{graphic()->grid_span()};
	Coord x{0};
	Coord y{0};
	x =( mpos().x - x_tile())/ pixel_span;
	y =( mpos().y - y_tile())/ pixel_span;

	// foreach														
	for(auto pix : working_tile()->pixels()) {
		if ( (pix->x()== x && pix->y()== y ) ) {							
			 pix->set_color( bcolor());											
		}															
	}																

}

void Harness::erase_pixel_under_mouse()
{
	Coord pixel_span{graphic()->grid_span()};
	Coord x{0};
	Coord y{0};
	x =( mpos().x - x_tile())/ pixel_span;
	y =( mpos().y - y_tile())/ pixel_span;

	// foreach														
	for(auto pix : working_tile()->pixels()) {
		if ( (pix->x()== x && pix->y()== y ) ) {							
			 pix->set_color( graphic()->background_color());											
		}															
	}																

}

void Harness::draw_button_at(Label label, Coord x, Coord y)
{
	ui()->draw_rectangle_lines( x, y, p_span(), p_span(), DARKGRAY );
	ui()->draw_text( label, x + p_span()/5, y +2, p_span(), DARKGRAY );
}

void Harness::draw_palette()
{

	// foreach														
	for( Coord n = 0; 0<= n && n < palette()->color_wells().size(); n++) {								
		 draw_color_well( n );												
	}																

}

void Harness::draw_color_well(Coord n)
{
	Coord x_well{0};
	Coord y_well{0};
	x_well = x_palette()+( p_span()*( n %3));
	y_well = y_palette()+( p_span()*( n /3));
	ui()->draw_rectangle( x_well, y_well, p_span(), p_span(), palette()->color_wells()[ n ]->color());
	ui()->draw_rectangle_lines( x_well, y_well, p_span(), p_span(), DARKGRAY );
}

void Harness::draw_working_tile()
{

	// foreach														
	for(auto p : working_tile()->pixels()) {
		 draw_pixel( p );												
	}																

}

void Harness::draw_pixel(Pixel* p)
{
	Coord x{0};
	x = x_tile()+( p_span()* p->x());
	Coord y{0};
	y = y_tile()+( p_span()* p->y());
	ui()->draw_rectangle( x, y, p_span(), p_span(), p->color());
	ui()->draw_rectangle_lines( x, y, p_span(), p_span(), LIGHTGRAY );
}

void Harness::draw_mouse_coords()
{
	ui()->draw_text( mpos().x,20,50, p_span(), BLACK );
	ui()->draw_text( mpos().y,20,80, p_span(), BLACK );
}

void Harness::draw_time()
{
	Coord screen_width{ui()->get_screen_width()};
	ui()->draw_text( ui()->time_HHMMSS(),( screen_width /2)-80,20, p_span(), PINK );
}

void Harness::save_graphic()
{
	PixelGraphics :: swa->println("save file!");
}

void Harness::load_graphic()
{
	PixelGraphics :: swa->println("load file!");
}



//-------------------------------------------------------------------------
// State Actions
//-------------------------------------------------------------------------



