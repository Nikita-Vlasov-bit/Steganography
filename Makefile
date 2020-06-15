output: main.o Steganography.o
	g++ main.o Steganography.o -o output
	
main.o: main.cpp
	g++ -c main.cpp
	
Steganography.o: Steganography.cpp Steganography.h
	g++ -c Steganography.cpp
	
clean:
	rm *.o output
