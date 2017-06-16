CC = g++ -std=c++11 -w

SRCS = ./*.cpp

main: SRC
	$(CC) -o $@ *.o

SRC: $(SRCS)
	$(CC) -c $(SRCS)

.PHONY: clean
clean:
ifeq ($(OS),Windows_NT)
	del main.exe *.o
else
	rm -f main *.o
endif
