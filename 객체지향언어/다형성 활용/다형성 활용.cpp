#include <iostream>
#include <string>
using namespace std;

class Bomb {
	string title;
public:
	Bomb(){}
	Bomb(string title) { this->title = title; }
	string getTitle() { return title; }
};

class Weapon {
public:
	virtual void load(Bomb bomb) = 0;
	virtual void use() = 0;
};
class Tank : public Weapon {
	string title;
public:
	void load(Bomb bomb) {
		this->title = bomb.getTitle();
	}
	void use() {
		cout << "\n탱크 " << title << "을 적재함\n";
		cout<<"탱크 " << title << "을 발사함\n\n";
	}
};
class Fighter : public Weapon {
	string title;
public:
	void load(Bomb bomb) {
		this->title = bomb.getTitle();
	}
	void use() {
		cout << "\n전투기 " << title << "을 적재함\n";
		cout << "전투기 " << title << "을 발사함\n\n";
	}
};
class Missile : public Weapon {
	string title;
public:
	void load(Bomb bomb) {
		this->title = bomb.getTitle();
	}
	void use() {
		cout << "\n미사일 " << title << "을 적재함\n";
		cout << "미사일 " << title << "을 발사함\n\n";
	}
};

class shop {
public:
	virtual Weapon* selectItem() = 0;
};

class Battleshop : public shop {
	int choose;
	Weapon* chosen;
public:
	Weapon* selectItem() {
		cout << "------------------------\n";
		cout << "----무기 아이템 선택----\n";
		cout << "------------------------\n";
		cout << "1. 탱크\n2. 전투기\n3. 미사일\n";
		cout << "\n아이템 선택(1~3) 그외 종료 : ";
		cin >> choose;
		if (choose == 1) {
			return new Tank;
		}
		else if (choose == 2) {
			return new Fighter;
		}
		else if (choose == 3) {
			return new Missile;
		}
		else {
			cout << "\n종료합니다.\n";
			exit(1);
		}
	}
};

int main() {
	Battleshop shop;
	Weapon* weapon;
	while (true) {
		weapon = shop.selectItem();			// 반환 값을 통한 UpCasting
		Bomb bomb("수소탄(hydrogen bomb)");
		weapon->load(bomb);
		weapon->use();
	}
	return 0;
}