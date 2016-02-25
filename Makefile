CC=g++
OPTIONS= -g
DEBUG= #-D DEBUG
LIBDIR=lib
INCLUDEDIR=include
_OBJ= tporo.o
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))
RUTA = src/tad10.cpp

tad: $(RUTA) $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) $(RUTA) $(OBJ) -o tad
	$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<
clean:
	rm -f $(OBJ)