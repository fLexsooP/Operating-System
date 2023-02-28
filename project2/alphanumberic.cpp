
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <string>

#include <bits/stdc++.h>

using namespace std;

string phrase = "";
istringstream ss;
bool locked;

void* print_alpha(void* arg) {
    char* message;
    message = (char*)arg;

    string word;

    while(ss >> word) {
        if (word[0] < '0' || word[0] > '9') {
            printf("%s: ", message);
            cout << word << endl;
        }
    }
    pthread_exit(0);
}



void* print_numeric(void* arg) {
    char* message;
    message = (char*)arg;

    string word;

    while(ss >> word) {
        if (word[0] >= '0' && word[0] <= '9') {
            printf("%s: ", message);
            cout << word << endl;
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
    ss.str(phrase);

    pthread_t alpha, numeric;
    // char* alpha_message = const_cast<char*>(a_message.c_str());
    // char* numeric_message = const_cast<char*>(n_message.c_str());
    char* alpha_message = const_cast<char*>("alpha");
    char* numeric_message = const_cast<char*>("numeric");
    int  alpha_ret, num_ret;
    
    alpha_ret = pthread_create(&alpha, NULL, print_alpha, (void*)alpha_message);
    num_ret = pthread_create(&numeric, NULL, print_numeric, (void*)numeric_message);


    
    pthread_join(alpha, NULL);
    pthread_join(numeric, NULL);

    return 0;
}

