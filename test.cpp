#include <iostream>
#include <string>
using namespace std;

const static int ROWS = 6;
const static int COLS = 10;
string seats[ROWS][COLS];
const static int num_seats = 5;

void randomSeats(){
	srand(time(0));
	for(int i = 0; i < num_seats; i++){		
		int t1 = rand() % ROWS + 1;
		int t2 = rand() % COLS + 1;
        cout<<t1<<" "<<t2;
		
		seats[t1][t2] = "■";
	}
}

int main(){
    randomSeats();
}