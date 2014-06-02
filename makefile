all:
	clear
	g++ -c main.cpp Rocket.cpp -std=c++11
	g++ main.o Rocket.o -std=c++11 -o vectorRocket -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
	rm main.o