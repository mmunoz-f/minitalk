# minitalk

This is a simple project of how Unix signals can be used. A client process will send messages to another server process.

<h3>How it works</h3>

The client will use SIGUSR1 and SIGUSR2 signals to communicate with the servers reinterpreting them as 0s and 1s, so the server will receive the data bit by bit.

<h3>How to use</h3>

After using `make` in the root of the repository, we will see to executables, first you should run the server:

```bash
./server
```
This will launch a simple program which will display its process id, and will wait to receive messages from the clients.

Then, in a separated tab, launch the client executable:

```bash
./client server_id message
```
```bash
./client 10927 "Hello World!"
```
The client will send the second parameter string to the server and this will display it.
