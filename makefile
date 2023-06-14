CC       = g++
CCFLAGS  = -std=c++2a -g -Wall -Ofast
GEN_MODE = async
DOM_NAME = PixelGraphics
DML_DOM  = PixelGraphics.dml
DML_OBJS = Harness.dml Graphic.dml Tile.dml Pixel.dml Palette.dml ColorWell.dml 
CPP_OBJS = $(DML_OBJS:.dml=.cpp)
H_OBJS   = $(DML_OBJS:.dml=.h)
LIB_OBJS = $(CPP_OBJS:.cpp=.o)
INC_DIRS = -I ${DML}/SWA
LIBS     = -L${DML}/SWA -lSWA -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

lib: $(filter-out Harness.o,$(LIB_OBJS)) $(DOM_NAME)Provided.h
	ar -rcs lib$(DOM_NAME).a $(filter-out Harness.o,$(LIB_OBJS))

run: $(LIB_OBJS) $(DOM_NAME)Provided.h
	$(CC) $(CCFLAGS) $(LIB_OBJS) -o run $(LIBS)

gen: *.dml
	dml $(DOM_NAME) $(GEN_MODE)

$(LIB_OBJS): $(CPP_OBJS)

$(CPP_OBJS): $(DML_OBJS) $(DOM_NAME).dml $(DOM_NAME)Provided.h
	dml $(DOM_NAME) $(GEN_MODE)             

.cpp.o:                                 
	$(CC) $(CCFLAGS) $(INC_DIRS) -c $< -o $@           

.PHONY: clean tidy
clean:
	rm -f *.o ./run lib$(DOM_NAME).a $(DOM_NAME).h
	for obj in $(basename $(DML_OBJS)); do \
		rm -f $$obj.cpp $$obj.h; \
	done

tidy:
	rm -f *.o $(DOM_NAME).h
	for obj in $(basename $(DML_OBJS)); do \
		rm -f $$obj.cpp; \
	done

