// ConsoleApplication11.cpp : Defines the entry point for the console application.
//
#include "main.h"

void shop() {
	bool exit = true;
	while (exit) {
		cout << "\n Here you may upgrade your: \n Strength (1) for " << StrPrice <<" gold \n Defence (2), for " << DefPrice << " gold \n current HP (3), for " << HPPrice << " gold \n Luck (4), for " << LuckPrice << " gold \n You may leave pressing anything else. \n";
		cout << "\n Your current amount of gold : " << Gold ;
		cout << "\n \n Your Strength " << PlayerStr << " Your Defence " << PlayerDef << " Your HP " << PlayerHP << " Your LUCK " << PlayerLuck;
		cout << "\n";
		cin >> ShopChoice;
		switch (ShopChoice) {
		case '1':	if (Gold < StrPrice) {
				cout << " Not enough money \n \n";
			}
			else {
				Gold = Gold - StrPrice;
				PlayerStr += 5;
				StrPrice+= 5;
			}
			break;
		case '2': if (Gold < DefPrice) {
			cout << " Not enough money \n \n";
		}
				else {
					Gold = Gold - DefPrice;
					PlayerDef += 5;
					DefPrice += 5;
				} break;
		case '3': if (Gold < HPPrice) {
			cout << " Not enough money \n \n";
		}
				else {
					Gold = Gold - HPPrice;
					PlayerHP += 10;
				} break;
		case '4': if (Gold < LuckPrice) {
			cout << " Not enough money \n \n";
		}
				else {
					Gold = Gold - LuckPrice;
					PlayerLuck += 5;
					LuckPrice += 5;
				} break;
		default: exit = false;
		}
}
}
void StartGame() { cout << "1";}
void Combat() {
	MonsterHP = 30;
	exit3 = true;
	do {
		if (PlayerHP <= 0) {
			cout << "You lose \n";
      cout << "You've been ressurected at the crossroads for 50 gold";
    	PlayerHP = 100;
			Gold = Gold - 50;
			if (Gold < 0) {
				Gold = 0;
			}
			else {}
      goto Won;
		}
		else {}
		if (MonsterHP <= 0) {
			goto Won;

		}
		else {}

		cout << "\n Press 1 to attack, or 2 to run  away.\n ";
		cout << "\n Your hp: " << PlayerHP << "\n Monster's HP: " << MonsterHP << "\n";
		cin >> CombatChoice;
		switch (CombatChoice) {
		case 1: if (PlayerLuck >= rand() % 100 + 1)
		{
			if (PlayerDef > MonsterATK) {
				PlayerHP = PlayerHP - 1;
				cout << "Monster attacked you but barely dealt damage";
			}
			else {
				cout << "\n Monster atacked you for " << MonsterATK - PlayerDef << "\n";
				PlayerHP = PlayerHP - (MonsterATK - PlayerDef);
			}
			cout << "\n You atacked monster for " << 2 * PlayerStr - MonsterDef << "\n";
			MonsterHP = MonsterHP - (2 * PlayerStr - MonsterDef);
		}
				else {
					if (PlayerDef > MonsterATK) {
						PlayerHP = PlayerHP - 1;
						cout << "Monster attacked you but barely dealt damage";
					}
					else {
						cout << "\n Monster atacked you for " << MonsterATK - PlayerDef << "\n";
						PlayerHP = PlayerHP - (MonsterATK - PlayerDef);
					}
					cout << "\n You atacked the monster for " << PlayerStr - MonsterDef << " damage \n";
					MonsterHP = MonsterHP - (PlayerStr - MonsterDef);
				}
				break;
				case 2:exit3 = false;
			break;

				default: cout << "\n Invalid command";
		}
	} while ((exit3 == true) && (MonsterHP > 0));

	Won:if ((PlayerHP>0) && (MonsterHP<=0)){
		cout << "\n Congratulations on defeating the monster!\n";
		GoldGain = (rand() % 6 + 10);
		cout << "\n You gain: " << GoldGain << " gold \n \n";
		Gold += GoldGain;
	}
	else if ((PlayerHP<=0)&&(MonsterHP<=0)){
    std::cout << "You both died" << '\n';
  }
  else if ((PlayerHP>0)&&(MonsterHP>0))
	{		cout << "\n You ran away \n";
}
else {}
}


void Menu() {
	while (exit2) {
		cout << "\n Press 1 to begin your dungeon run. \n Press 2 instead to check the shop. \n You may press anything else to exit the program.\n";
		cin >> MenuChoice;
		switch (MenuChoice) {
		case 1: Combat();
			break;
		case 2: shop();
			break;
		default: exit2 = false;
		}
	}
}
int main()
{
	Gold = 20;
  Menu();
	return 0;
}
