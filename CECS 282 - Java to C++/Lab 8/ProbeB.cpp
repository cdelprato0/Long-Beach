//Chaz Del Prato & Anthony Pham
//Probe A, Probe B, Probe C, Hub, Kill_patch, foce_patch
//This file will have the requirements for the probe B
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>

using namespace std; 

int main() {
	//Gets the message queue from the created instance
	int qid = msgget(ftok(".",'u'), 0);

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

	//Probe B's magic seed
	int beta = 257;
	//The content from the probe
	string content;
	//Seeds the random number generator with the magic seed
	srand(beta);
	//values used to store the random number
	int randNum = 0;
	//keeps a count of the messages
	int msgCount = 0;

	//Loop will constantly run until the forced patch is taken. Happens after 10000 messages to the Hub.
	while(true){
		
		//Randomly chooses a number that is divisiable by the magic seed
		do{
			randNum = rand();
		}while(randNum % beta != 0);
		//Sets and converts the random number into a string
		content = to_string(randNum);

		//If it is the probes first message, it will send the PID first
		if(msgCount == 0){
			cout << getpid() << ": Sending PID to Hub..." << endl;
			msg.pid = getpid();
			strncpy(msg.greeting, content.c_str(), sizeof(msg.greeting));
			msg.mType = 111;
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

	cout << "Probe B has terminated!!!" << endl;
	return 0;
}
