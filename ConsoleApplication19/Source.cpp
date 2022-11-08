#include"Header.h"
void main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	FILE* f1;
	char* wordFile = new char[255];
	char symbol;
	char file_Name[] = "file1.txt";
	char alfavit[255] = "abcdefghijklmnopqrstuvwxyz";
	int tries = TRIES, count = 0;
	int count_lines = Count_lines(file_Name);
	printf("%i count of lines\n", count_lines);
	int position_word = rand() % count_lines;
	cout << "position_word: " << position_word << endl;
	strcpy(wordFile, Print_word(file_Name, position_word));
	int size = strlen(wordFile);
	if (wordFile[strlen(wordFile) - 1] == '\n') {
		wordFile[strlen(wordFile) - 1] = '\0';
	}
	char* hidden_word = new char[strlen(wordFile) + 1];
	memset(hidden_word, '*', strlen(wordFile) + 1);
	hidden_word[strlen(wordFile)] = '\0';

	printf("Words: %s  \n", wordFile);

	do {
		printf("Fake word: %s  \n", hidden_word);
		printf("Tries: %d  \n", tries);
		cout << "Enter symbol:\n";
		cin >> symbol;
		tries--;
		count++;
		Ñomparison(alfavit, wordFile, hidden_word, symbol);
	} while (tries != 0 && strcmp(wordFile, hidden_word) != 0);
	printf("Hidden word: %s  \n", hidden_word);
	if (tries != 0) {
		cout << " CONGRATULATION! YOU ARE WIN!!! You guessed the word for: " << count << " tries!" << endl;
	}
	else
		cout << "GAME OVER!" << endl;

	DeletStr(wordFile);
	DeletStr(hidden_word);

	system("pause");	
}