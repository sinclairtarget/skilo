builddir = build
objects = $(builddir)/term.o $(builddir)/skilo.o 
CFLAGS = -Wall -Wextra -pedantic -std=c99

# Tell make that prerequisites of these types can be found in src/
vpath %.c src/
vpath %.h src/

# builddir is a "order-only" prerequisite. It's updated first if this target is
# updated, but not used to determine if this target is out-of-date.
skilo: $(objects) | $(builddir)
	$(CC) -o build/skilo $(objects) 

# Pattern rule
$(objects): $(builddir)/%.o : %.c | $(builddir)
	$(CC) $(CFLAGS) -c $< -o $@  # $< is first prereq, $@ is all targets

# Append prerequisites
skilo.o: term.h
term.o: term.h

$(builddir):
	mkdir -p $(builddir)

.PHONY: clean  # PHONY rules can't be mistaken for files.
clean:
	rm -rf $(builddir)
