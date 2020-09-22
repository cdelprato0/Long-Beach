//Chaz Del Prato & Anthony Pham
//Probe A, Probe B, Probe C, Hub, Kill_patch, foce_patch
//This file will have the requirements for the probe A
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>

using namespace std;

int main(){
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

	//Probe A's magic seed
	int alpha = 997;
	//The content from the probe
	string content;
	//Seeds the random number generator with the magic seed
	srand(alpha);
	//values used to store the random number
	int randNum = 0;
	//A flag to check to see if the terminated conditions have been met
	bool exitRandom = false;
	//keeps a count of the messages
	int msgCount = 0;
	
	//sends messages until the random number generator, generates a number lower than 100
	while(!exitRandom){

		//Randomly chooses a number that is divisiable by the magic seed
		do{
			randNum = rand();
		}while(randNum % alpha != 0);

		//If the random number is less than 100, it will terminate the program.
		if(randNum < 100){
			cout << "Terminating Probe A!!!" << endl;
			//sets flag
			exitRandom = true;
			//breaks out of the loop
			break;
		}
		//checks to see if the message count is zero
		if(msgCount == 0){
			//If it is the probes first message, it will send the PID first
			cout << getpid() << ": Sending PID to Hub..." << endl;
			//Sets and converts the random number into a string
			content = to_string(randNum);
			strncpy(msg.greeting, content.c_str(), sizeof(msg.greeting));
			//Sets the pid to the message
			msg.pid = getpid();
			//sets the type of message
			msg.mType = 111;
			//sends the message to the buffer
			msgsnd(qid, (struct msgbuf*)&msg, size, 0);
		}
		//Sets and converts the random number into a string
		content = to_string(randNum);

		//Sends the random number to the hub.
		cout << getpid() << ": Sending message to Hub..." << endl;
		//Copys the string of string one(content) into the string two (msg.greeting), 
		//with a fixed size of string 2 (msg.greeting) 
		strncpy(msg.greeting, content.c_str(), sizeof(msg.greeting));
		msg.mType = 111;
		msgsnd(qid, (struct msgbuf*)&msg, size, 0);

		//After the hub receives a message, it will send one back to th probe
		cout << getpid() << ": Receiving from Hub..." << endl;
		//receiving the message from the hub
		msgrcv(qid, (struct msgbuf*)&msg, size, 217, 0);

		//sets the message content and outputs
		content = msg.greeting;
		cout << "Message from Hub: " << content << endl;

		//increments the message count
		msgCount++;
	}
	//When the loop exits, it will send a message to the hub saying it has terminated
	string quit = "Terminate";
	strncpy(msg.greeting, quit.c_str(),sizeof(msg.greeting));
	msg.mType = 111;
	msgsnd(qid, (struct msgbuf*)&msg, size, 0);

	return 0;
}
