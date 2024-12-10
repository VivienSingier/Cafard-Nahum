#include "pch.h"
#include "main.h"
#include <SFML/Graphics.hpp>
#include "GameManager.h"

int main()
{
    GameManager game;
    game.Init();
    game.Run();

    return 0;
}
