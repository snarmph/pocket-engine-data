all:
	cc ttf_to_png.c -o ttf -lm

run: clean all
	./ttf ../fonts/pokemon_fire_red.ttf output.png 16

clean:
	rm -f ./ttf