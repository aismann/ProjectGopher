build: main.o Initialisation.o pugixml.o Game.o Menu.o SplashScreen.o
	g++ main.o Initialisation.o pugixml.o Game.o Menu.o SplashScreen.o -o build -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main.o: main.cpp
	g++ -c -std=c++0x main.cpp

Initialisation.o: Initialisation.h Initialisation.cpp
	g++ -c -std=c++0x Initialisation.h Initialisation.cpp

pugixml.o: ./data/lib/pugixml/pugixml.cpp ./data/lib/pugixml/pugixml.hpp
	g++ -c -std=c++0x ./data/lib/pugixml/pugixml.cpp ./data/lib/pugixml/pugixml.hpp

Game.o: Game.h Game.cpp
	g++ -c -std=c++0x Game.h Game.cpp

Menu.o: Menu.h Menu.cpp
	g++ -c -std=c++0x Menu.h Menu.cpp

SplashScreen.o: SplashScreen.h SplashScreen.cpp
	g++ -c -std=c++0x SplashScreen.h SplashScreen.cpp

clean:
	rm -f *.o *.gch

clean_exe:
	rm -f build
#build: main.o pugixml.o Initialisation.o
#	g++ -o game main.o pugixml.o Initialisation.o
#	echo build: done.

#build.o: Initialisation.h Initialisation.cpp ./data/lib/pugixml/pugixml.cpp ./data/lib/pugixml/pugixml.hpp main.cpp
#	g++ -c -std=c++0x ./data/lib/pugixml/pugixml.cpp ./data/lib/pugixml/pugixml.hpp Initialisation.cpp main.cpp
