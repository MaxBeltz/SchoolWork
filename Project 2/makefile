otpt: driver.cpp bitarray.o set.o dictionary.o
	g++ driver.cpp bitarray.o set.o dictionary.o -o otpt

set.o: set.cpp set.h bitarray.o
	g++ -c set.cpp -o set.o

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o
	
bitarray.o: bitarray.cpp
	g++ -c bitarray.cpp -o bitarray.o
	
dictionary.o: dictionary.cpp dictionary.h set.o bitarray.o
	g++ -c dictionary.cpp -o dictionary.o
	
clean: 
	rm -f *.o otpt