build: main.o Initialisation.o pugixml.o Game.o Menu.o MainMenu.o Options.o Splash.o
	g++ main.o Initialisation.o pugixml.o Game.o Menu.o Options.o MainMenu.o Splash.o -o build -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

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

MainMenu.o: MainMenu.h MainMenu.cpp
	g++ -c -std=c++0x MainMenu.h MainMenu.cpp

Options.o: Options.h Options.cpp
	g++ -Wall -c -std=c++0x Options.h Options.cpp

Splash.o: Splash.h Splash.cpp
	g++ -c -std=c++0x Splash.h Splash.cpp

clean:
	rm -f *.o *.gch

clean_exe:
	rm -f build
