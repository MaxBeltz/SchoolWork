Sort.exe:  Driver.o InsertionSort.o bubbleSort.o
	g++ Driver.o InsertionSort.o bubbleSort.o -o Sort.exe
Driver.o: Driver.cpp
	g++ -c Driver.cpp -o Driver.o
InsertionSort.o: InsertionSort.cpp
	g++ -c InsertionSort.cpp -o InsertionSort.o
bubbleSort.o: bubbleSort.cpp
	g++ -c bubbleSort.cpp -o bubbleSort.o
clean: 
	rm -f *.o
	rm Sort.exe
val:
	valgrind --leak-check=full --show-leak-kinds=all ./Sort.exe
valt:
	valgrind --tool=memcheck --log-file=Valgrind.text ./Sort.exe
run: 
	./Sort.exe
