main: main.o imageio.o invert.o box.o
	g++ -o main main.o imageio.o invert.o box.o

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.h

main.o: main.cpp imageio.h invert.h box.h

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h

invert.o: invert.cpp invert.h

box.o: box.cpp box.h

clean:
	rm -f main.o sample.o imageio.o invert.o box.o