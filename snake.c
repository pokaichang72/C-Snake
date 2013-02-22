#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define MAP_X 20
#define MAP_Y 20
#define MAP_EX_WIDTH 2

#define KEY_UP 1
#define KEY_DOWN 2
#define KEY_LEFT 3
#define KEY_RIGHT 4
#define KEY_QUIT 0


int print_map(int map[MAP_X][MAP_Y]) {
	int map_size = (MAP_X * MAP_Y) * MAP_EX_WIDTH + MAP_Y + 1;
	char print[map_size];
	int i, i2, i3, p;

	for (i=0; i<MAP_Y; i++) {
		for (i2=0; i2<MAP_X; i2++) {
			p = (i * MAP_X + i2) * MAP_EX_WIDTH + i;
			if (map[i][i2] == 0) {
				for (i3=0; i3<MAP_EX_WIDTH; i3++) print[p+i3] = '8';
			} else if (0 < map[i][i2]) {
				for (i3=0; i3<MAP_EX_WIDTH; i3++) print[p+i3] = ' ';
			} else {
				for (i3=0; i3<MAP_EX_WIDTH; i3++) print[p+i3] = '.';
			}
			
		}
		print[p+MAP_EX_WIDTH] = '\n';
	}
	print[p+MAP_EX_WIDTH+1] = '\0';
	
	puts(print);
}


int main() {
	int i, i2, i3;
	int key=KEY_RIGHT, move;
	int level=3, life=2;
	int map[MAP_Y][MAP_X] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		1, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};
	int head_x=2, head_y=1, rand_x, rand_y;
	srand(time(NULL));
	
	printf("Snake\n\nUse arrow keys (up, down, left, right) to control.\n\nPress \"e\" to exit.\n");
	system("PAUSE");
	while (1) {
		move = 0; //if move
		
		for(i=0; i<130-(level*3); i++) {
			Sleep(1);
			if(GetKeyState(VK_UP) & 0x80 && map[head_y-1][head_x] < 1) key = KEY_UP;
			if(GetKeyState(VK_DOWN) & 0x80 && map[head_y+1][head_x] < 1) key = KEY_DOWN;
			if(GetKeyState(VK_RIGHT) & 0x80 && map[head_y][head_x+1] < 1) key = KEY_RIGHT;
			if(GetKeyState(VK_LEFT) & 0x80 && map[head_y][head_x-1] < 1) key = KEY_LEFT;
			if(GetKeyState(0x51) & 0x80) key = KEY_QUIT;
		}

		switch (key) { //Set reactions for key event
			case KEY_UP:
				if (head_y > 0 && map[head_y-1][head_x] < 1) {
					head_y--;
					move = 1;
				}
			break;
			
			case KEY_DOWN:
				if (head_y < MAP_Y-1 && map[head_y+1][head_x] < 1) {
					head_y++;
					move = 1;
				}
			break;
			
			case KEY_LEFT:
				if (head_x > 0 && map[head_y][head_x-1] < 1) {
					head_x--;
					move = 1;
				}
			break;
			
			case KEY_RIGHT:
				if (head_x < MAP_X-1 && map[head_y][head_x+1] < 1) {
					head_x++;
					move = 1;
				}
			break;
			
			case KEY_QUIT:
				return 0;
			break;
		}
		
		if (move) {
			if (map[head_y][head_x] == -1) { //Get Food!
				level++;
				for (i=0; i<MAP_X; i++) {
					for (i2=0; i2<MAP_Y; i2++) {
						if (map[i2][i] > 0) map[i2][i]++;
					}
				}
				while (1) { //Generate new Food
					rand_x = (rand() % MAP_X);
					rand_y = (rand() % MAP_Y);
					if (map[rand_y][rand_x] == 0) {
						map[rand_y][rand_x] = -1;
						break;
					}
				}
			}
			
			for (i=0; i<MAP_X; i++) { //Update map
				for (i2=0; i2<MAP_Y; i2++) {
					if (map[i2][i] > 0) map[i2][i]--;
				}
			}
			
			map[head_y][head_x] = level;
		}
		
		
		system("cls");

		print_map(map);
		printf("Score: %d\n", level-3); //Print Score
		
		if (move == 0) life--;
		else life = 2;
		
		if (life == 0) {
			printf("\nYou are dead.\a\n");
			system("color 04");
			break;
		}
	}
	
	system("PAUSE");
	return 0;
}
