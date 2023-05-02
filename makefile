files = main.c menu/menu.c 

game: $(files)
	gcc $(files) -o game -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf
	./game