VANILLAPATH = /home/kevidryon2/.local/share/pictrel/vanilla

all: clean run

build/%t: tools/%.c
	clang -g -o $@ $< -lraylib

clean:
	rm -f build/*

build/vanilla.krp: build/krpt
	./build/krpt build/vanilla.krp assets/*

build/vanilla:
	gcc -g src/*.c -lraylib -lX11 -lpthread -lGL -lm -lupix -o build/vanilla

run: install 
	$(VANILLAPATH)/vanilla
	
install: build/vanilla build/vanilla.krp
	cp build/* $(VANILLAPATH)
