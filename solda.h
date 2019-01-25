#include "unite.cpp"

// extern Unite *AllSolda[12];

class Fantassin: public Unite {
public:
	Fantassin(): Unite("Fant",10,10,4) {
		Porte[0] = 1;
		Porte[1] = 0;
		Porte[2] = 0;
		if (Camp == 0) {
			Post[0] = 1;
		}
		if(Camp == 1) {
			Post[11] = 1;
		}
	}
	~Fantassin(){}

	virtual	void avancer() {
		if(Camp == 0) {
			if(Post[Position+1] == 0){
				Post[Position] = 0;
				Position ++;
				Post[Position] = 1;
			}
			else std::cerr << "You can't move forward!" << '\n';
		}
		if(Camp == 1) {
			if(Post[Position-1] == 0) {
				Post[Position] = 0;
				Position --;
				Post[Position] = 1;
			}
			else std::cerr << "You can't move forward!" << '\n';
		}
	}
};

class Archer: public Unite {
public:
	Archer(): Unite("Arch",12,8,3) {
		Porte[0] = 1;
		Porte[1] = 2;
		Porte[2] = 3;
		if (Camp == 0) {
			Post[0] = 1;
		}
		if(Camp == 1) {
			Post[11] = 1;
		}
	}

	~Archer() {}

	virtual	void avancer() {
		if(Camp == 0) {
			if(Post[Position+1] == 0){
				Post[Position] = 0;
				Position ++;
				Post[Position] = 1;
			}
			else std::cerr << "You can't move forward!" << '\n';
		}
		if(Camp == 1) {
			if(Post[Position-1] == 0) {
				Post[Position] = 0;
				Position --;
				Post[Position] = 1;
			}
			else std::cerr << "You can't move forward!" << '\n';
		}
	}
};

class Catapulte: public Unite {
public:
	Catapulte(): Unite("Cata",20,12,6) {
		Porte[0] = 2;
		Porte[1] = 3;
		Porte[2] = 4;
		if (Camp == 0) {
			Post[0] = 1;
		}
		if(Camp == 1) {
			Post[11] = 1;
		}
	}
	~Catapulte() {}

	virtual	void avancer() {
		if(Camp == 0) {
			if(Post[Position+1] == 0){
				Post[Position] = 0;
				Position ++;
				Post[Position] = 1;
			}
			else std::cerr << "You can't move forward!" << '\n';
		}
		if(Camp == 1) {
			if(Post[Position-1] == 0) {
				Post[Position] = 0;
				Position --;
				Post[Position] = 1;
			}
			else std::cerr << "You can't move forward!" << '\n';
		}
	}
};
