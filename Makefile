all: proj3.exe

doClipColor.o: doClipColor.cpp doClipColor.h constants.h
	g++ -std=c++98 -Wall -c doClipColor.cpp -o doClipColor.o

doClip.o: doClip.cpp doClip.h constants.h doClipColor.h
	g++ -std=c++98 -Wall -c doClip.cpp -o doClip.o

askForFile.o: askForFile.cpp askForFile.h constants.h
	g++ -std=c++98 -Wall -c askForFile.cpp -o askForFile.o

askForColor.o: askForColor.cpp askForColor.h constants.h
	g++ -std=c++98 -Wall -c askForColor.cpp -o askForColor.o

askForInsertIdx.o: askForInsertIdx.cpp askForInsertIdx.h constants.h RowColumnClass.h
	g++ -std=c++98 -Wall -c askForInsertIdx.cpp -o askForInsertIdx.o

ColorClass.o: ColorClass.h ColorClass.cpp constants.h doClip.h
	g++ -std=c++98 -Wall -c ColorClass.cpp -o ColorClass.o

RectangleClass.o: RectangleClass.h RectangleClass.cpp ColorClass.h
	g++ -std=c++98 -Wall -c RectangleClass.cpp -o RectangleClass.o

RowColumnClass.o: RowColumnClass.h RowColumnClass.cpp constants.h doClip.h
	g++ -std=c++98 -Wall -c RowColumnClass.cpp -o RowColumnClass.o

ColorImageClass.o: ColorImageClass.h ColorImageClass.cpp constants.h RectangleClass.h
	g++ -std=c++98 -Wall -c ColorImageClass.cpp -o ColorImageClass.o

project3.o: project3.cpp ColorImageClass.h ColorClass.h RowColumnClass.h constants.h RectangleClass.h
	g++ -std=c++98 -Wall -c project3.cpp -o project3.o

proj3.exe: project3.o doClipColor.o doClip.o askForFile.o askForColor.o askForInsertIdx.o ColorClass.o RowColumnClass.o ColorImageClass.o RectangleClass.o
	g++ -std=c++98 -Wall project3.o doClipColor.o doClip.o askForFile.o askForColor.o askForInsertIdx.o ColorClass.o RowColumnClass.o ColorImageClass.o RectangleClass.o -o proj3.exe

clean:
	rm -f *.o *.exe
