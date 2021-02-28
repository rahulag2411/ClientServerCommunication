#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc!=2)
    {
        cerr << "Missing port number\n";
        exit(0);
    }
    int port = atoi(argv[1]);
    char message[1500];
    sockaddr_in serverSocket;
    bzero((char *)&serverSocket, sizeof(serverSocket));
    serverSocket.sin_family = AF_INET;
    serverSocket.sin_port = htons(port);
    serverSocket.sin_addr.s_addr = htonl(INADDR_ANY);

    int serverSocketID = socket(AF_INET, SOCK_DGRAM, 0);
    if (serverSocketID<0)
    {
        cerr<<"Not Successful socket()\n";
        exit(0);
    }

    int bindStatus =  bind(serverSocketID, (struct sockaddr *)&serverSocket, sizeof(serverSocket));
    if (bindStatus<0)
    {
        cerr<<"Not Successful bind()\n";
        exit(0);
    }
    
    cout<<"Waiting for the client to connect...\n";

    //Connection socket
    sockaddr_in newSocket;
    memset(&newSocket, 0, sizeof(newSocket));
    socklen_t newSocketLen = sizeof(newSocket);

    while (true)
    {
        cout<<"Client: ";
        recvfrom(serverSocketID, (char *)&message, sizeof(message), 0, (struct sockaddr*)&newSocket, &newSocketLen);
        if (!strcmp(message, "exit"))
        {
            cout<<"Connection Ended\n";
            break;
        }
        cout<<message<<"\n";
        cout<<"Server: ";
        string data;
        getline(cin, data);
        strcpy(message, data.c_str());
        sendto(serverSocketID, (char *)&message, sizeof(message), 0, (struct sockaddr*)&newSocket, sizeof(newSocket));
        if (data=="exit")
        {
            cout<<"Connection Ended\n";
            break;
        }
    }
    
    close(serverSocketID);

    return 0;
}


