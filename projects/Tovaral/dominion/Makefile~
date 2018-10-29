CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

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
	
card1:
	gcc -fprofile-arcs -ftest dominion.o cardtest1.c rngs.o -o cardtest1 -g $(CFLAGS)

card2:
	gcc -fprofile-arcs -ftest dominion.o cardtest2.c rngs.o -o cardtest2 -g $(CFLAGS)

card3:
	gcc -fprofile-arcs -ftest dominion.o cardtest3.c rngs.o -o cardtest3 -g $(CFLAGS)

card4:
	gcc -fprofile-arcs -ftest dominion.o cardtest4.c rngs.o -o cardtest4 -g $(CFLAGS)

	
unit1:
	gcc -fprofile-arcs -ftest dominion.o unittest1.c rngs.o -o unittest1 -g $(CFLAGS)

unit2:
	gcc -fprofile-arcs -ftest dominion.o unittest2.c rngs.o -o unittest2 -g $(CFLAGS)

unit3:
	gcc -fprofile-arcs -ftest dominion.o unittest3.c rngs.o -o unittest3 -g $(CFLAGS)

unit4:
	gcc -fprofile-arcs -ftest dominion.o unittest4.c rngs.o -o unittest4 -g $(CFLAGS)



myTest:
	./unittest1 &> unittestresult.out
	./unittest2 >> unittestresult.out
	./unittest3 >> unittestresult.out
	./unittest4 >> unittestresult.out
	./cardtest1 >> unittestresult.out
	./cardtest2 >> unittestresult.out
	./cardtest3 >> unittestresult.out
	./cardtest4 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
