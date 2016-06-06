CC=g++
CFLAGS=-Wall -std=c++11

44:
	$(CC) $(CFLAGS) 44.cpp ../mathlib/algorithm.h -o 44

43:
	$(CC) $(CFLAGS) 43.cpp ../mathlib/algorithm.h -o 43

42:
	$(CC) $(CFLAGS) 42.cpp ../mathlib/algorithm.h -o 42

41: prime.o
	$(CC) $(CFLAGS) 41.cpp ../mathlib/mathlib.h prime.o -o 41

40: mathlib.o
	$(CC) $(CFLAGS) 40.cpp mathlib.o -o 40

39:
	$(CC) $(CFLAGS) 39.cpp -o 39

38: mathlib.o
	$(CC) $(CFLAGS) 38.cpp mathlib.o -o 38

37: prime.o mathlib.o
	$(CC) $(CFLAGS) 37.cpp prime.o mathlib.o -o 37

36: mathlib.o
	$(CC) $(CFLAGS) 36.cpp mathlib.o -o 36

35: prime.o mathlib.o
	$(CC) $(CFLAGS) 35.cpp prime.o mathlib.o -o 35

34: mathlib.o
	$(CC) $(CFLAGS) 34.cpp mathlib.o -o 34

33: rational.o mathlib.o
	$(CC) $(CFLAGS) 33.cpp rational.o mathlib.o -o 33

prime.o:
	$(CC) $(CFLAGS) -c ../mathlib/prime.cpp

rational.o:
	$(CC) $(CFLAGS) -c ../mathlib/rational.cpp

mathlib.o:
	$(CC) $(CFLAGS) -c ../mathlib/mathlib.cpp

clean:
	rm -f *.o 33 34 35 36 37 38 39 40 41 42