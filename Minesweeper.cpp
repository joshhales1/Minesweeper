#include <iostream>
#include <string>

int MINE = 1;
int EXPOSED = 2;
int FLAG = 4;

int rndint() {
    return rand() % 10;
}

void circle(char(*map)[10][10], int w, int z) {
    
    for (int x = (w < 1 ? 0 : -1); x < (w > 8 ? 0 : 2); x++) {
        for (int y = (z < 1 ? 0 : -1); y < (z > 8 ? 0 : 2); y++) { //|| Line below? TODO
            if (x + w, y + z) continue;
            
        }
    }

}

void render(char (*map)[10][10]) {
    system("cls");
    for (int x = 0; x < 10; x++) {

        //TODO: Make columsna and rows work

        for (int y = 0; y < 10; y++) {
            /*if (map[x][y] & MINE)
                std::cout << "x ";
            else*/ if ((*map)[x][y] & FLAG)
                std::cout << "f ";
            else if ((*map)[x][y] & EXPOSED)
                std::cout << ((int)((*map)[x][y]) >> 3) << " ";
            else
                std::cout << "@ ";
        }
        std::cout << "\n";
    }
}
int main()
{
    srand(time(0));

    char map[10][10];
    memset(map, 0, sizeof(map));

    for (int i = 0; i < 5; i++) {
        int w = rndint();
        int z = rndint();
        if (map[w][z] & MINE) {
            i--;
            continue;
        }

        map[w][z] = MINE;

        for (int x = (w < 1 ? 0 : -1); x < (w > 8 ? 0 : 2); x++) {
            for (int y = (z < 1 ? 0 : -1); y < (z > 8 ? 0 : 2); y++) { //|| Line below? TODO
                if (x == 0 && y == 0) continue;
                map[x + w][y + z] = map[x + w][y + z] + 8;                
            }
        }
    }

    render(&map);

    while (1) {
        std::string input;
        std::getline(std::cin, input);

        std::string first = input.substr(0, 1);

        if (input.substr(0, 1) == "r") {
            int x = stoi(input.substr(1, 1));
            int y = stoi(input.substr(2, 1));

            if (map[x][y] & EXPOSED)
                continue;

            if (map[x][y] & MINE) {
                std::cout << "GAME OVER!";
                break;
            }

            if (map[x][y] >> 3 == 0) {
                // reveal circle
            }
            else {
                map[x][y] = map[x][y] + EXPOSED;
            }                
        }
        char(*p)[10][10] = &map;
        render(p);
    }
    return 0;
}

