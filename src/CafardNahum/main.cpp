#include "pch.h"
#include "main.h"
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include <random>
#include <stdlib.h>

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    GameManager* game = GameManager::getInstance();
    game->Init();
    game->Run();

    return 0;
}
