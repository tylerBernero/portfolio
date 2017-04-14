SRC = B1Room.cpp
SRC += B2Room.cpp
SRC += BombRoom.cpp
SRC += BossRoom.cpp
SRC += Dungeon.cpp
SRC += EntranceRoom.cpp
SRC += Game.cpp
SRC += main.cpp
SRC += SkulltulaRoom.cpp
SRC += IntInputValid.cpp

default: $(SRC)
	g++ -std=c++11  $(SRC) -o main

clean:
	rm main