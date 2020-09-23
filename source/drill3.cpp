#include "std_lib_facilities.h"

int main ()

{
	string first_name;
	string friend_name;
	string recipient_name;
	char friend_sex = 0;
	int age = 0;
	
	cout << "Enter your first name!\n";
	cin >> first_name;
	cout << "Hello " << first_name << "!\n";
	cout << "Who would you like to write to?\n";
	cin >> recipient_name;
	
	cout << "\tDear " << recipient_name <<",\n" <<
	"How are you? I am fine. I miss you!\n";
	cout << "What is your friends name?\n";
	cin >> friend_name;
	cout << "Have you seen " << friend_name << " lately?\n";
	
	do
	{
		cout << "Is your friend male or female? (m/f)\n";
		cin >> friend_sex;

		if (friend_sex == 'm' || friend_sex == 'M')
		{
			cout << "If you see " << friend_name << " please ask him to call me.\n";
			break;	
		}
		else if (friend_sex == 'f' || friend_sex == 'F')
		{
			cout << "If you see " << friend_name << " please ask her to call me.\n";
			break;
		}
		else
			cout << "Gender wrongly specified!\n";
	}while (friend_sex != 'm' || friend_sex != 'M' || friend_sex != 'f' || friend_sex != 'F');
	
	do
	{
		cout << "How old is the recipient?\n";
		cin >> age;
		if (age <= 0 || age >= 110)
			cout << "You're kidding!\n";
		else
		{
			cout << "I hear you just had a birthday and you are " << age << " years old.\n";
			break;
		}
	}while (age <= 0 || age >= 110);
	
	if (age < 12)
		cout << "Next year you will be " << age+1 << ".\n";
	if (age == 17)
		cout << "Next year you will be able to vote.\n";
	if (age > 70)
		cout << "I hope you are enjoying retirement.\n";
	
	cout << "Yours sincerely,\n\n " << first_name << endl;
	
	return 0;
}

	


