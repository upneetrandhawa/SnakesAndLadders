#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>



using namespace std;
int count[100] = {0};

class SnakesAndLadderPlayerData
{
private:
	string playerName;
	bool scoreCard[100] = {false};
	bool canStart = false;
public:
	 //SnakesAndLadder();
//	~ SnakesAndLadder();

    void setPlayerName(string name){
		playerName = name;
	}
	string getPlayerName(){
		return playerName;
	}
	bool  isThere(int position){
		return scoreCard[position];
	}

	void setScoreCard(int position, bool value){
		scoreCard[position] = value;
	}

	/* data */
};


void printBoard();
int randomk();
bool Check();

int main(){
	cout<<"----------------------------SNAKES AND LADDERS----------------------------\n"<<endl;
	int noPlayers;
	cout<<"Enter number of players: ";
	cin >> noPlayers;

	SnakesAndLadderPlayerData *players = new SnakesAndLadderPlayerData[noPlayers];
	for (int i = 0; i<noPlayers; i++){
		string value;
		cout<<"Enter Player"<<i+1<<" name: ";
		cin>>value;
		players[i].setPlayerName(value);
	}

	cout<<"----------------------------LETS START THE GAME----------------------------\n"<<endl;
    
	printBoard();

	while(Check){
		for (int i = 0; i<noPlayers; i++){
			char input;
			cout<<"Player "<< players[i].getPlayerName()<< " press ENTER to roll dice: ";
			cin>>input;
			int diceValue = randomk();

			if (diceValue == 6){
				cout<<"Player "<< players[i].getPlayerName()<< " got "<<diceValue<< " .You can START!"<<endl;
				cout<<"Player "<< players[i].getPlayerName()<< " press ENTER to roll dice AGAIN! ";
				cin>>input;
			    diceValue = randomk();

				if (diceValue == 6){
					cout<<"Player "<< players[i].getPlayerName()<< " got two "<<diceValue<< "\'s in a row  .You can START!"<<endl;
					cout<<"Player "<< players[i].getPlayerName()<< " press ENTER to roll dice AGAIN! ";
					cin>>input;
					diceValue = randomk();

					if (diceValue == 6){
						cout<<"Player "<< players[i].getPlayerName()<< " got three "<<diceValue<< "\'s in a row .You can START!"<<endl;
						cout<<"Player "<< players[i].getPlayerName()<< " This is a fault. Start Over again";
						
						

				
					}

				
				}

			}
		}

	}
	printBoard();
}

void printBoard(){
	for (int i = 10 ; i >0 ; i--){
		if (i%2==0){
			for(int j = 0; j <10 ; j++){
				cout<<i*10-j<< "\t\t";
			}
		}

		else {
			for(int j = 9; j >=0 ; j--){
				cout<<i*10-j<< "\t\t";
			}
		}
		cout<<"\n\n";
	}
}

int randomk (){
	srand(time(0));
    return (rand() % 6 + 1);
}

bool Check(){
	//if someone at 100 return false
	
}