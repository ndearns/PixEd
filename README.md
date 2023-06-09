# PixEd

Pixel Art Editor

A dml tile editor that's really, really, simple, unlike all the pixel art editors I've looked at so far.

[Screenshot](./PixEd_screenshot.png "Screenshot in use")


- [x] Tiles are 16x16.  
- [x] A new Graphic starts with one Tile 
- [x] Tile Pixels can be painted.
- [x] New Tiles can be added.
- [x] A Palette presents the 27 #defined raylib colors in Color wells.  
- [ ] The Palette is saved with the Graphic.
- [x] A Color has R, G, B and Alpha values.
- [ ] The Palette has a Mixer well.
- [x] The Brush can transfer paint from Color wells to the Mixer well.
- [ ] The Mixer well blends the Colors transferred to it.
- [ ] The Mixer well can be wiped clean.
- [ ] The Mixer well Color can be assigned to a Color well.
- [ ] The black and white Color wells cannot be overridden.  They are always available to adjust the mixer Color brightness. 
- [x] Graphics can be exported to PNG files.
- [x] A Brush can be dipped in a Color Well and the Color painted onto the Tile.
- [x] An Eraser erases the Color in pixels, setting them to the background color, with shift-paint.
- [ ] The background Color can be set for the Graphic.
- [x] The default background is off white.
- [x] A new Tile can be created in the sequence of existing Tiles.
- [ ] A new Tile can be created as a copy of an existing Tile.
- [ ] A Tile can be cleared.
- [ ] A Tile can be removed from the Tile sequence.
- [ ] Tiles can be viewed as a Stack, a Strip, or a Grid.

# Domain Outline

```
domain PixelGraphics
{
    object Graphic;
    object Tile;
    object Brush;
    object Eraser;
    object Pixel;
    object Color;
    object ColorWell;
    object Palette;
    object MixerWell;
    object StackView;
    object StripView;
    object GridView;
"---------------------------------------"
    object Harness;
    object Raylib [ archetypes='provided'; ];
"---------------------------------------"
    type Index   : NumericType;
    type Byte    : NumericType;
    type Image   : ProvidedType;
    type Boolean : ProvidedType;
    type Name    : TextType;
};
```
