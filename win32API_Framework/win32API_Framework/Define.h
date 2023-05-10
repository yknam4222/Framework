#pragma once

extern HWND g_hWnd;

const int COUNT = 128;

#define WIDTH 1280
#define HEIGHT 720

const unsigned char KEYID_UP = 0x00000001;
const unsigned char KEYID_DOWN = 0x00000002;
const unsigned char KEYID_LEFT = 0x00000004;
const unsigned char KEYID_RIGHT = 0x00000008;
const unsigned char KEYID_RETURN = 0x00000010;
const unsigned char KEYID_SPACE = 0x00000020;
const unsigned char KEYID_ESCAPE = 0x00000040;
const unsigned char KEYID_CONTROL = 0x00000080;

#define Single(T)								\
public:												 \
	static T* GetInstance()					 \
	{													 \
		static T* instance;	\
		if(instance == nullptr)\
instance = new T;\
		return instance;						\
	}													 \
private:											 \
	T(const T&) = delete;					  \
	T& operator = (const T&) = delete;

#define GetSingle(T) (T::GetInstance())

