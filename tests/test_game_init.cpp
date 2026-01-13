#include "../src/game/Game.h"
#include <iostream>
#include <cassert>

void testGameInitialization() {
    Game game;
    const Game::Grid& grid = game.getGrid();
    
    int emptyCount = 0;
    int value2Count = 0;
    int value4Count = 0;
    
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            int value = grid[row][col];
            if (value == 0) {
                emptyCount++;
            } else if (value == 2) {
                value2Count++;
            } else if (value == 4) {
                value4Count++;
            } else {
                std::cerr << "ERREUR: Valeur inattendue: " << value << " à (" << row << "," << col << ")\n";
                assert(false);
            }
        }
    }
    
    std::cout << "  Cases vides (0): " << emptyCount << "\n";
    std::cout << "  Tuiles avec valeur 2: " << value2Count << "\n";
    std::cout << "  Tuiles avec valeur 4: " << value4Count << "\n";
    
    assert(emptyCount == 14);
    assert((value2Count + value4Count == 2));
    assert((value2Count + value4Count == 2));
    
    std::cout << " Test réussi!\n\n";
}

int main() {
    std::cout << "=== Test d'intégration: Initialisation du jeu ===\n\n";
    std::cout << "Vérifie qu'il y a bien 2 tuiles aléatoires (2 ou 4) générées\n\n";
    
    testGameInitialization();
    
    std::cout << "=== Test réussi! ===\n";
    return 0;
}
