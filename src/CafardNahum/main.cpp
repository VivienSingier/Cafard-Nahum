#include "pch.h"
#include "main.h"
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include <random>

int main()
{
    srand(time(NULL));

    GameManager* game = GameManager::getInstance();
    game->Init();
    game->Run();

    return 0;
}
