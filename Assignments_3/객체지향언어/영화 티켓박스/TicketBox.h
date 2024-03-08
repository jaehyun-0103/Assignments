#ifndef TICKETBOX_H
#define TICKETBOX_H
// 추가 기능 4
#define TICKETBOX_MANAGER_PWD "admin"

class TicketBox {
public:
	virtual Screen* selectMenu() { return NULL; } // 상영관 선택 메뉴 ( 1관, 2관, 3관)
	void Initialize() {}
};

class TUKoreaTBox : public TicketBox {
	EuropeScreen* pEuropeScreen;
	AsiaScreen* pAsiaScreen;
	PremiumScreen* pPremiumScreen;
public:
	TUKoreaTBox();
	~TUKoreaTBox();
	Screen* selectMenu();
	void Initialize();

	// 추가 기능 4
	void Manage();
};
#endif