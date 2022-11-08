#include"Header.h"

int Count_lines(char* fileName) {
	FILE* f1;
	char str[255];
	int count = 0;
	if (fopen_s(&f1, fileName, "r") == NULL) {
		while (!feof(f1)) {
			fgets(str, 255, f1);
			count++;
		}
		fclose(f1);
	}
	return count;
}

char* Print_word(char* fileName, int position_word) {
	FILE* f1;
	char* str = new char[255];
	if (fopen_s(&f1, fileName, "r") == NULL) {
		for (int i = 0; i <= position_word; i++)
		{
			fgets(str, 255, f1);
		}

		fclose(f1);
	}
	return str;
}
bool Ñomparison(char* alfavit, char* word, char* hidden_word, char symbol) {
	bool IsGuessLetter = false;
	if (isupper(symbol)) {
		symbol = tolower(symbol);
	}
	char* pos = strchr(alfavit, symbol);
	if (pos == nullptr) {
		cout << "Enter the letter of the latin alphabet!" << endl;
	}
	else {
		*pos = ' ';
	}
	for (int i = 0; i < strlen(word); i++)
	{
		if (word[i] == symbol) {
			hidden_word[i] = symbol;
			IsGuessLetter = true;
		}


	}
	return IsGuessLetter;
}

void DeletStr(char* str) {
	delete[]str;
}
