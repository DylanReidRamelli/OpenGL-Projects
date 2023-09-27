support ?= 21
CC = gcc

CFLAGS += -Wpedantic -march=znver2
CFLAGS += -D_N_=$(support)

OS := $(shell uname)
ifeq ($(OS), Darwin)
# Run MacOS commands
LDFLAGS += -framework OpenGL -framework GLUT -lGLEW
else
# check for Linux and run other commands
LDFLAGS += -lGL -lglut -lGLEW
endif

test : main.o 
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean : 
	rm -f test *.o

.PHONY : clean