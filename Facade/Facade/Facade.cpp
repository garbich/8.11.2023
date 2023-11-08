#include <iostream>
using namespace std;

class TV {
public:

	void onTV() {
		cout << "TV was on" << endl;
	}

	void offTV() {
		cout << "TV was off" << endl;
	}
};


class Conditioning {
public:
	void onConditioning() {
		cout << "Conditioning was on. temperature = 20 degree" << endl;
	}

	void offConditioning() {
		cout << "conditioning was off" << endl;
	}
};

class Light {
public:

	void onLight() {
		cout << "Light was on" << endl;
	}

	void offLight() {
		cout << "Light was off" << endl;
	}
};

class SmartHomeFacade {
	TV* tv;
	Conditioning* conditioning;
	Light* light;
public:

	void watchTV() {
		tv->onTV();
		conditioning->onConditioning();
		light->onLight();
	}

	void turnOffEverything() {
		tv->offTV();
		conditioning->offConditioning();
		light->offLight();
	}
};

int main() {
	SmartHomeFacade smartHome;

	smartHome.watchTV();

	cout << endl;

	smartHome.turnOffEverything();
}