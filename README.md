# CLIENT-SERVER COMMUNICATION

This project is entirely written in *C++* .It includes socket programming using both TCP and UDP protocols.

## Running this on Your Own Local System

* Clone this Repo to your local System.
* Go to the directory where you have clone this repo
* Now Select the connection you wish to establish

* Run following commands in your terminal.
 
     ```
     g++ -o testServer server.cpp
     ```
    ```
    ./testServer <port_number>
    ```

* Open a new window of terminal in current folder and run following commands.
     ```
     g++ -o testClient client.cpp
     ```
    ```
    ./testClient localhost <port_number>
    ```

**Note** - The commands given in step 3 and 4 assumes that you have gcc installed on your system and you are working on ubuntu operating system.


## See How it works!

> Image of TCP

![Image of TCP](/static/TCP.png)

 ############################################

> Image of UDP

![Image of UDP](/static/UDP.png)