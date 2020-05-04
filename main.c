#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void breakit(char letter, bool & done, int length, string & str) {

	string commonLetters = "ETAOINSHR";
	int trackLetter = 0;
	bool firstDone = false;
	string commonDigrams = "THHEINERANREEDONESSTATTONTHANDOUEANGASORTIISETITSEHIOFHOADOOSSAIAL";
	string commonTrigrams = "THEINGANDHEREREENTTHANTHWASETHFORDTHYOU";
	string notCommon = "ZQJXV";

	int tempy = letter;


	while (!firstDone) {


		int key = commonLetters[trackLetter] - letter;

		if (letter < commonLetters[trackLetter]) {
			key *= -1;
			key += 26;
		}
		else if(key < 0){
			abs(key);
		}

		string tempStr = str;
		int counter = 0;

		//cout << " The Testing key is " << abs(key) << endl;
		//cout << " The Testing Freq Letter is " << commonLetters[trackLetter] << endl;


		for (int i = 0; i < length; i++)
		{
			tempStr[i] = (((str[i] - abs(key) + 26) - 65) % 26) + 65;
		}

		//cout << "Decrypted with testing key: " << tempStr << endl << endl << endl;


		//at this point the cipher text as been decypted with E
		//examine tempstr for english grammerical syntax
		for (int k = 0; k < length-1; k++) {

			for (int j = 0; j < 66; j++)
			{
				if (commonDigrams[j] == tempStr[k] && commonDigrams[j + 1] == tempStr[k + 1]) {
					//cout << "MATCHING GRAM: " << commonDigrams[j] << commonDigrams[j + 1] << endl;
					counter++;
				}
				j++;
			}
		}


		for (int k = 0; k < length - 1; k++) {

			for (int j = 0; j < 5; j++)
			{
				if (notCommon[j] == tempStr[k]) {
					//cout << "NOT COMMON LETTERS: " << notCommon[j]<< endl;
					counter--;
				}
			}
		}




		//number of hits for grams
		//cout << "Number of digram hits: " << counter << endl;

		for (int q = 0; q < length-2; q++) {

			for (int t = 0; t < 39; t++)
			{
				if (commonTrigrams[t] == tempStr[q] && commonTrigrams[t + 1] == tempStr[q + 1] && commonTrigrams[t + 2] == tempStr[q + 2]) {
					//cout << "MATCHING TRIGRAM: " << commonTrigrams[t] << commonTrigrams[t + 1] << commonTrigrams[t + 2] << endl;
					counter += 1;
				}
				t += 2;
			}
		}

		//cout << "Number of trigram hits: " << counter << endl << endl;

		int tens = 10;
		bool found = false;

		if (length <= tens && counter > 0) {
			firstDone = true;
			done = true;
			str = tempStr;
			found = true;
		}
		else if (length > tens) {

			//matching length of string and gram possiblilities algorithm
			for (int h = 1; h < 1000; h++) {

				if (length < tens && counter > h) {
					firstDone = true;
					done = true;
					str = tempStr;
					found = true;
				}

				tens += 10;
			}
		}
		else if(!found){
			//cout << "no match....................." << endl;
		}

		if (commonLetters[trackLetter] == 'R') {
			firstDone = true;
		}
		trackLetter++;
	}
}

void letterFrequencies(string & str) {

	int word_length = size(str);
	int counter = 0;
	int numArray[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	char charArray[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};


	//count up all the individual letters
	while (counter < word_length) {

		if (str[counter] == 'A') {
			numArray[0] += 1;
		}
		else if (str[counter] == 'B') {
			numArray[1] += 1;
		}
		else if (str[counter] == 'C') {
			numArray[2] += 1;
		}
		else if (str[counter] == 'D') {
			numArray[3] += 1;
		}
		else if (str[counter] == 'E') {
			numArray[4] += 1;
		}
		else if (str[counter] == 'F') {
			numArray[5] += 1;
		}
		else if (str[counter] == 'G') {
			numArray[6] += 1;
		}
		else if (str[counter] == 'H') {
			numArray[7] += 1;
		}
		else if (str[counter] == 'I') {
			numArray[8] += 1;
		}
		else if (str[counter] == 'J') {
			numArray[9] += 1;
		}
		else if (str[counter] == 'K') {
			numArray[10] += 1;
		}
		else if (str[counter] == 'L') {
			numArray[11] += 1;
		}
		else if (str[counter] == 'M') {
			numArray[12] += 1;
		}
		else if (str[counter] == 'N') {
			numArray[13] += 1;
		}
		else if (str[counter] == 'O') {
			numArray[14] += 1;
		}
		else if (str[counter] == 'P') {
			numArray[15] += 1;
		}
		else if (str[counter] == 'Q') {
			numArray[16] += 1;
		}
		else if (str[counter] == 'R') {
			numArray[17] += 1;
		}
		else if (str[counter] == 'S') {
			numArray[18] += 1;
		}
		else if (str[counter] == 'T') {
			numArray[19] += 1;
		}
		else if (str[counter] == 'U') {
			numArray[20] += 1;
		}
		else if (str[counter] == 'V') {
			numArray[21] += 1;
		}
		else if (str[counter] == 'W') {
			numArray[22] += 1;
		}
		else if (str[counter] == 'X') {
			numArray[23] += 1;
		}
		else if (str[counter] == 'Y') {
			numArray[24] += 1;
		}
		else if (str[counter] == 'Z') {
			numArray[25] += 1;
		}

		counter++;
	}

	//find most frequent letter
	//char letter;
	int i = 0;
	int temp = 0;


	//INITIAL ARRAYS BEFORE SWAPS
	////////////////////////////////////////////
	//cout << endl << endl << "Number Array: ";
	//for (i = 0; i < 26; i++) {
	//	cout << numArray[i] << " ";
	//}
	//cout << endl;
	//cout << "Char Array:   ";
	//for (i = 0; i < 26; i++) {
	//	cout << charArray[i] << " ";
	//}
	//cout << endl << endl;
	/////////////////////////////////////////////


	//swaping
	for (int ii = 0; ii < 26; ii++) {
		for (int iii = 0; iii < 26; iii++)
			if (numArray[iii+1] > numArray[iii])
			{
				swap(numArray[iii + 1], numArray[iii]);
				swap(charArray[iii + 1], charArray[iii]);
			}
	}


	////AFTER ARRAYS SWAP
	////////////////////////////////////////////
	//cout << endl << endl << "Number Array: ";
	//for (i = 0; i < 26; i++) {
	//	cout << numArray[i] << " ";
	//}
	//cout << endl;
	//cout << "Char Array:   ";
	//for (i = 0; i < 26; i++) {
	//	cout << charArray[i] << " ";
	//}
	//cout << endl << endl;
	/////////////////////////////////////////////

	//cout << "Highest Frequency is: " << numArray[0] << " the letter: " << charArray[0] << endl;
	//cout << "Second Highest Frequency is: " << numArray[1] << " the letter: " << charArray[1] << endl << endl;

	//START BREAKING ALOGORITHM NOW

	bool DONE = false;
	int tryit = 0;

	//IF NOT DONE LOOP
	while (!DONE)
	{
		//cout << " The Testing Ciphered Letter is " << charArray[tryit] << endl;
		breakit(charArray[tryit], DONE, word_length, str);//needs highest freq key 
		tryit++;
		if (!DONE && tryit == 4) {
			cout << "NO MATCH WAS FOUND IN OUR ALGORITHM" << endl;
			DONE = true;
		}
	}
	

	//ETAOIN SHRDLU   <====== are the most frequent letters in english language
}

void WordUpper(string &word)		//upper case the word to cipher
{
	int word_length = size(word) - 1;

	for (int i = 0; i < word_length + 1; i++)		//upper each letter to cipher text
	{
		word[i] = toupper(word[i]);
	}
}

void WordRemoveNonAlpha(string &word)	//remove all symbols and spaces from the text
{
	string alpha_word;
	int word_length = size(word) - 1;			//get the length of the alpha/symbol word

	for (int i = 0; i < word_length + 1; i++)		//upper each letter to cipher text
	{
		if (isalpha(word[i]))						//if it is a alpha character
		{
			alpha_word.append(1, toupper(word[i]));	//save it uper case in the only alpha word
		}
		//else drop the character
	}

	word = alpha_word;		//assign the only alpha version of the word
}

void cleanArray(string & str) {

	WordRemoveNonAlpha(str);
	WordUpper(str);

}

void getFile(string & inputs) {

	//get the file name
	string fileName;
	cout << "Enter File Name: ";
	getline(cin, fileName);

	//declare input file stream
	ifstream inFile;
	
	//open file for input stream
	inFile.open(fileName);

	//check if file was opened
	if (!inFile) {
		cerr << "Warning: Unable to open file '" << fileName << "'" << endl;
		return;
	}

	//read file
	//if not at end of file, continue reading numbers
	while (!inFile.eof())      
	{
		//get next character from file
		getline(inFile, inputs);               
	}

	//close input stream
	inFile.close();
}



int main() {

	string inputs;//our ciphertext to be decrypted


	cout << "Welcome to a cryptoanalysis of the cesar cipher" << endl;




	getFile(inputs);//gets the ciphertext from the file and stores in "inputs"

	//cout << "OriginalText: " << inputs << endl << endl;//print what was originally in the file

	cleanArray(inputs);//cleans up the array so we only have alphabet letters

	cout << endl << "CipherText:   " << inputs << endl <<endl;//print the cleaned up array

	letterFrequencies(inputs);//start our frequency algorithms

	string plaintext = inputs;

	//makelowercase
	int word_length = size(plaintext) - 1;

	for (int i = 0; i < word_length + 1; i++)		//upper each letter to cipher text
	{
		plaintext[i] = tolower(plaintext[i]);
	}

	cout << "PlainText:    " << plaintext << endl;//when algorithms are complete we will print the final decrypted text here



	system("PAUSE");
	return 0;
}
