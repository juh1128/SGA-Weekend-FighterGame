#pragma once
#include <vector>

class image;

typedef void(*CALLBACK_FUNCTION)(void);
typedef void(*CALLBACK_FUNCTION_PARAMETER)(void*);
//���̵� �����ʹ� ������ ����ų �� �ִ� == ������ ���� �� �ִ�
//����ֱ� ������ ���� ������ �������� �ʿ䰡 �ִ�



class animation
{
public:
	typedef vector<POINT> vFrameList;
	typedef vector<int> vPlayList;

private:
	int			_frameNum;			//������ �ѹ�
	int			_maxFrameX;
	int			_maxFrameY;

	vFrameList	_frameList;			//�ִϸ��̼� ������ ����Ʈ
	vPlayList	_playList;			//�ִϸ��̼� �÷��� �ε��� ����Ʈ

	int			_frameWidth;		//����(������ ũ��)
	int			_frameHeight;		//����

	BOOL		_loop;				//���� ����

	float		_frameUpdateSec;	//������ ���� 
	float		_elapsedSec;

	DWORD		_nowPlayIndex;		//��� ������ �ε���
	BOOL		_play;

	image*		_img;				//�ִϸ��̼��� ����� �̹���
	RECT		_collisionRect;		//�ִϸ��̼��� �浹��Ʈ

	void* _obj;
	CALLBACK_FUNCTION _callbackFunction;
	CALLBACK_FUNCTION_PARAMETER _callbackFunctionParameter;

	tagMessage _endMessage;
	gameObject* _messageTarget;

public:
	animation();
	virtual ~animation();

	//           �̹��� ��ü ���� ����      �� ��� ����    ����
	HRESULT init(int totalW, int totalH, int frameW, int frameH);
	void release(void);

	void setDefPlayFrame(BOOL reverse = FALSE, BOOL loop = FALSE);
	void setDefPlayFrame(BOOL reverse, BOOL loop, CALLBACK_FUNCTION cbFunction);
	void setDefPlayFrame(BOOL reverse, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj);

	void setPlayFrame(int* playArr, int arrLen, BOOL loop = FALSE);
	void setPlayFrame(int* playArr, int arrLen, BOOL loop, CALLBACK_FUNCTION cbFunction);
	void setPlayFrame(int* playArr, int arrLen, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj);

	void setPlayFrame(int start, int end, BOOL reverse = FALSE, BOOL loop = FALSE);
	void setPlayFrame(int start, int end, BOOL reverse, BOOL loop, CALLBACK_FUNCTION cbFunction);
	void setPlayFrame(int start, int end, BOOL reverse, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj);

	//�ִϸ��̼��� FrameUpdateSec�� �����Ѵ�. 
	//1�� �� �� �������� ���� ������ �Է� �޾Ƽ�, 1������ �Ѿ�µ� �ɸ��� �ð��� �������� ���.
	void setFPS(int framePerSec);

	//setFPS�� ���� ���ǵ�� �ִϸ��̼� �������� ������Ʈ�Ѵ�. (�ʼ�~!)
	void frameUpdate();

	void start(void);
	void stop(void);
	void pause(void);
	void resume(void);

	inline BOOL isPlay(void) { return _play; }
	inline POINT getFramePos(void) { return _frameList[_playList[_nowPlayIndex]]; }
	inline int getFrameWidth(void) { return _frameWidth; }
	inline int getFrameHeight(void) { return _frameHeight; }

	//���� �߰��� ��
	//���� �ִϸ��̼����� ������ ���������� ������ ��ȣ�� �����´�.
	inline int getFrame(void) { return _nowPlayIndex; }
	//��ü ��������Ʈ ��Ʈ ���ؿ��� ���� �������� X��ǥ �ε����� �����´�.
	inline int getFrameX(void) { return _playList[_nowPlayIndex] % _maxFrameX; }
	//��ü ��������Ʈ ��Ʈ ���ؿ��� ���� �������� Y��ǥ �ε����� �����´�.
	inline int getFrameY(void) { return _playList[_nowPlayIndex] / _maxFrameX; }

	//�ִϸ��̼� ���� �� ���� �̹��� ����
	void setImage(image* img);
	image* getImage();

	//�ִϸ��̼��� ���� �� ������ Ÿ�ٿ��� �޽����� �����Ѵ�.
	void setEndMessage(gameObject* target, tagMessage msg);

	//----- �ִϸ��̼� ó���� Ư���ϰ� �ϰ� ���� �� -----

	//�ִϸ��̼��� �������� 1�����Ӹ� ������Ų��.
	void addFrame(void);
	//�ִϸ��̼� �������� �����Ѵ�.
	void setFrame(int frame);
	//�ִϸ��̼��� �浹������ ���� �����Ѵ�.
	void setCollisionRect(RECT rc)
	{
		_collisionRect = rc;
	}
	RECT getCollisionRect()
	{
		return _collisionRect;
	}
};

