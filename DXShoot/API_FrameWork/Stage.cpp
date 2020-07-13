#include "stdafx.h"
#include "Stage.h"
#include "Player.h"
#include "ObjMgr.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "TimeMgr.h"
#include "Monster.h"


CStage::CStage()
{
}


CStage::~CStage()
{
	Release();
}

void CStage::Initialize()
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Background.bmp", L"Background");

	CObj*	pObj = CAbstractFactory<CPlayer>::Create();
	CObjMgr::Get_Instance()->Add_Object(OBJID::PLAYER, pObj);

	//CObj*	pObj = CAbstractFactory<CMonster>::Create(400.f, 300.f);
	//CObjMgr::Get_Instance()->Add_Object(OBJID::MONSTER, pObj);
}

void CStage::Update()
{
	CTimeMgr::Get_Instance()->Update_Time();
	CObjMgr::Get_Instance()->Update();
}

void CStage::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CStage::Render(HDC _DC)
{
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Background");
	BitBlt(_DC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	CObjMgr::Get_Instance()->Render(_DC);
}

void CStage::Release()
{
}
