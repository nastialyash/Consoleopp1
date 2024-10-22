

#include <iostream>
using namespace std;
class people {
	string PIB;
public:
	
	
	void Show() {
		cout << "PIB " << PIB << endl;
		
	}
	const string getName() const {
		return PIB;
		}
	void copy(const people& other ) {
		PIB = other.PIB;
	}
	void showInfo() const {
		cout << "Human  " << PIB << endl;
	}
	
};
class kvart {
private:
	people** num;  
	int numresident;
public:
	kvart(int numResidents = 0) : numresident(numResidents) {
		num = new people * [numResidents];  
		for (int i = 0; i < numResidents; ++i) {
			num[i] = nullptr;  
		}
	}
	kvart(const kvart& other) {
		copy(other);  
	}

	void copy(const kvart& other) {
		numresident = other.numresident;
		num = new people * [numresident];
		for (int i = 0; i < numresident; ++i) {
			if (other.num[i]) {
				num[i] = new people(*other.num[i]);
			}
			else {
				num[i] = nullptr;
			}
		}
	}
	void showInfo() const {
		cout << "Kvart with " << numresident << " people" << endl;
		for (int i = 0; i < numresident; ++i) {
			if (num[i]) {
				num[i]->showInfo();
			}
			else {
				cout << "No " << endl;
			}
		}
	}
	
	void clear() {
		for (int i = 0; i < numresident; ++i) {
			delete num[i];  
		}
		delete[] num;  
	}
	~kvart() {
		clear();
	}
};
class home {
private:
	kvart* apartments;  
	int numApartments;
	home(const home& other) {
		copy(other);  
	}
	void copy(const home& other) {
		numApartments = other.numApartments;
		apartments = new kvart[numApartments];
		for (int i = 0; i < numApartments; ++i) {
			apartments[i] = other.apartments[i];  
		}
	}
	void showInfo() const {
		cout << "House with " << numApartments << " kvart:" << endl;
		for (int i = 0; i < numApartments; ++i) {
			cout << "Kvart " << i + 1 << ":" << endl;
			apartments[i].showInfo();
			cout << "--------------------------" << endl;
		}
	}
	void clear() {
		delete[] apartments;  
	}
	~home() {
		clear();
	}
	
};
int main()
{
	home Home();
	


}
