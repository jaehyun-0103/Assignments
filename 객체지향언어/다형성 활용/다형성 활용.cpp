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
		cout << "\n��ũ " << title << "�� ������\n";
		cout<<"��ũ " << title << "�� �߻���\n\n";
	}
};
class Fighter : public Weapon {
	string title;
public:
	void load(Bomb bomb) {
		this->title = bomb.getTitle();
	}
	void use() {
		cout << "\n������ " << title << "�� ������\n";
		cout << "������ " << title << "�� �߻���\n\n";
	}
};
class Missile : public Weapon {
	string title;
public:
	void load(Bomb bomb) {
		this->title = bomb.getTitle();
	}
	void use() {
		cout << "\n�̻��� " << title << "�� ������\n";
		cout << "�̻��� " << title << "�� �߻���\n\n";
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
		cout << "----���� ������ ����----\n";
		cout << "------------------------\n";
		cout << "1. ��ũ\n2. ������\n3. �̻���\n";
		cout << "\n������ ����(1~3) �׿� ���� : ";
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
			cout << "\n�����մϴ�.\n";
			exit(1);
		}
	}
};

int main() {
	Battleshop shop;
	Weapon* weapon;
	while (true) {
		weapon = shop.selectItem();			// ��ȯ ���� ���� UpCasting
		Bomb bomb("����ź(hydrogen bomb)");
		weapon->load(bomb);
		weapon->use();
	}
	return 0;
}