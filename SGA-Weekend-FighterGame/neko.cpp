#include "stdafx.h"
#include "neko.h"


//s
HRESULT neko::init(vector2D pos)
{
	character::init("����", pos, "nekoRightStop");

	_state = RIGHT_STOP;
	_isEnemyRight = true;
	
	//_pivot = Pivot::BOTTOM;

	//���� ���� ������
	_jumpPower = 0;
	_gravity = 0;
	_savePosY = this->_pos.y;
	_isJump = false;

	//Ű ���� ����
	_saveLastKey = key::END;	//�ƹ�Ű�� �ȴ��� END�� �ʱ�ȭ  ���ش�.

	//�ݹ� �Լ� ���
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((tagNekoState::ENUM)msg.data);
	});

	this->setScale(3.0, 3.0);

	this->setGravity(0);
	//116 ,179 , 144,225

	return S_OK;
}

void neko::release()
{
	character::release();
}

void neko::update()
{
	character::update();

	this->jumping();

	this->stateUpdate(_state);

	this->enemyPos();
}

void neko::render()
{
	character::render();

	char str[100];
	sprintf(str, "%d ,%d" ,(int)_pos.x, (int)_pos.y);
	TextOut(getMemDC(), 0, 20, str, strlen(str));
}


void neko::changeState(tagNekoState::ENUM state)
{
	switch (state)
	{
	case RIGHT_STOP:	//������ ��������
	{
		this->setAnimation("nekoRightStop");	//������ ������ ������ ����
	}
		break;
	case LEFT_STOP:		//���� ��������
	{
		this->setAnimation("nekoLeftStop");		//���� ������ ������ ����
	}
		break;
	case RIGHT_MOVE:	//������ �̵� ���� 
	{
		this->setAnimation("nekoRightMove");	//������ �̵����� ������ ����
	}
		break;
	case LEFT_MOVE:		//���� �̵� ����
	{
		this->setAnimation("nekoLeftMove");		//���� �̵����� ������ ���� 
	}
		break;
	case RIGHT_SIT:		//������ �ɱ� ����
	{
		this->setAnimation("nekoRightSit");		//������ �ɱ�� ������ ����
	}
		break;
	case LEFT_SIT:	//���� �ɱ� ����
	{
		this->setAnimation("nekoLeftSit");
	}
		break;
	case RIGHT_CHANGE_SIT :	//������ �������� ����
	{
		this->setAnimation("nekoRightChangeSit");		//������ �ɱ� ������� �����Ӻ���
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_SIT));	//�ɱ� ��� �����ӳ����� �ɱ�� ���º���
	}
	break;

	case LEFT_CHANGE_SIT :	//���� �������� ���� 
	{
		this->setAnimation("nekoLeftChangeSit");				//���� �ɴ� ������ ���
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_SIT));	//������ ������ ���� �ɱ���·� ��ȯ
	}
		break;

	case RIGHT_CHANGE_UP :	//������ �Ͼ�� ����
	{
		this->setAnimation("nekoRightChangeSitUp");		//������ �Ͼ�� ������ ���
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, RIGHT_STOP));	//������ ������ ������ ��������
	}
	break;

	case LEFT_CHAGNE_UP :	//���� �Ͼ�� ����
	{
		this->setAnimation("nekoLeftChangeSitUp");		//���� �Ͼ�� ������ ��� 
		this->_animation->setEndMessage(this, tagMessage("changeState", 0.0f, LEFT_STOP));	//������ ������ ���� ���� ����
	}
	break;

	case RIGHT_SIT_MOVE:	//������ �ɱ� �̵�
	{
		this->setAnimation("nekoRightSitMove");		//������ �ɱ� �̵����� ������ ��ȯ 
	}
	break;

	case LEFT_SIT_MOVE:		//���� �ɱ� �̵�
	{
		this->setAnimation("nekoLeftSitMove");		//���� �ɱ� �̵����� ������ ��ȯ 
	}
	break;
	
	case RIGHT_JUMP:							//������ ���� ���� 
	{
		this->setJump();						//����!
		this->setAnimation("nekoRightJump");	//������ ���� ���������� ��ȯ 
	}
		break;
	case LEFT_JUMP:								//���� ���� ����
	{
		this->setJump();						//����!
		this->setAnimation("nekoLeftJump");		//���� ���� ���������� ��ȯ 
	}
		break;
	
	}
	_state = state;

}

void neko::stateUpdate(tagNekoState::ENUM state)
{
	switch (state)
	{
	case tagNekoState::RIGHT_STOP:	//������ �⺻������ ��
	{
		//===================������ �̵����� ���� ����=================
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))
		{
			this->changeState(RIGHT_MOVE);	//������ �̵����� ���� ����
		}

		//========================�������� ���º���===================
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))
		{
			this->changeState(LEFT_MOVE);	//���� �̵����� ���� ����
		}
		//====================������ �ɱ� ������� ���� ����============
		if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))
		{
			this->changeState(RIGHT_CHANGE_SIT);	//������ �ɴ� ������� ���� ����
		}
		//=====================���� ���·� ��ȯ=====================
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))			//����Ű�� �ѹ� �����ٸ�
		{
			this->changeState(RIGHT_JUMP);			//������ ���� ���·� ��ȯ 
			_saveLastKey = END;
		}

		if (!_isEnemyRight)this->changeState(LEFT_STOP);		//���� ���ʿ� �ִٸ� ���� ���� �������·� ��ȯ
	}
	break;
	case LEFT_STOP:			//���� ���������� �� 
	{
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))		//���� Ű�� �ѹ� ������
		{
			this->changeState(LEFT_MOVE);			//���� �̵� ���·� ��ȯ
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))		//������ Ű�� �ѹ� ������
		{
			this->changeState(RIGHT_MOVE);			//������ �̵� ���·�  ��ȯ 
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))		//�Ʒ�Ű�� �ѹ� ������
		{
			this->changeState(LEFT_CHANGE_SIT);		//���� �ɴ� ��� ���·� ��ȯ 
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))		//����Ű�� �ѹ� ������
		{
			this->changeState(LEFT_JUMP);			//���� ���� ���·� ��ȯ 
			_saveLastKey = END;
		}

		if (_isEnemyRight)this->changeState(RIGHT_STOP);		//���� �����ʿ� �ִٸ� ���� ������ ���� ���·� ��ȯ
	}
	break;
	case RIGHT_MOVE:	//������ �̵� ����
	{
		//========================������ �̵�=====================
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))		//������ Ű ��� ������ �ִٸ� 
		{
			_pos.x += NEKOSPEED;								//���������� ��ǥ �̵�
			_saveLastKey = RIGHT;					//Ű ����
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))		//�Ʒ�Ű�� ������
		{
			this->changeState(RIGHT_SIT_MOVE);					//������ �ɱ� �̵� ����
		}
		//================���� �����ʿ� �ִٸ�=======================
		if (_isEnemyRight)
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))	//Ű���� �ն���
			{
				this->changeState(RIGHT_STOP);		//������ ��������
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))	//����Ű ������
			{
				this->changeState(RIGHT_JUMP);				//������ ���� �̵� ���·� ��ȯ 
			}
		}
		//================���� ���ʿ� �ִٸ�=======================
		else if (!_isEnemyRight)
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))	//Ű���� �ն���
			{
				this->changeState(LEFT_STOP);			//���� �������·� ��ȯ 
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))	//����Ű�� ������
			{
				this->changeState(LEFT_JUMP);			//���� ���� �̵� ���·� ��ȯ
			}
		}
	}
	break;
	case LEFT_MOVE:
	{
		//===========�������� �̵�========================
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))	//���� Ű�� ��� ������ �ִٸ�
		{
			_pos.x -= NEKOSPEED;							//�������� ��ǥ �̵�
			_saveLastKey = LEFT;					//Ű ����
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::DOWN]))	//�Ʒ� Ű�� �����ٸ�
		{
			this->changeState(LEFT_SIT_MOVE);				//���� �ɾ� �̵����� ���º�ȭ
		}
		//================���� �����ʿ� �ִٸ�=======================
		if (_isEnemyRight)
		{
			if(KEYMANAGER->isOnceKeyUp(keyList[key::LEFT])) //�����̵� Ű���� �ն��� 
			{
				this->changeState(RIGHT_STOP);				//������ �������·� ��ȯ
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))	//����Ű ������
			{
				this->changeState(RIGHT_JUMP);				//���� �̵� ���·� ��ȯ 
			}
		}
		//=================����  ���ʿ� �ִٸ�==============================
		else if (!_isEnemyRight)
		{
			if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))	//���� �̵�Ű���� �ն���
			{
				this->changeState(LEFT_STOP);			//���� �������·� ��ȯ 
			}
			if (KEYMANAGER->isOnceKeyDown(keyList[key::JUMP]))	//����Ű�� �ѹ� ������
			{
				this->changeState(LEFT_JUMP);			//���� ���� �̵� ���·� ��ȯ 
			}
		}
	}
	break;
	case RIGHT_SIT:	//�ɱ� ���¿��� 
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))	//�ɱ� Ű���� �ն���
		{
			this->changeState(RIGHT_CHANGE_UP);					//������ �븻���·� ���� ��ȯ
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))	//������ �̵�Ű�� ������
		{
			this->changeState(RIGHT_SIT_MOVE);				//������ �ɱ� �̵����·� ��ȯ
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))	//����Ű�� ������
		{
			this->changeState(LEFT_SIT_MOVE);				//���� �ɱ� �̵����·� ��ȯ 
		}
		
		if (!_isEnemyRight)this->changeState(LEFT_SIT);		//���� ���ʿ� �ִٸ� ���� �ɱ� ���·� ��ȯ 
	}
	break;
	case LEFT_SIT:			//���� �ɱ� ���� 
	{
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))		//�ɱ� Ű���� �ն���
		{
			this->changeState(LEFT_CHAGNE_UP);			//�Ͼ�� ���·� ��ȯ
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::LEFT]))		//���� Ű�� �ѹ� �����ٸ�
		{
			this->changeState(LEFT_SIT_MOVE);			//���� �ɾ� �̵����·� ��ȯ 
		}
		if (KEYMANAGER->isOnceKeyDown(keyList[key::RIGHT]))		//������ Ű��  �ѹ� �����ٸ� 
		{
			this->changeState(RIGHT_SIT_MOVE);			//������ �ɾ� �̵����·� ��ȯ 
		}

		if (_isEnemyRight)this->changeState(RIGHT_SIT);		//���� �����ʿ� �ִٸ� ������ �ɱ� ���·� ��ȯ
	}
	break;
	
	case RIGHT_CHANGE_SIT:
	{

	}
	break;

	case LEFT_CHANGE_SIT:
	{

	}
	break;

	case RIGHT_CHANGE_UP:
	{

	}
	break;

	case LEFT_CHAGNE_UP:
	{

	}
	break;

	case RIGHT_SIT_MOVE :	//������ �ɱ� �̵�����
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))	//������ Ű��� ������ 
		{
			this->_pos.x += NEKOSITSPEED;						//���������� �̵�
			_saveLastKey = RIGHT;					//Ű ����
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))		//������ Ű���� �ն���
		{
			if (_isEnemyRight)		//���� ���� �����ʿ� �ִٸ�
			{
				this->changeState(RIGHT_SIT);					//������ �ɱ� ���·� ��ȯ
			}
			else if (!_isEnemyRight)	//���� ���� ���ʿ� �ִٸ�
			{
				this->changeState(LEFT_SIT);					//���� �ɱ� ���·� ��ȯ 
			}
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))		//Ű���� �ն���
		{
			this->changeState(RIGHT_MOVE);		//������ �̵� ���·� ��ȯ
		}
	}
	break;
	
	case LEFT_SIT_MOVE :	//���� �ɱ� �̵�
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))	//���� Ű ��� ������ ������
		{
			this->_pos.x -= NEKOSITSPEED;					//�������� ��ǥ �̵�
			_saveLastKey = LEFT;					//Ű ����
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))	//���� Ű���� ���� ���ٸ� 
		{
			if (_isEnemyRight)						//���� �����ʿ� �ִٸ�
			{
				this->changeState(RIGHT_SIT);	//������ �ɴ� ���·� ��ȯ 
			}
			else if (!_isEnemyRight)				//���� ���ʿ� �ִٸ�
			{
				this->changeState(LEFT_SIT);	//���� �ɴ� ���·� ��ȯ 
			}
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::DOWN]))	//�Ʒ� Ű���� �ն��ٸ�
		{
			this->changeState(LEFT_MOVE);		//���� �̵����·�  ��ȯ
		}
	
	}
	break;

	case RIGHT_JUMP:	//������ ���ڸ� ���� ����
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))	//������ Ű ��� ������ 
		{
			this->_pos.x += NEKOSPEED;						//���������� ��ǥ �̵�
			_saveLastKey = RIGHT;					//Ű ����
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))	//���� Ű ��� ������
		{
			this->_pos.x -= NEKOSPEED;						//�������� ��ǥ �̵�
			_saveLastKey = LEFT;					//Ű ����
		}

		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))	//������ Ű���� �ն��ٸ� 
		{
			_saveLastKey = END;								//Ű ���� ���� 
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))	//���� Ű���� �ն��ٸ� 
		{
			_saveLastKey = END;								//���� Ű ���� ����  
		}
	}
	break;
	case LEFT_JUMP:		//���� ���ڸ� ���� ����
	{
		if (KEYMANAGER->isStayKeyDown(keyList[key::RIGHT]))	//������ Ű ��� ������ 
		{
			this->_pos.x += NEKOSPEED;						//���������� ��ǥ �̵�
			_saveLastKey = RIGHT;					//Ű ����
		}
		if (KEYMANAGER->isStayKeyDown(keyList[key::LEFT]))	//���� Ű ��� ������
		{
			this->_pos.x -= NEKOSPEED;						//�������� ��ǥ �̵�
			_saveLastKey = LEFT;					//Ű ����
		}

		if (KEYMANAGER->isOnceKeyUp(keyList[key::RIGHT]))	//������ Ű���� �ն��ٸ� 
		{
			_saveLastKey = END;								//Ű ���� ���� 
		}
		if (KEYMANAGER->isOnceKeyUp(keyList[key::LEFT]))	//���� Ű���� �ն��ٸ� 
		{
			_saveLastKey = END;								//���� Ű ���� ����  
		}
	}
	break; 
	
	}
}

void neko::enemyPos()
{
	if (this->_pos.x > _enemy->_pos.x && _isEnemyRight)			//�� x��ǥ���� ��뺸�� ũ�ٸ� 
	{
		_isEnemyRight = false;						//�����ġ �Ұ� false 
	}
	else if (this->_pos.x < _enemy->_pos.x && !_isEnemyRight)	//��	 x��ǥ���� ��뺸�� �۴ٸ� 
	{
		_isEnemyRight = true;						//�� ��ġ �Ұ� true
	}

}

void neko::jumping()
{
	if (!_isJump) return;								//���� ���¶�� �������� ��������

	_pos.y -= _jumpPower;								//y���� ���� �Ŀ���ŭ ����
	_jumpPower -= _gravity;								//���� �Ŀ����� �߷°���ŭ ��� ����

	if (_savePosY <= _pos.y)							//���� ���̺� �����Ǻ��� �÷��̾��� ��ǥ�� Ŀ������ �ϸ� 
	{													//�װ� ���� �����ߴٴ� �Ŵϱ� 

		_isJump = false;								//���� ���� �Ұ� false��
		_pos.y = _savePosY;								//y��ǥ ���� ������ saveY��ǥ ������ �ʱ�ȭ 

		if (_state == RIGHT_JUMP || _state == LEFT_JUMP)	//���� ���¿��ٸ�
		{
			if (_isEnemyRight)							//���� ��밡 �����ʿ� �ִٸ� 
			{
				if(_saveLastKey == END)this->changeState(RIGHT_STOP);			//�������� ����Ű�� ������ ������ �������·� ��ȯ
				else if (_saveLastKey == RIGHT)this->changeState(RIGHT_MOVE);	//�������� ����Ű�� �������̶�� �������̵����·κ�ȯ
				else if (_saveLastKey == LEFT)this->changeState(LEFT_MOVE);		//�������� ����Ű�� �����̶�� ���� �̵����·� ��ȯ
			}	
			else										//���� ��밡 ���ʿ�  �ִٸ� 
			{
				if (_saveLastKey == END)this->changeState(LEFT_STOP);			//�������� ����Ű�� ������ ������ �������·� ��ȯ
				else if (_saveLastKey == RIGHT)this->changeState(RIGHT_MOVE);	//�������� ����Ű�� �������̶�� �������̵����·κ�ȯ
				else if (_saveLastKey == LEFT)this->changeState(LEFT_MOVE);		//�������� ����Ű�� �����̶�� ���� �̵����·� ��ȯ
			}				
		}
	}
}

