CC=g++
OPTS=-g

test: all
	bunzip2 -c -k ../traces/DIST-INT-1.bz2 | ./predictor
	bunzip2 -c -k ../traces/DIST-FP-1.bz2 | ./predictor
	bunzip2 -c -k ../traces/DIST-MM-2.bz2 | ./predictor
	bunzip2 -c -k ../traces/DIST-SERV-1.bz2 | ./predictor

all: main.o traceread.o predictor.o
	$(CC) $(OPTS) -lm -o predictor main.o traceread.o predictor.o

main.o: main.C traceread.h predictor.h
	$(CC) $(OPTS) -c main.C

traceread.o: traceread.h traceread.C
	$(CC) $(OPTS) -c traceread.C

predictor.o: predictor.h predictor.C
	$(CC) $(OPTS) -c predictor.C

clean:
	rm -f *.o predictor;
