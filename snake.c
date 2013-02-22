#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define MAP_X 20
#define MAP_Y 20
#define MAP_EX_WIDTH 2

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_EXIT 101


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
	int key, move;
	int level=3;
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
	
	printf("Snake\n\nUse arrow keys (up, down, left, right) to control.\nPress any key to start.\nPress \"e\" to exit.");

	while (1) {

		key = getche(); //Get key event
		move = 0; //if move
		
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
			
			case KEY_EXIT:
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
	}







	return 0;
}
