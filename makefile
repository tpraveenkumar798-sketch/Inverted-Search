OBJ:=$(patsubst %.c,%.o,$(wildcard *.c))

inv.exe: $(OBJ)
	gcc -o $@ $^

clean:
	rm -f *.o *.exe