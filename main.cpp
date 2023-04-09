/* A Tic-tac-toe Game (:
   Licensed to: GNU GENERAL PUBLIC LICENSE v3
*/
#include <iostream>
#include <string>
#include <cstdlib>
#pragma comment(lib, "winmm.lib")
#include <windows.h>

using namespace std;



// Global
string name1, name2;
char table[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int nobat = 0;
int scoreN1 = 0;
int scoreN2 = 0;

// What the functions do is clear from their names (:
void getPlayerName () {
    cout << "Player1!, enter your name: ";
    getline(cin,name1);
    cout << endl << "Player2!, enter your name: ";
    getline(cin,name2);
}

void printTable () {
    system("cls");
    cout << endl << endl << endl;
    cout << "                               Player 1: " << name1 << "  &&&  " << "Player 2: " << name2 << endl;
    cout << "                               ._._._._._._._._._._._._._._._._._._._." << endl;
    cout << "                               [            |           |            ]" << endl;
    cout << "                               ]      " << table[0] << "     |     " << table[1] << "     |     " << table[2] << "      ["
         << endl;
    cout << "                               [            |           |            ]" << endl;
    cout << "                               ]    -----------------------------    [" << endl;
    cout << "                               [            |           |            ]" << endl;
    cout << "                               ]      " << table[3] << "     |     " << table[4] << "     |     " << table[5] << "      ["
         << endl;
    cout << "                               [            |           |            ]" << endl;
    cout << "                               ]    -----------------------------    [" << endl;
    cout << "                               [            |           |            ]" << endl;
    cout << "                               ]      " << table[6] << "     |     " << table[7] << "     |     " << table[8] << "      ["
         << endl;
    cout << "                               [            |           |            ]" << endl;
    cout << "                               ._._._._._._._._._._._._._._._._._._._." << endl;
}

char getCharNobat () {
    if (nobat % 2 == 0) {
        return 'X';
    } else {
        return 'O';
    }
}

string getNameNobat () {
    if (nobat % 2 == 0) {
        return name1;
    } else {
        return name2;
    }
}

bool isFull () {
    int count = 0;
    for (int i=0; i<9; i++) {
        if (table[i]=='X' || table[i]=='O') {
            count ++;
        }
    }

    if (count == 9) {
        return true;
    } else {
        return false;
    }
}

void getUserInput () {
    cout << "                                   Enter 1-9  " << getNameNobat () << "  ------>>>  " << getCharNobat () << " : ";

    char input;
    cin >> input;
    Beep(600,300);
    
	while(isFull(input)){
		printTable();
		cout<<"                  warning table is not available"<<endl;
		cout<<"                  Enter 1-9 player( "<<getNameNobat()<<" -> "<<getCharNobat()<<" ): ";

		cin>>input;
	}
	
	switch(input){
		case '1':
			table[0]=getCharNobat();
			break;
		case '2':
			table[1]=getCharNobat();
			break;
		case '3':
			table[2]=getCharNobat();
			break;
		case '4':
			table[3]=getCharNobat();
			break;
		case '5':
			table[4]=getCharNobat();
			break;
		case '6':
			table[5]=getCharNobat();
			break;
		case '7':
			table[6]=getCharNobat();
			break;		
		case '8':
			table[7]=getCharNobat();
			break;
		case '9':
			table[8]=getCharNobat();
			break;
		default:
			cout<<"                  Error just 1-9 doctor!"<<endl;
			sleep(2);
			break;
	}
}


bool isWin () {
    if (table[0]==table[1] && table[1]==table[2]) {
        return true;
    } else if (table[3]==table[4] && table[4]==table[5]) {
        return true;
    } else if (table[6]==table[7] && table[7]==table[8]) {
        return true;
    } else if (table[0]==table[3] && table[3]==table[6]) {
        return true;
    } else if (table[1]==table[4] && table[4]==table[7]) {
        return true;
    } else if (table[2]==table[5] && table[5]==table[8]) {
        return true;
    } else if (table[0]==table[4] && table[4]==table[8]) {
        return true;
    } else if (table[2]==table[4] && table[4]==table[6]) {
        return true;
    } else {
        return false;
    }

}


bool isEnd () {
    if (isWin() || isFull()) {
        return false;
    } else {
        return true;
    }
}


string whoIsWinner () {
	if(isFull()){
		return "                            YEAAAAAH player "+ name1 + " and "+ name2 +" are the winners! ";
	}else{
		return "                            YEAAAAAH player "+ getNameNobat()+" is the winner! ";
		if (getNameNobat() == name1) {
			scoreN1++;
		} else {
			scoreN2++;
		}
	}
}

void playerScore () {
	cout << "                    " << name1 << ":" << scoreN1 << "                    " << name2 << ":" << scoreN2;
}

void playSound () {
	PlaySound(TEXT("Martin Vide - Make It Bounce.wav"), NULL, SND_ASYNC);
}




int main (){
    Beep(500, 300);
    Beep(600, 350);
    Beep(400, 350);
    Beep(300, 350);
	Beep(500, 300);
    Beep(600, 350);

	system("color 4");
    
	getPlayerName();
	playerScore;
    printTable();
	
	playSound();
	
	while (isEnd()) {
    	system("color E5");
        printTable();
        getUserInput();
    }
    
    printTable();
    cout << whoIsWinner();
    Beep(600, 350);
    Beep(500, 300);
    Beep(600, 350);
    Beep(400, 350);
    Beep(300, 350);
	Beep(500, 300);
}