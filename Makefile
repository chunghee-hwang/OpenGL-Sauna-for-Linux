sauna : light.o CameraMove.o bitmaploader.o sauna.o -lGL -lGLU -lglut -lm

light.o : light.cpp
	g++ -c -o light.o light.cpp

CameraMove.o : CameraMove.cpp
	g++ -c -o CameraMove.o CameraMove.cpp

bitmaploader.o : bitmaploader.cpp
	g++ -c -o bitmaploader.o bitmaploader.cpp
sauna.o : sauna.cpp
	g++ -c -o sauna.o sauna.cpp

clean:
	rm *.o sauna
