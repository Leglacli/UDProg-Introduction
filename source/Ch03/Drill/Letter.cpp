#include "std_lib_facilities.h"

void makeLetter();
string askName();
void askRecipient();
string askFriendName();
void askGender(string fname);
void askRecipientAge();

int main()
{
	makeLetter();
	return 0;
}


void makeLetter()
{
	//Asking for name.
	string first_name = askName();

	//Asking for a recipient.
	askRecipient();

	//Asking for friends name.
	string friend_name = askFriendName();

	//Asking for friend's gender.
	askGender(friend_name);
	
	//Asking for recipient's age.
	askRecipientAge();

	cout << "Yours sincerely,\n\n " << first_name << endl;
}

string askName()
{
	string first_name;
	cout << "Enter your first name!\n";
	cin >> first_name;
	cout << "Hello " << first_name << "!\n";
	return first_name;
}

void askRecipient()
{
	string recipient_name;
	cout << "Who would you like to write to?\n";
	cin >> recipient_name;
	cout << "\tDear " << recipient_name << ",\n" << "How are you? I am fine. I miss you!\n";
}

string askFriendName()
{
	string friend_name;
	cout << "What is your friends name?\n";
	cin >> friend_name;
	cout << "Have you seen " << friend_name << " lately?\n";
	return friend_name;
}

void askGender(string fname)
{
	char friend_sex = 0;
	//Loop to make sure we get the correct information.
	do
	{
		cout << "Is your friend male or female? (m/f)\n";
		cin >> friend_sex;

		if (friend_sex == 'm' || friend_sex == 'M')
		{
			cout << "If you see " << fname << " please ask him to call me.\n";
			break;
		}
		else if (friend_sex == 'f' || friend_sex == 'F')
		{
			cout << "If you see " << fname << " please ask her to call me.\n";
			break;
		}
		else
			cout << "Gender wrongly specified!\n"; //Incorrect gender.

	} while (friend_sex != 'm' || friend_sex != 'M' || friend_sex != 'f' || friend_sex != 'F');

}

void askRecipientAge()
{
	int age;
	do
	{
		cout << "How old is the recipient?\n";
		cin >> age;
		if (age <= 0 || age >= 110)
			cout << "You're kidding!\n"; //Incorrect age.
		else
		{
			cout << "I hear you just had a birthday and you are " << age << " years old.\n";
			break;
		}
	} while (age <= 0 || age >= 110);

	//Different output for each age range.
	if (age < 12)
		cout << "Next year you will be " << age + 1 << ".\n";
	if (age == 17)
		cout << "Next year you will be able to vote.\n";
	if (age > 70)
		cout << "I hope you are enjoying retirement.\n";
}
