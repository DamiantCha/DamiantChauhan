// Damiant Chauhan
// CIS-7 Online
// Professor Nguyen
// Case Three: Vigenere Cipher Decryption

#include <iostream>
#include <string>
using namespace std;
string encrypt(string plaintext, string key); // function prototype
string decrypt(string ciphertext, string key); //function prototype

string encrypt(string plaintext, string key) // function definition used to encrypt plaintext with key
{
	string ciphertext = ""; // variable to store ciphertext
	int keyIndex = 0; // variable to keep track of key index
	for (int i = 0; i < plaintext.length(); i++) // increment the length of the plaintext 
	{
		if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') // 
		{
			ciphertext += (((plaintext[i] - 'A') + (key[keyIndex] - 'A')) % 26) + 'A'; // En(x) = (x + n) mod 26. added the incremented plaintext and the key index in the encryption phase
			keyIndex++; // this will increase the value of the variable by 1
			if (keyIndex == key.length()) // key index is equal to the length of the key
				keyIndex = 0; 
		}
		else
			ciphertext += plaintext[i];
	}
	return ciphertext;
}

string decrypt(string ciphertext, string key)
{
	string plaintext = ""; // variable to store the plaintext
	int keyIndex = 0; // keyIndex is set to 0
	for (int i = 0; i < ciphertext.length(); i++) // increment the length of the plaintext
	{
		if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z')
		{
			plaintext += (((ciphertext[i] - 'A') - (key[keyIndex] - 'A')) % 26) + 'A'; // En(x) = (x - n) mod 26. subtracted the increment ciphertext and the key index in the decryption phase
			keyIndex++; // increases the value of the variable by 1
			if (keyIndex == key.length()) 
				keyIndex = 0;
		}
		else
			plaintext += ciphertext[i];
	}
	return plaintext;
}
int main() {
	int choice;
	char again;
	cout << "----------------------------------------Welcome to the vigenere cipher program!----------------------------------------" << endl;
	cout << "-------------------------------------------All letters must be capatalize ---------------------------------------------" << endl;
	do // used a do while loop to rerun the program as many time as the user wishes
	{
	cout << "1. Encrypt" << endl; // output the choices user has to choose
	cout << "2. Decrypt" << endl;
	cin >> choice; // whatever the user chooses will be stored in the choice variable
	cin.ignore();
	
	

		if (choice == 1) // choice 1 is the the encryption choice where the user enters the plaintext and the key and the cipher text is given back
		{
			
			string plaintext;
			string key;
			string ciphertext;

			cout << "Enter plaintext: ";
			getline(cin, plaintext); // this is were the plaintext is stored
			cout << "Enter key: ";
			getline(cin, key); // this is where the key is stored

			cout << "Ciphertext: " << encrypt(plaintext, key) << endl; // this is where i call on the encrypt function that stores returns the ciphertext


		}

		else if (choice == 2) // choice 2 is the decryption function where the ciphertext is entered and so is the key and it will return back the plaintext
		{
			string ciphertext;
			string key;
			string plaintext;

			cout << "Enter ciphertext: "; // prompt user to enter ciphertext
			getline(cin, ciphertext); // get ciphertext
			cout << "Enter key: "; // prompt user to enter key
			getline(cin, key); // get key

			cout << "Plaintext: " << decrypt(ciphertext, key) << endl; // This is where i call on the decrypt function which returns the plaintext
		}
		else
		{
			cout << "Invalid choice." << endl; // If the user chooses a number that isn't one or two it will display "invalid choice"
		}
		
		cout << "Would you like to run the program again? (y/n): "; // given characters to ask the user if they wish to rerun the program
		cin >> again;
		cin.ignore();
	} while(again == 'Y' || again == 'y');
	
	
}














