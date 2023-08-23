support ?= 21

CFLAGS += -Wpedantic
CFLAGS += -D_N_=$(support)
LDFLAGS += -framework OpenGL -framework GLUT

test : main.o 
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) 

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean : 
	rm -f test *.o

.PHONY : clean