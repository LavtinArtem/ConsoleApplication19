#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;
#define TRIES 7

int Count_lines(char* fileName);
char* Print_word(char* fileName, int position_word);
bool Ñomparison(char* alfavit, char* word, char* hidden_word, char symbol);
void DeletStr(char* str);
