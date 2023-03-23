

main: main.o invert.o box.o imageio.o
	g++ -o main -std=c++11 main.o invert.o box.o imageio.o


main.o: main.cpp invert.cpp invert.h box.cpp box.h 
	g++ -c -std=c++11 main.cpp invert.cpp box.cpp 
 

imageio.o: imageio.cpp imageio.h
	g++ -c -std=c++11 imageio.cpp


clean:
	rm -f sample.o imageio.o main.o invert.o box.o
	rm -f main a.out sample
	rm -f taskA.pgm taskB.pgm taskC.pgm taskD.pgm taskE.pgm taskF.pgm