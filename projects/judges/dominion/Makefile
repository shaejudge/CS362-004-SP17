CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	
unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
	
unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
	
unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
	
unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
	
cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
	
cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
	
cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
	
cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)

gcovU1: unittest1.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage unittest1.c dominion.o rngs.o -lm
	
gcovC1: cardtest1.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage cardtest1.c dominion.o rngs.o -lm
	
gcovC2: cardtest2.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage cardtest2.c dominion.o rngs.o -lm
	
gcovC3: cardtest3.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage cardtest3.c dominion.o rngs.o -lm
	
gcovC4: cardtest4.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage cardtest4.c dominion.o rngs.o -lm
	
gcovAll: gcovU1 gcovC1 gcovC2 gcovC3 gcovC4

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	
gcovRand1: randomtestcard1.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage randomtestcard1.c dominion.o rngs.o -lm

gcovRand2: randomtestcard2.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage randomtestcard2.c dominion.o rngs.o -lm
	
gcovRandAdv: randomtestadventurer.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage randomtestadventurer.c dominion.o rngs.o -lm
	
randomAll: gcovRand1 gcovRand2 gcovRandAdv
	./randomtestcard1 > randomtestresults.out
	./randomtestcard2 >> randomtestresults.out
	./randomtestadventurer >> randomtestresults.out
	
	#gcov randomtestcard1.c


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
