#pragma once

#include <iostream>
#include <memory>
using namespace std;

// Transfer library
class Usb {
public:
	bool isAvailable();

	void connect();

	void send(string file);
};

bool Usb::isAvailable() { return false; }

void Usb::connect() { cout << "Connecting via USB" << endl; }

void Usb::send(string file) { cout << file << " sent." << endl; }

class Bluetooth {
public:
	bool isAvailable();

	void connect();

	void authenticate();

	void send(string file);
};

bool Bluetooth::isAvailable() { return true; }

void Bluetooth::connect() { cout << "Connecting via BT" << endl; }

void Bluetooth::authenticate() { cout << "Authenticating BT" << endl; }

void Bluetooth::send(string file) { cout << file << " sent." << endl; }

// The Facade
class FileTransfer {
public:
	void sendFile(string fileName);
};

void FileTransfer::sendFile(string fileName)
{
	shared_ptr<Usb> u(new Usb());
	shared_ptr<Bluetooth> b(new Bluetooth());
	if (u->isAvailable()) {
		u->connect();
		u->send(fileName);
	}
	else if (b->isAvailable()) {
		b->connect();
		b->authenticate();
		b->send(fileName);
	}
	else {
		cout << "Not sent" << endl;
	}
}

// Test Program
int main()
{
	unique_ptr<FileTransfer> ft(new FileTransfer());
	ft->sendFile("mypicture");
}
