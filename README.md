# PixEd

Pixel Art Editor

A dml tile editor that's really, really, simple, unlike all the pixel art editors I've looked at so far.

- Tiles are 32x32.  
- A new Graphic starts with one Tile and you can add more.
- A Palette presents 16 default colors in Color wells.  
- The Palette is saved with the Graphic.
- A Color has R, G, B and Alpha values.
- The Palette has a Mixer well.
- The Brush can transfer paint from Color wells to the Mixer well.
- The Mixer well blends the Colors transferred to it.
- The Mixer well can be wiped clean.
- The Mixer well Color can be assigned to a Color well.
- The black and white Color wells cannot be overridden.  They are always available to adjust the mixer Color brightness. 
- Graphics can be exported to PNG files.
- A Brush can be dipped in a Color and the Color painted onto the Tile.
- An Eraser erases the Color in pixels, setting them to the background color.
- The background Color can be set for the Graphic.
- The default background is transparent.
- A new Tile can be created in the sequence of existing Tiles.
- A new Tile can be created as a copy of an existing Tile.
- A Tile can be cleared.
- A Tile can be removed from the Tile sequence.
- Tiles can be viewed as a Stack, a Strip, or a Grid.

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
    type Boolean : ProvidedType;
    type Name    : TextType;
};
```
