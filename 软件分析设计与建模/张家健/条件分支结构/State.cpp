#include<iostream>
using namespace std;

#define Wait 0
#define Lock 1
#define Open 2
#define Final 3

void State_teller(int state)
{
	switch(state)
	{
    case Wait:
		cout << "Current State is Wait." << endl;
		break;
	case Lock:
		cout << "Current State is Lock." << endl;
		break;
	case Open:
		cout << "Current State is Open." << endl;
		break;
	case Final:
		cout << "Current State is Final." << endl;
		break;
	default:
		break;
	}
}

int main()
{
	int Current_state = 0;
	string capacity;
	int door = 0;
	int candle = 1;
	int loop = 1;

	while (loop)
	{
		switch (Current_state)
		{
		case Wait:
			State_teller(Current_state);
			cout << "You are searching for the lock......" << endl;
			cout << "Please decide whether to close the door !!!" << endl;
			cout << "Enter 1 to close the door, and 0 to let the door open." << endl;
			cin >> door;
			cout << "Enter any character to remove candle ......" << endl;
			cin >> capacity;
			candle = 0;
			if (door)
			{
				cout << "The lock is revealed !" << endl;
				Current_state = Lock;
			}
			break;
		case Lock:
			State_teller(Current_state);
			cout << "Please decide whether to put back the candle !!!" << endl;
			cout << "Enter 1 to put back the candle, and 0 to let the candle out." << endl;
			cin >> candle;
			cout << "You are turning the key ......" << endl;
			if (candle)
			{
				cout << "The lock is open safely !" << endl;
				Current_state = Open;
			}
			else
			{
				cout << "You have released the Killer Rabbit, run now!!!" << endl;
				Current_state = Final;
			}
			break;
		case Open:
			State_teller(Current_state);
			cout << "Enter any character to be safe closed ......" << endl;
			cin >> capacity;
			cout << "safe closed !!!" << endl;
			Current_state = Wait;
			break;
		case Final:
			State_teller(Current_state);
			cout << "Game Over!!!" << endl;
			loop = 0;
			break;
		default:
			break;
		}
	}

	return 0;
}
