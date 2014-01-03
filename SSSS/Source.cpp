
#include <iostream>
#include <math.h>
#include <string>
#include <time.h>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include "LargeNumber.h"

//#include "BigInteger.hh"
////#include "BigUnsigned.hh"
//#include "BigIntegerUtils.hh"
////#include "BigIntegerLibrary.hh"
using namespace std;


void encrypt();
void decrypt();
CLargeNumber convertToASCII(string);


string sum;
bool zero = false;
bool decimal = false;

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


CLargeNumber convertToASCII(string letter)
{
	long long engie;
	for (int i = 0; i < letter.length(); i++)
	{
		char x = letter.at(i);
		//cout << int(x) << endl;
		if (int(x) < 100)
		{
			
			if(int(x) != ' ')
				zero = true;
			sum = sum + '0' + to_string(int(x));
		}
		else
		sum += to_string(int(x));;
	}

	cout << sum << endl;
	istringstream buffstring(sum);
	buffstring >> engie;

	//return CLargeNumber(engie);
	return CLargeNumber(sum);
}

void encrypt()
{
	ofstream out("Output.txt");

	srand(time(NULL));
	 CLargeNumber random = rand() % 1000 + 200;
	srand(time(NULL));
	 CLargeNumber random_2 = rand() % 1000 + 200;

	string to_encrypt__;
	CLargeNumber to_encrypt;
	long shares;
	cout << "Enter a number: ";
	cin.ignore();
	getline(cin,to_encrypt__);
	cout << "Shares to create: " << endl;
	cin >> shares;
	
	//long long(shares)
	to_encrypt = convertToASCII(to_encrypt__);


	cout << to_encrypt.ToString() << endl;


	cout << "Encryption keys: " << endl;
	for (long i = 1; i <= shares; i++)
	{
		cout << i << ": ";
		if (zero == true)
		{
			cout << "0";
			out << "0";
			}
		cout << i;
		out << i;
		CLargeNumber oLN = CLargeNumber(i) * CLargeNumber(random);
		CLargeNumber oLN2 =  CLargeNumber(i) * CLargeNumber(i) * CLargeNumber(random_2);
		//cout << to_encrypt + (CLargeNumber(i) * CLargeNumber(random)) + (CLargeNumber(i) * CLargeNumber(i) * CLargeNumber(random_2));
		CLargeNumber oLN3 = to_encrypt + oLN + oLN2;
		cout << oLN3.ToString();
		out << oLN3.ToString() << endl;
		cout << endl;
	}


}


//void decrypt()
//{
//	const int size = 3;
//	string keys[size];
//	string x;
//	string x_1;
//	string x_2;
//	string to_decrypt[size];
//
//
//	long double first_term[size];
//	long double second_term[size];
//	long double third_term[size];
//
//	long double x_;
//	long double x__;
//	long double x___;
//	long double number;
//
//	long double mult;
//	long double mult1;
//	long double mult2;
//
//	cout << "Enter the keys. " << endl;
//	for (int i = 0; i < size; i++)
//	{
//		cin >> keys[i];
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		string place = keys[i];
//		long double num;
//		if (place[0] == '0')
//		{
//			place = place.substr(1, place.length() - 1);
//			zero = true;
//		}
//
//		istringstream lol(place);
//		lol >> num;
//
//		number = num;
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
//	to_decrypt[0] = to_decrypt[0].substr(1, to_decrypt[0].length() - 1);
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
//	long double sum = third_term[0] * x_ + third_term[1] * x__ + third_term[2] * x___;
//
//	cout << sum << endl;
//
//	string sum_string;
//
//	if (zero == true)
//	{
//		sum_string = '0' + to_string(sum) ;
//		cout << sum_string << endl;
//	}
//
//	size_t dotIndex = sum_string.find(".");
//	sum_string = sum_string.substr(0, dotIndex);
//
//	cout << sum_string.length() << endl;
//
//	for (int i = 0; i < sum_string.length()-1; i += 3)
//	{
//		long double moss;
//		string lawl;
//		char ha;
//		/*if (i == 0 && zero == true)
//		{
//			istringstream lol1(sum_string);
//			lol1 >> moss;
//		}*/
//
//		if (sum_string[i] == '0')
//		{
//			//cout << sum_string[i + 1] << endl;
//			//cout << sum_string[i + 2] << endl;
//
//			lawl = sum_string[i + 1];
//			lawl += sum_string[i + 2];
//			istringstream lol1(lawl);
//				lol1 >> moss;
//				ha = moss;
//		}
//		else
//		{
//			istringstream lol1(lawl);
//			lol1 >> moss;
//			ha = moss;
//		}
//		cout << ha;
//	}
//	cout << "\nEnd." << endl;
//}

void decrypt()
{
	const int size = 3;
	CLargeNumber keys[size];
	string x;
	string x_1;
	string x_2;
	string to_decrypt[size];

	string to_decrypt_[size];


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


	/*CLargeNumber first_term[size];
	CLargeNumber second_term[size];
	CLargeNumber third_term[size];*/

	/*CLargeNumber number;

	CLargeNumber mult;
	CLargeNumber mult1;
	CLargeNumber mult2;*/

	cout << "Enter the keys. " << endl;
	for (int i = 0; i < size; i++)
	{
		string input;
		//cin >> CLargeNumber(input);
		cin >> input;
		//cin >> keys[i](input);
		if (i == 0)
			keys[0] = CLargeNumber(input);
		if (i == 1)
			keys[1] = CLargeNumber(input);
		if (i == 2)
			keys[2] = CLargeNumber(input);
	}


	for (int i = 0; i < size; i++)
	{
		string place = keys[i].ToString();
		// place = keys[i];
		long double num;


		cout << "First: " << keys[i].ToString()[0] << endl;
		if (place[0] == '0')
		{
			cout << "First: " << place[0] << endl;
			place = place.substr(1, place.length() - 1);
			zero = true;
			cout << "ZERO DETECTED!" << endl;
		}

		/*istringstream lol(place);
		lol >> num;

		number = num;
		cout << "L(" << i << "): " << endl;
		to_decrypt[i] = to_string(number);*/

		istringstream lol(place);
		lol >> num;

		number = num;
		cout << "L(" << i << "): " << endl;
		to_decrypt_[i] = to_string(number);

		to_decrypt[i] = place;

	}

	x = to_decrypt_[0][0];      //x holds first digit
	x_1 = to_decrypt_[1][0];
	x_2 = to_decrypt_[2][0];

	istringstream buffer(x);
	buffer >> x_;

	istringstream buffer1(x_1);
	buffer1 >> x__;

	istringstream buffer2(x_2);
	buffer2 >> x___;


	first_term[0] = 1 / ((x_ - x__) * (x_ - x___));
	second_term[0] = ((-x__) + (-x___)) * first_term[0];
	third_term[0] = ((x__ * x___)) * first_term[0];

	cout << "PASS" << endl;
	cout << first_term[0] << endl;

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

	/*to_decrypt[0] = to_decrypt[0].substr(1, to_decrypt[0].length() - 1);
	to_decrypt[1] = to_decrypt[1].substr(1, to_decrypt[1].length() - 1);
	to_decrypt[2] = to_decrypt[2].substr(1, to_decrypt[1].length() - 1);*/

	/*istringstream multi(to_decrypt[0]);
	multi >> x_;

	istringstream multi1(to_decrypt[1]);
	multi1 >> x__;

	istringstream multi2(to_decrypt[2]);
	multi2 >> x___;*/

	//long double sum = third_term[0] * x_ + third_term[1] * x__ + third_term[2] * x___;

	for (int i = 0; i < size; i++)
	{
		size_t dotIndex = to_decrypt[i].find(".");
		to_decrypt[i] = to_decrypt[i].substr(0, dotIndex);
	}

	cout << "this: " << to_decrypt[0].substr(1, to_decrypt[0].length() - 1);

	string going_dec = to_decrypt[0].substr(1, to_decrypt[0].length() - 1);
	string going_dec2 = to_decrypt[1].substr(1, to_decrypt[1].length() - 1);
	string going_dec3 = to_decrypt[2].substr(1, to_decrypt[1].length() - 1);

	CLargeNumber to_dec = going_dec;
	CLargeNumber to_dec1 = going_dec2;
	CLargeNumber to_dec2 = going_dec3;

	CLargeNumber third_termL = third_term[0];
	CLargeNumber third_termL1 = third_term[1];
	CLargeNumber third_termL2 = third_term[2];
	

		CLargeNumber third = third_termL * to_dec; //Add one to account for decimal place
cout << "pass";
	CLargeNumber third1 = third_termL1 * to_dec1;
	CLargeNumber third2 = third_termL2 * to_dec2;

	cout << "Thirdterm: " << third_termL << endl;
	cout << "to_dec: " << to_dec.ToString() << endl;
	cout << "third: " << third.ToString() << endl;
	
	CLargeNumber sum = third + third1 + third2;

	cout << "Sum: ";
	cout << sum.ToString() << endl;


	string sum_string = sum.ToString();

	if (zero == true)
	{
		sum_string = '0' + sum_string;
		cout << sum_string << endl;
	}

	size_t dotIndex = sum_string.find(".");
	sum_string = sum_string.substr(0, dotIndex);

	cout << "Length: " << endl;
	cout << sum_string.length() << endl;

	cout << "Result: ";
	for (int i = 0; i < sum_string.length() - 1; i += 3)
	{
		long double moss;
		string lawl;
		char ha;
		if (sum_string[i] == '0')
		{
			/*cout << "1. " << sum_string[i + 1] << endl;
			cout << "2. " << sum_string[i + 2] << endl;*/

			lawl = sum_string[i + 1];
			lawl += sum_string[i + 2];
			istringstream lol1(lawl);
			lol1 >> moss;
			ha = moss;
		}
		else
		{

			lawl = sum_string[i];
			lawl += sum_string[i+1];
			lawl += sum_string[i + 2];
			istringstream lol1(lawl);
			lol1 >> moss;
			ha = moss;
		}
		cout << ha;
	}

	cout << "\nEnd." << endl;
}
