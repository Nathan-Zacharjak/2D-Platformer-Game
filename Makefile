all: compile run
compile: Collision.cpp Platform.cpp  Bullet.cpp Gun.cpp Character.cpp Player.cpp Enemy.cpp Game.cpp main.cpp
	g++ -o Driver Collision.cpp Platform.cpp  Bullet.cpp Gun.cpp Character.cpp Player.cpp Enemy.cpp Game.cpp main.cpp -lsfml-graphics -lsfml-system -lsfml-window
run: Driver
	./Driver
