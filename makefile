files = main.c menu/menu.c game.c settings/settings.c player/player.c enemy/enemy.c background/background.c minimap/minimap.c

Island: $(files)
	gcc $(files) -o Island -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lm
	./Island