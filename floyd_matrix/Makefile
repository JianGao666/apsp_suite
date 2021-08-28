KERN=floyd

CFLAGS?=-O3 -Wall -Wno-unused-label

CC = gcc

SRCS=$(KERN).c
FILES=$(SRCS) $(KERN).h 

run: main input.data 
	./main

$(KERN): $(FILES) 
	$(CC) $(CFLAGS) -o $(KERN).o $(SRCS) 

main: $(KERN).o ../common/main.c
	$(CC) $(CFLAGS) -o main $(SRCS) ../common/main.c local_support.c

hls: $(KERN).c $(KERN).h
	vivado_hls hls.tcl

clean:
	rm -f main $(KERN).o
