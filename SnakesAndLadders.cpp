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
	
	int currPositon = 0;
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
	int  getPosition(){
		return currPositon;
	}

	void setPosition(int position){
		currPositon= position;
	}
	bool getCanStart(){
		return canStart;
	}
	void setCanStart(bool value){
		canStart = value;
	}

	/* data */
};


void printBoard();
int randomk();
void resetOverlappedPlayers(SnakesAndLadderPlayerData *players, int currPlayer, int currPlayerPosition, int noPlayers);
bool Check(SnakesAndLadderPlayerData *players, int noPlayers);

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

	while(Check(players, noPlayers)){
		for (int i = 0; i<noPlayers; i++){
			char input;
			cout<<"Player "<< players[i].getPlayerName()<< " press ENTER to roll dice: ";
			cin>>input;
			int diceValue = randomk();

			if (diceValue == 6 && !players[i].getCanStart()){
				players[i].setCanStart(true);
				cout<<"Player "<< players[i].getPlayerName()<< " got "<<diceValue<< " .You can START!"<<endl;
				cout<<"Player "<< players[i].getPlayerName()<< " press ENTER to roll dice AGAIN! ";
				cin>>input;
			    int diceValue2 = randomk();

				if (diceValue2 == 6){
					cout<<"Player "<< players[i].getPlayerName()<< " got two "<<diceValue2<< "\'s in a row."<<endl;
					cout<<"Player "<< players[i].getPlayerName()<< " press ENTER to roll dice AGAIN! ";
					cin>>input;
					int diceValue3 = randomk();

					if (diceValue3 == 6){
						cout<<"Player "<< players[i].getPlayerName()<< " got three "<<diceValue3<< "\'s in a row."<<endl;
						cout<<"Player "<< players[i].getPlayerName()<< " This is a fault. Start Over again. Need 6 again";
						players[i].setCanStart(false);
						players[i].setPosition(0);
					
					}
					else {
					    cout<<"Player "<< players[i].getPlayerName()<< " got "<<diceValue3<<endl;
					    players[i].setPosition(players[i].getPosition()+diceValue+diceValue2+diceValue3);
					}

				
				}
				else{
					cout<<"Player "<< players[i].getPlayerName()<< " got "<<diceValue2<<endl;
					    players[i].setPosition(players[i].getPosition()+diceValue+diceValue2);
				}


			}

			else if (diceValue == 6 && players[i].getCanStart()){
				cout<<"Player "<< players[i].getPlayerName()<< " got "<<diceValue<<endl;
				cout<<"Player "<< players[i].getPlayerName()<< " press ENTER to roll dice AGAIN! ";
				cin>>input;
			    int diceValue2 = randomk();

				if (diceValue2 == 6){
					cout<<"Player "<< players[i].getPlayerName()<< " got two "<<diceValue2<< "\'s in a row."<<endl;
					cout<<"Player "<< players[i].getPlayerName()<< " press ENTER to roll dice AGAIN! ";
					cin>>input;
					int diceValue3 = randomk();

					if (diceValue3 == 6){
						cout<<"Player "<< players[i].getPlayerName()<< " got three "<<diceValue3<< "\'s in a row."<<endl;
						cout<<"Player "<< players[i].getPlayerName()<< " This is a fault. Start Over again";
						players[i].setPosition(0);
					}

					else {
					    cout<<"Player "<< players[i].getPlayerName()<< " got "<<diceValue3<<endl;
					    players[i].setPosition(players[i].getPosition()+diceValue+diceValue2+diceValue3);
					}
				}

				else{
					cout<<"Player "<< players[i].getPlayerName()<< " got "<<diceValue2<<endl;
					    players[i].setPosition(players[i].getPosition()+diceValue+diceValue2);
				}

			}

			else if (diceValue!=6 && players[i].getCanStart()) {
				cout<<"Player "<< players[i].getPlayerName()<< " got "<<diceValue<<endl;
				players[i].setPosition(players[i].getPosition()+diceValue);
			}
			cout<<"Player "<< players[i].getPlayerName()<< " at Position "<<players[i].getPosition()<<endl;
			cout<<"\n"<<endl;
			resetOverlappedPlayers(players,i,players[i].getPosition(),noPlayers);
		}

	

	//printBoard();
}
	return 0;
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

bool Check(SnakesAndLadderPlayerData *players, int noPlayers){
	//if someone at 100 return false
for (int i = 0; i<noPlayers; i++){
		if(players[i].getPosition()>=100){
			cout<<"\n\n\n----------------Player "<<players[i].getPlayerName()<<" won----------------"<<endl;
         return false;
		}
	}
return true;
	
}

void resetOverlappedPlayers(SnakesAndLadderPlayerData *players, int currPlayer, int currPlayerPosition int noPlayers){
	for (int i = 0 ; i < noPlayers; i++){
		if(players[i].getPosition()==currPlayerPosition && i!=currPlayer){
			cout<<"Player "<<players[currPlayer].getPlayerName()<<" overlapped "<<players[i].getPlayerName()<<" therefore "
				<<players[i].getPlayerName()<<" will restart"<<endl;
			players[i].players[i].setPosition(0);
		}
	}
}
