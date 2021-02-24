all: game

game: Point.o iGraphics.o Grid.o color.o Circle.o Box.o Button.o Food.o Snake.o game_window.o game_details.o Keyboard.o Mouse.o draw.o highscore.o name_entry.o Main.o
	g++32  -Llib  Point.o iGraphics.o Grid.o color.o Circle.o Box.o Button.o Food.o Snake.o game_window.o game_details.o Keyboard.o Mouse.o draw.o highscore.o name_entry.o Main.o -o game -lfreeglut -lGlaux -lopengl32 -lglu32 -lwinmm -lgdi32 -static-libgcc -static-libstdc++ 

Main.o: Main.cpp
	g++32 -Iinclude   -c Main.cpp

color.o: color.cpp
	g++32 -Iinclude   -c color.cpp 

Circle.o: Circle.cpp
	g++32 -Iinclude   -c Circle.cpp

Grid.o: Grid.cpp
	g++32 -Iinclude   -c Grid.cpp

iGraphics.o: iGraphics.cpp
	g++32 -Iinclude   -c iGraphics.cpp

Food.o: Food.cpp
	g++32 -Iinclude   -c Food.cpp

Snake.o: Snake.cpp
	g++32 -Iinclude   -c Snake.cpp

game_window.o: game_window.cpp
	g++32 -Iinclude   -c game_window.cpp

game_details.o: game_details.cpp
	g++32 -Iinclude   -c game_details.cpp

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

highscore.o: highscore.cpp
	g++32 -Iinclude   -c highscore.cpp

name_entry.o: name_entry.cpp
	g++32 -Iinclude   -c name_entry.cpp

run: game
	./game

clean:
	rm -rf *o



# g++32 -Iinclude   -c ${file} -o a.o && g++32 -Llib a.o