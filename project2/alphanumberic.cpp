
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <ctype.h>
#include <bits/stdc++.h>


using namespace std;

string phrase;
vector<string> words;
int cur_index = 0;
bool locked = true;

vector<string> split_into_words(string phrase) {
    stringstream ss(phrase);
    string word;
    vector<string> words;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

void* print_alpha(void* arg) {
    char* message;
    message = (char*)arg;

    while (cur_index < words.size()) {
        if (isalpha(words[cur_index][0])) {
            cout << message << ": " << words[cur_index] << endl;
            cur_index++;
        } 
    }
    pthread_exit(0);
}

void* print_numeric(void* arg) {
    char* message;
    message = (char*)arg;

    while (cur_index < words.size()) {
        if (isdigit(words[cur_index][0])) {
            cout << message << ": " << words[cur_index] << endl;
            cur_index++;
        }
    }
    pthread_exit(0);
}


int main(int argc, char const *argv[])
{
    if (argc < 2)
	{
		fprintf(stderr, "USAGE: %s <PHRASE>\n", argv[0]);
		exit(-1);
	}

	/* Save the name of the file */
	phrase = argv[1];
    words = split_into_words(phrase);
    



    pthread_t alpha, numeric;
    char* alpha_message = const_cast<char*>("alpha");
    char* numeric_message = const_cast<char*>("numeric");
    int  alpha_ret, num_ret;
    
    alpha_ret = pthread_create(&alpha, NULL, print_alpha, (void*)alpha_message);
    num_ret = pthread_create(&numeric, NULL, print_numeric, (void*)numeric_message);


    pthread_join(alpha, NULL);
    pthread_join(numeric, NULL);

    return 0;
}

