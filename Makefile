CC := g++

CFLAGS := -g
INCLUDES := -I include $(shell sdl2-config --cflags)
LIBS := libs/ChipM8.a $(shell sdl2-config --libs)

SRC := $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
OBJS := $(SRC:.cpp=.o)


ChipM8-SDL: ${OBJS} ${LIBS}
	$(CC) ${INCLUDES} ${CFLAGS} $^ -o $@

%.o: %.cpp
	$(CC) ${INCLUDES} ${CFLAGS} -c $^ -o $@

.PHONY: clean

clean:
	rm ChipM8-SDL
	rm ${OBJS}