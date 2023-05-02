files = main.c menu/menu.c game.c

Island: $(files)
	gcc $(files) -o Island -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf
	./Island