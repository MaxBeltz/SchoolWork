testrec: rectangle.o square.o
	g++ getrect2.cpp -o testrec rectangle.o square.o
	
square.o: rectangle.o
	g++ -c square.cpp
	
rectangle.o: rectangle.cpp
	g++ -c rectangle.cpp
	
clean:
	rm -f *.o blah