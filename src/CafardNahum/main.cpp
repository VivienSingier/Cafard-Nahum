#include "pch.h"
#include "main.h"
#include <SFML/Graphics.hpp>
#include "GameManager.h"

int main()
{
    GameManager* game = GameManager::getInstance();
    game->Init();
    game->Run();

    return 0;
}
