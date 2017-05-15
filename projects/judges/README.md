This is my assignment-4 submission!


To compile and run the Smithy:

make randomtestcard1
./randomtestcard1


To run gcov on the Smithy and see coverage:

make gcovRand1
./a.out
gcov randomtestcard1.c


To compile and run the Village:

make randomtestcard2
./randomtestcard2


To run gcov on the Village and see coverage:

make gcovRand2
./a.out
gcov randomtestcard2.c


To compile and run the Adventurer:

make randomtestadventurer
./randomtestadventurer


To run gcov on the Adventurer and see coverage:

make gcovRandAdv
./a.out
gcov randomtestadventurer.c


To run all gcov tests and see in randomtestresults.out:

randomAll: gcovRand1 gcovRand2 gcovRandAdv
	./randomtestcard1
	./a.out
	gcov randomtestcard1.c > randomtestresults.c
	./randomtestcard2
	./a.out
	gcov randomtestcard2.c >> randomtestresults.c
	./randomtestadventurer
	./a.out
	gcov randomtestadventurer.c >> randomtestresults.c
	
	./randomtestadventurer