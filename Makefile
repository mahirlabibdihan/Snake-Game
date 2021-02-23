all: game

game: Point.o iGraphics.o Graph.o Colors.o Circle.o Box.o Button.o Food.o Animal.o Window.o Details.o Keyboard.o Mouse.o draw.o Main.o
	g++32  -Llib  Point.o iGraphics.o Graph.o Colors.o Circle.o Box.o Button.o Food.o Animal.o Window.o Details.o Keyboard.o Mouse.o draw.o Main.o -o game -lfreeglut -lGlaux -lopengl32 -lglu32 -lwinmm -lgdi32 -static-libgcc -static-libstdc++ 

Main.o: Main.cpp
	g++32 -Iinclude   -c Main.cpp

Colors.o: Colors.cpp
	g++32 -Iinclude   -c Colors.cpp 

Circle.o: Circle.cpp
	g++32 -Iinclude   -c Circle.cpp

Graph.o: Graph.cpp
	g++32 -Iinclude   -c Graph.cpp

iGraphics.o: iGraphics.cpp
	g++32 -Iinclude   -c iGraphics.cpp

Food.o: Food.cpp
	g++32 -Iinclude   -c Food.cpp

Animal.o: Animal.cpp
	g++32 -Iinclude   -c Animal.cpp

Window.o: Window.cpp
	g++32 -Iinclude   -c Window.cpp

Details.o: Details.cpp
	g++32 -Iinclude   -c Details.cpp

Button.o: Button.cpp
	g++32 -Iinclude   -c Button.cpp

Box.o: Box.cpp
	g++32 -Iinclude   -c Box.cpp

Keyboard.o: Keyboard.cpp
	g++32 -Iinclude   -c Keyboard.cpp

Mouse.o: Mouse.cpp
	g++32 -Iinclude   -c Mouse.cpp

draw.o: draw.cpp
	g++32 -Iinclude   -c draw.cpp

Point.o: Point.cpp
	g++32 -Iinclude   -c Point.cpp

run: game
	./game

clean:
	rm -rf *o



# g++32 -Iinclude   -c ${file} -o a.o && g++32 -Llib a.o