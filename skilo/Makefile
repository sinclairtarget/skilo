builddir = build
objects = $(builddir)/term.o $(builddir)/skilo.o 

skilo: build $(objects)
	$(CC) -o build/skilo $(objects) 

build:
	mkdir -p $(builddir)

build/skilo.o: src/skilo.c
	$(CC) -c src/skilo.c -o build/skilo.o -Wall -Wextra -pedantic -std=c99

build/term.o: src/term.c
	$(CC) -c src/term.c -o build/term.o -Wall -Wextra -pedantic -std=c99

.PHONY: clean
clean:
	rm -rf $(builddir)
