#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Game {
	public:
		int board[5][5]={0};

		Game() {
			cout<<"\n\nMAYIN TARLASI OYUNU\n\n";
		}

		~Game() {
			cout<<"\n\nOYUN SONA ERDI\n\n";
		}

		void pointBoard() {
			for(int i=0;i<5;i++) {
				board[i][rand()%4+0] = 1;
			}
		}

		void printBoard() {
			for(int i=0;i<5;i++) {
				for(int j=0;j<5;j++) {
					if(board[i][j]==1)
						cout<<"\e[91m"<<board[i][j]<<" \e[91m| ";
					else if(board[i][j]==0)
						cout<<"\e[92m"<<board[i][j]<<" \e[92m| ";
					else
						cout<<"\e[97m"<<board[i][j]<<" \e[97m| ";
				}
				cout<<"\n\n";
			}
		}

		void game() {
			int number;
			int sayac=0;
			pointBoard();
			while(sayac<5) {
				cout<<"\n1 ile 5 arasinda sayi gir: ";
				cin>>number;
				if(board[sayac][number-1]==1) {
					cout<<"\nMayina denk geldin.\n";
					printBoard();
					exit(1);
				}
				else {
					board[sayac][number-1] = 3;
				}
				sayac++;
			}
		        cout<<"\n\tTEBRIKLER.\n";
                        printBoard();

		}
};

int main(int argc, char *argv[]) {
	srand(time(NULL));
	Game g;
	g.game();
}
