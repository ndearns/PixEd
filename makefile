CC = g++
CCFLAGS = -std=c++2a -g -Wall -Ofast
GEN_MODE = async
DML_DOM = PixelGraphics
DML_OBJS= Harness Graphic Tile Pixel Palette ColorWell
LIBS= -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

run: EventQueue.o *.dml $(DML_DOM)Provided.h Raylib.h
	dml $(DML_DOM) $(GEN_MODE)
	for obj in $(DML_OBJS); do \
		$(CC) $(CCFLAGS) -c $$obj.cpp -o $$obj.o; \
	done
	$(CC) $(CCFLAGS) *.o -o run $(LIBS)

gen: *.dml
	dml $(DML_DOM) $(GEN_MODE)

%.o: %.cpp %.h
	$(CC) $(CCFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o ./run $(DML_DOM).h
	for obj in $(DML_OBJS); do \
		rm -f $$obj.cpp $$obj.h; \
	done

