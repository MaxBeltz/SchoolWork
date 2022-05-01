otpt: Driver.cpp congaline.o pirate.o node.o
	g++ Driver.cpp congaline.o pirate.o node.o -o otpt

congaline.o: congaline.cpp node.o pirate.o
	g++ -c congaline.cpp pirate.o node.o -o congaline.o

node.o: node.cpp pirate.o
	g++ -c node.cpp pirate.o -o node.o
	
pirate.o: pirate.cpp
	g++ -c pirate.cpp -o pirate.o
	
clean: rm -f *.o otpt