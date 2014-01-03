//#include <iostream>
//#include <math.h>
//#include <string>
//#include <time.h>
//#include <sstream>
//#include <cstdlib>
//using namespace std;
//
//
//void encrypt();
//void decrypt();
//
//
//int main()
//{
//	int choice;
//	cout << "Select an option: " << endl;
//	cout << "(1) Encrypt " << endl;
//	cout << "(2) Decrypt " << endl;
//	cin >> choice;
//
//	switch (choice)
//	{
//	case 1:
//		encrypt();
//		break;
//	case 2:
//		decrypt();
//		break;
//
//	}
//	system("PAUSE");
//	return 0;
//}
//
//
//void encrypt()
//{
//	srand(time(NULL));
//	int random = rand() % 1000 + 200;
//	srand(time(NULL));
//	int random_2 = rand() % 1000 + 200;
//	
//	int to_encrypt;
//	int shares;
//	cout << "Enter a number: ";
//	cin >> to_encrypt;
//	cout << "Shares to create: " << endl;
//	cin >> shares;
//
//	cout << "Encryption keys: " << endl;
//	for (int i = 1; i <=shares; i++)
//	{
//		cout << i << ": ";
//		cout << i;
//		cout << to_encrypt + i * random + pow(i, 2)*random_2;
//		cout << endl;
//	}
//
//
//}
//
//
//void decrypt()
//{
//	const int size = 3;
//	int keys[size];
//	string x;
//	string x_1;
//	string x_2;
//	string to_decrypt[size];
//
//
//	long long first_term[size];
//	long long second_term[size];
//	long long third_term[size];
//
//	long long x_;
//	long long x__;
//	long long x___;
//	long long number;
//
//	long long mult;
//	long long mult1;
//	long long mult2;
//	 
//	cout << "Enter the keys. " << endl;
//	for (int i = 0; i < size; i++)
//	{
//		cin >> keys[i];
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		number = keys[i];
//		cout << "L(" << i << "): ";
//		to_decrypt[i] = to_string(number);
//
//	}
//
//	x = to_decrypt[0][0];      //x holds first digit
//	x_1 = to_decrypt[1][0];
//	x_2 = to_decrypt[2][0];
//
//	istringstream buffer(x);
//	buffer >> x_;
//
//	istringstream buffer1(x_1);
//	buffer1 >> x__;
//
//	istringstream buffer2(x_2);
//	buffer2 >> x___;
//
//
//	first_term[0] = 1 / ((x_ - x__) * (x_ - x___));
//	second_term[0] = ((-x__) + (-x___)) * first_term[0];
//	third_term[0] = ((x__ * x___)) * first_term[0];
//
//	cout << first_term[0] << endl;
//	cout << second_term[0] << endl;
//	cout << third_term[0] << endl;
//	
//
//	first_term[1] = 1 / ((x__ - x_)*(x__ - x___));
//	second_term[1] = ((-x_) + (-x___)) * first_term[1];
//	third_term[1] = (x_ * x___) * first_term[1];
//
//	cout << first_term[1] << endl;
//	cout << second_term[1] << endl;
//	cout << third_term[1] << endl;
//	
//	first_term[2] = 1 / ((x___ - x_)*(x___ - x__));
//	second_term[2] = ((-x_) + (-x__)) * first_term[2];
//	third_term[2] = (x_ * x__) * first_term[2];
//
//	cout << first_term[2] << endl;
//	cout << second_term[2] << endl;
//	cout << third_term[2] << endl;
//	
//	to_decrypt[0] =  to_decrypt[0].substr(1,to_decrypt[0].length() - 1);
//	to_decrypt[1] = to_decrypt[1].substr(1, to_decrypt[1].length() - 1);
//	to_decrypt[2] = to_decrypt[2].substr(1, to_decrypt[1].length() - 1);
//
//	istringstream multi(to_decrypt[0]);
//	multi >> x_;
//
//	istringstream multi1(to_decrypt[1]);
//	multi1 >> x__;
//
//	istringstream multi2(to_decrypt[2]);
//	multi2 >> x___;
//
//	long long sum = third_term[0] * x_ + third_term[1] * x__ + third_term[2] * x___;
//
//	cout << sum << endl;
//
//
//
//}
//
//
//
//
//













#include <iostream>
#include <math.h>
#include <string>
#include <time.h>
#include <sstream>
#include <cstdlib>
#include "BigInteger.hh"
#include "BigIntegerLibrary.hh"
using namespace std;


void encrypt();
void decrypt();
long long convertToASCII(string);


string sum;
bool zero = false;

int main()
{
	int choice;
	cout << "Select an option: " << endl;
	cout << "(1) Encrypt " << endl;
	cout << "(2) Decrypt " << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		encrypt();
		break;
	case 2:
		decrypt();
		break;

	}
	system("PAUSE");
	return 0;
}


long long convertToASCII(string letter)
{
	long engie;
	for (int i = 0; i < letter.length(); i++)
	{
		char x = letter.at(i);
		//cout << int(x) << endl;
		if (int(x) < 100)
		{
			zero = true;
			sum = sum + '0' + to_string(int(x));
		}
		else
		sum += to_string(int(x));;
	}

	cout << sum << endl;
	istringstream buffstring(sum);
	buffstring >> engie;

	return engie;
}

void encrypt()
{
	srand(time(NULL));
	long long random = rand() % 1000 + 200;
	srand(time(NULL));
	long long random_2 = rand() % 1000 + 200;

	string to_encrypt__;
	long long to_encrypt;
	long shares;
	cout << "Enter a number: ";
	cin.ignore();
	getline(cin,to_encrypt__);
	cout << "Shares to create: " << endl;
	cin >> shares;
	
	//BigInteger(shares)
	to_encrypt = convertToASCII(to_encrypt__);


	cout << to_encrypt << endl;


	cout << "Encryption keys: " << endl;
	for (long long i = 1; i <= shares; i++)
	{
		cout << i << ": ";
		if (zero == true)
			cout << "0";
		cout << i;
		cout << to_encrypt + i * random + (i*i *random_2);
		cout << endl;
	}


}


void decrypt()
{
	const int size = 3;
	string keys[size];
	string x;
	string x_1;
	string x_2;
	string to_decrypt[size];


	long double first_term[size];
	long double second_term[size];
	long double third_term[size];

	long double x_;
	long double x__;
	long double x___;
	long double number;

	long double mult;
	long double mult1;
	long double mult2;

	cout << "Enter the keys. " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> keys[i];
	}

	for (int i = 0; i < size; i++)
	{
		string place = keys[i];
		long double num;
		if (place[0] == '0')
		{
			place = place.substr(1, place.length() - 1);
			zero = true;
		}

		istringstream lol(place);
		lol >> num;

		number = num;
		cout << "L(" << i << "): ";
		to_decrypt[i] = to_string(number);

	}

	x = to_decrypt[0][0];      //x holds first digit
	x_1 = to_decrypt[1][0];
	x_2 = to_decrypt[2][0];

	istringstream buffer(x);
	buffer >> x_;

	istringstream buffer1(x_1);
	buffer1 >> x__;

	istringstream buffer2(x_2);
	buffer2 >> x___;


	first_term[0] = 1 / ((x_ - x__) * (x_ - x___));
	second_term[0] = ((-x__) + (-x___)) * first_term[0];
	third_term[0] = ((x__ * x___)) * first_term[0];

	cout << first_term[0] << endl;
	cout << second_term[0] << endl;
	cout << third_term[0] << endl;


	first_term[1] = 1 / ((x__ - x_)*(x__ - x___));
	second_term[1] = ((-x_) + (-x___)) * first_term[1];
	third_term[1] = (x_ * x___) * first_term[1];

	cout << first_term[1] << endl;
	cout << second_term[1] << endl;
	cout << third_term[1] << endl;

	first_term[2] = 1 / ((x___ - x_)*(x___ - x__));
	second_term[2] = ((-x_) + (-x__)) * first_term[2];
	third_term[2] = (x_ * x__) * first_term[2];

	cout << first_term[2] << endl;
	cout << second_term[2] << endl;
	cout << third_term[2] << endl;

	to_decrypt[0] = to_decrypt[0].substr(1, to_decrypt[0].length() - 1);
	to_decrypt[1] = to_decrypt[1].substr(1, to_decrypt[1].length() - 1);
	to_decrypt[2] = to_decrypt[2].substr(1, to_decrypt[1].length() - 1);

	istringstream multi(to_decrypt[0]);
	multi >> x_;

	istringstream multi1(to_decrypt[1]);
	multi1 >> x__;

	istringstream multi2(to_decrypt[2]);
	multi2 >> x___;

	long double sum = third_term[0] * x_ + third_term[1] * x__ + third_term[2] * x___;

	cout << sum << endl;

	string sum_string;

	if (zero == true)
	{
		sum_string = '0' + to_string(sum) ;
		cout << sum_string << endl;
	}

	size_t dotIndex = sum_string.find(".");
	sum_string = sum_string.substr(0, dotIndex);

	cout << sum_string.length() << endl;

	for (int i = 0; i < sum_string.length()-1; i += 3)
	{
		long double moss;
		string lawl;
		char ha;
		/*if (i == 0 && zero == true)
		{
			istringstream lol1(sum_string);
			lol1 >> moss;
		}*/

		if (sum_string[i] == '0')
		{
			//cout << sum_string[i + 1] << endl;
			//cout << sum_string[i + 2] << endl;

			lawl = sum_string[i + 1];
			lawl += sum_string[i + 2];
			istringstream lol1(lawl);
				lol1 >> moss;
				ha = moss;
		}
		else
		{
			istringstream lol1(lawl);
			lol1 >> moss;
			ha = moss;
		}
		cout << ha;
	}
	cout << "\nEnd." << endl;
}