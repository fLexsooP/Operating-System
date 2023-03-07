
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <bits/stdc++.h>


using namespace std;

string sentence;
vector<string> words;
int cur_index = 0;
bool flag;

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
        flag = isalpha(words[cur_index][0]);
        if (flag) {
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
        flag = isalpha(words[cur_index][0]);
        if (!flag) {
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
	sentence = argv[1];
    words = split_into_words(sentence);
    
    
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

