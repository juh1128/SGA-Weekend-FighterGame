#pragma once
#include "gameNode.h"

class playGround : public gameNode
{
private:

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void setupGuenhwa();
	void setupDongjin();
	void setupHyunjin();
	void setupSiyeong();
	void setupSoonyu();
	void setupYuhoon();
	void setupHyeongjoon();
	void setupSunghoon();
	void setupTaesung();
	void setupYongjae();
	void setupYoonsam();
	void setupHalim();

	playGround();
	~playGround();
};

