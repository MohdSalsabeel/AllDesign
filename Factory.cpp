class Vehicle {
public:
	virtual void printVehicle() = 0;
};

class TwoWheller :public Vehicle {
public:
	void printVehicle() {
		cout << "It is two wheller " << endl;
	}
};


class FourWheller : public Vehicle {
public:
	void printVehicle() {
		cout << "It is four wheller " << endl;
	}
};

class FactoryVehicle {

public:
	static Vehicle* getVehicle(string vehicleType) {
		if (vehicleType == "Two") {
			return new TwoWheller();
		}
		else if (vehicleType == "Four") {
			return new FourWheller();
		}
	}
};


int main() {
string name;
	cin >> name;
	FactoryVehicle* fact = new FactoryVehicle();
	fact->getVehicle(name)->printVehicle();

}
