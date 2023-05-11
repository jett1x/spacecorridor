CFLAGS =  -O3 -Dmain=SDL_main
LDFLAGS = -lm -lmingw32 -lSDL2main -lSDL2 -L C:\MinGW\lib\gcc\mingw32\6.3.0
SDL2_INCLUDE_DIR = C:\SDL2\i686-w64-mingw32\include
SDL2_LIBRARIES_DIR = C:\SDL2\i686-w64-mingw32\lib
INC = sdl2-light.h space_graphics.h space_logics.h space_const.h
SRC = main.c sdl2-light.c space_graphics.c space_logics.c
OBJ = $(SRC:%.c=%.o)

PROG = spacecorridor.exe

%.o: %.c $(INC)
	gcc $(CFLAGS) -c $<  -I $(SDL2_INCLUDE_DIR)

$(PROG): $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@ -L $(SDL2_LIBRARIES_DIR)

doc: $(PROG)
	doxygen $(PROG)

.PHONY: clean
clean:
	del /f /q *.o *~ $(PROG)
	rd /s /q latex html
