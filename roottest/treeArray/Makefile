NAME=match
FLAGS = `${ROOTSYS}/bin/root-config --cflags --libs` -g
SHOW_FLAGS = `${ROOTSYS}/bin/root-config --cflags --glibs`

#zip: zip.cc KM2AEvent.cpp WFCTAEvent.cpp KM2AEventDict.cpp
#	g++ -g -mcmodel=medium -o $@ $^ ${FLAGS}

$(NAME): $(NAME).cc
	g++ -g -mcmodel=medium -o $@ $^ ${FLAGS}

clean:
	rm -f *.o
