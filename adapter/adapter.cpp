#include <iostream>
#include <string>

typedef int Cable;

//adapter interface

class EuropeanSocketInterface {
	public:
		virtual int voltage() = 0;
		virtual Cable live() = 0;
		virtual Cable neutral() =0;
		virtual Cable earth() = 0;
};

class Socket : public EuropeanSocketInterface {
	public:
		int voltage() { return 230; }

        	Cable live() { return 1; }
        	Cable neutral() { return -1; }
        	Cable earth() { return 0; }
};


class USASocketInterface {
	public:
		virtual int voltage() = 0;

        	virtual Cable live() = 0;
        	virtual Cable neutral() = 0;
};

//Adapter

class Adapter : public USASocketInterface {
	EuropeanSocketInterface* socket;

	public:
		void plugIn(EuropeanSocketInterface* outlet) {
			socket = outlet;		
		}

	int voltage() {return 110; }
	Cable live() {return socket->live();}
	Cable neutral() {return socket->neutral();}
};


//Client
class Electric {
	USASocketInterface* power;

	public:
		void plugIn(USASocketInterface* supply) {
			power = supply;	
		}

	void boil() {
 if (power->voltage() > 110)
            {
                std::cout << "Kettle is on fire!" << std::endl;
                return;
            }

            if (power->live() == 1 && power->neutral() == -1)
            {
                std::cout << "Coffee time!" << std::endl;
            }
        }
};


int main() {
	Socket* socket = new Socket;
	Adapter* adapter = new Adapter;
	Electric* ketty = new Electric;

	/*plug in*/

	adapter->plugIn(socket);
	ketty->plugIn(adapter);

	ketty->boil();
return 0;
}
