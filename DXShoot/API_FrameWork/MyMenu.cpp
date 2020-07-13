#include "stdafx.h"
#include "MyMenu.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "ObjMgr.h"


CMyMenu::CMyMenu()
{
}


CMyMenu::~CMyMenu()
{
	Release();
}

void CMyMenu::Initialize()
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Menu/menu.bmp", L"Menu");
}

void CMyMenu::Update()
{
	CObjMgr::Get_Instance()->Update();
}

void CMyMenu::Late_Update()
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
		CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::STAGE);
}

void CMyMenu::Render(HDC _DC)
{
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Menu");
	BitBlt(_DC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	CObjMgr::Get_Instance()->Render(_DC);
}

void CMyMenu::Release()
{
	CObjMgr::Get_Instance()->Delete_ID(OBJID::UI);
}
