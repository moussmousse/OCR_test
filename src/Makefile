#MAKEFILE 
#for the OCR project

# Compilers and options
CC=gcc
CPPFLAGS= -MMD
CFLAGS= -Wall -Wextra -std=c99 -pedantic -O2 -g
LDFLAGS=
LDLIBS= -lm
 
SRC = neuronal_network/list.c neuronal_network/neuro.c neuronal_network/use_neuro.c  main.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

all: main
 
main: ${OBJ}
 
-include ${DEP}
 
clean:
	rm -f ${OBJ} ${DEP}
	rm -f main
 
# END
