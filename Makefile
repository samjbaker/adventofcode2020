# the compiler: clang or gcc for C program, define as g++ for C++
CC = /usr/local/bin/gcc-10
#CC = gcc
#CC = clang

#to detect leaks run using command: ASAN_OPTIONS=detect_leaks=1 ./test

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#-g3 is debugging flag instead of O2
CFLAGS  = -Wall -Wextra -pedantic -std=c90 -g3 -lm -fsanitize=address -fsanitize=undefined
#CFLAGS  = -Wall -Wextra -pedantic -std=c90 -g3 -lm -lSDL2 -fsanitize=address -fsanitize=undefined
#CFLAGS  = -Wall -Wextra -pedantic -std=c90 -O2 -lm

# the build target executable:
TARGET = myprog

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)
