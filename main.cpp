#include <iostream>
#include <vector>

#include "player.h"
#include "room.h"
#include "inventory.h"
#include "itemType.h"
#include "itemStack.h"
#include "constantProperty.h"
#include "dinamicProperty/dinamicProperty.h"
#include "condition.h"

using namespace std;

class Game {
private:
    Player player;
    vector<Room> rooms;

public:
    Game() : player("Player", "Главный герой", nullptr) {
        // Инициализируем первую тестовую комнату
        rooms.push_back(Room("Тестовая комната", "Это простая тестовая комната."));
        player.setPosition(&rooms[0]);
    }

    void run() {
        cout << "Текущая комната: " << player.getPosition()->getName() << endl;
        cout << "Описание: " << player.getPosition()->getDescription() << endl;
    }
};

int main() {
    Game game;
    game.run();
    return 0;
}
