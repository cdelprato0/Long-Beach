//Chaz Del Prato & Anthony Pham
//Probe A, Probe B, Probe C, Hub, Kill_patch, foce_patch
//This file will have the requirements for the probe C
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
#include "kill_patch.h"

using namespace std; 

int main() {
	
	//This struct is for the buffer, it allows us to pass messages to the hub
	struct buffer{
		long mType;
		char greeting[50];
		int pid;
	};

	//An instance of the buffer
	buffer msg;
	//the size of the message
	int size = sizeof(msg)-sizeof(long);

	//Probe C's magic seed
	int rho = 251;
	//The content from the probe
	string content;
	//Seeds the random number generator with the magic seed
	srand(rho);
	//values used to store the random number
	int randNum = 0;
	//keeps a count of the messages
	int msgCount = 0;

	//Gets the message queue from the created instance
	int qid = msgget(ftok(".",'u'), 0);

	//When the kill command is excuted, it will relay this message to the hub
	content = "Kill";
	//Copys the string of string one(content) into the string two (msg.greeting), 
	//with a fixed size of string 2 (msg.greeting)
	strncpy(msg.greeting, content.c_str(), sizeof(msg.greeting));
	//Sets the message type
	msg.mType = 111;
	//Calls the kill patch that will kill the probe when called kill -10 [pid]
	kill_patch(qid, (struct msgbuf*)&msg, size, 111);

	//Runs the loop until the probe is killed
	while(true){
		
		//Randomly chooses a number that is divisiable by the magic seed
		do{
			randNum = rand();
		}while(randNum % rho != 0);

		//Sets and converts the random number into a string
		content = to_string(randNum);
		//If it is the probes first message, it will send the PID first
		if(msgCount == 0){
			cout << getpid() << ": Sending PID to Hub..." << endl;
			//Sets the PID
			strncpy(msg.greeting, content.c_str(), sizeof(msg.greeting));
			msg.pid = getpid();
			msg.mType = 111;
			//sends a message to the Hub with the content of pid
			msgsnd(qid, (struct msgbuf*)&msg, size, 0);
		}
		
		//Sends the random number to the Hub
		cout << getpid() << ": Sending message to Hub..." << endl;
		strncpy(msg.greeting, content.c_str(), sizeof(msg.greeting));
		msg.mType = 111;
		msgsnd(qid, (struct msgbuf*)&msg, size, 0);
		//increments the count of messages
		msgCount++;

	}

	cout << "Probe C has Been KILLED!!" << endl;
	return 0;
}
