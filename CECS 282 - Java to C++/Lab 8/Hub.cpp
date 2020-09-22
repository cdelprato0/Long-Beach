//Chaz Del Prato & Anthony Pham
//Probe A, Probe B, Probe C, Hub, Kill_patch, foce_patch
//This file will have the requirements for the HUB
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
#include <sstream>
#include "force_patch.h"

using namespace std;

int main(){

	//Creates the new message queue
	int qid = msgget(ftok(".",'u'), IPC_EXCL|IPC_CREAT|0600);
	cout << "The QUEUE has been CREATED" << endl;
	
	//This struct is for the buffer, it allows us to read and pass information 
	//to the probes
	struct buf{
		long mType;
		char greeting[50];
		int pid;
	};
	//An instance of the buffer
	buf msg;
	//the size of the message
	int size = sizeof(msg)-sizeof(long);

	//variable to store the sender's message
	string senderMessage;
	//keeps counts of the number of messages sent
	int aCount = 0;
	int bCount = 0;
	int cCount = 0;
	//keeps the pid's of each of the probes
	int pidA = 0;
	int pidB = 0;
	int pidC = 0;
	//keeps the random value used for valid reading
	int validReading;
	//flag to determine which probes are running
	bool probeA = true;
	bool probeB = true;
	bool probeC = true;
	
	//While the probes are running
	while(probeA || probeB || probeC){
		//Receives a message from a probe
		msgrcv(qid, (struct msgbuf*)&msg, size, 111, 0);
		//Copies the contents of the message
		senderMessage = msg.greeting;
		//if the message contains the terminate key word, it will terminate the probe A
		if(senderMessage.compare("Terminate") == 0){
			probeA = false;
			continue;
		}
		
		//helps convert from a string to an integer
		stringstream geek(senderMessage);
		//Sets the valid reading number to zero
		validReading = 0;
		//converts the string into an integer
		geek >> validReading;

		//If the random variable can be divisiable by probe A's magic seed, 
		//then we pefrom probe A's function
		if(validReading % 997 == 0){
			//If the message count is zero, it will read the PID
			if(aCount == 0){
				pidA = msg.pid;
			}
			cout << "Message A: " << validReading << " received from " << pidA << endl;
			
			//Sends a message back to probe A so that the probe can send another message
			strncpy(msg.greeting, "Good message", sizeof(msg.greeting));
			msg.mType = 217;
			msgsnd(qid, (struct msgbuf*)&msg, size, 0);
			//increments the count
			aCount++;
				
		}
		//If the random variable can be divisiable by probe B's magic seed, 
		//then we pefrom probe B's function
		else if(validReading % 257 == 0){
			//If the message count is zero, it will read the PID
			if(bCount == 0){
				pidB = msg.pid;
			}
			cout << "Message B: " << validReading << " received from " << pidB << endl;
			//When the message count is equal to 10,000 it will force patch and kill the process
			if(bCount == 10000){
				probeB = false;
				cout << "The Probe B has been Forced!!" << endl;
				//function given to us by the professor
				force_patch(msg.pid);
			}

			bCount += 1;
		}
		//If the random variable can be divisiable by probe C's magic seed, 
		//then we pefrom probe C's function
		else if(validReading % 251 == 0){
			//If the message count is zero, it will read the PID
			if(cCount == 0){
				pidC = msg.pid;
			}
			cout << "Message C: " << validReading << " received from " << pidC << endl;
			//If the kill message has been sent
			if(senderMessage.compare("Kill") == 0){
				cout << "Probe C has been KILLED!!!" << endl;
				probeC = false;
				continue;
			}
			
			cCount++;

		}
	}
			
	//Deleteing the message queue
	msgctl(qid, IPC_RMID, NULL);

	return 0;
}
