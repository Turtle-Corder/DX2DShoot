#include "stdafx.h"
#include "Monster.h"
#include "ObjMgr.h"
#include "ScrollMgr.h"
#include "KeyMgr.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
	Release();
}

HRESULT CMonster::Initialize()
{
	//m_tInfo.fX = 400.f;
	//m_tInfo.fY = 400.f;

	//m_tInfo.iCX = 300;
	//m_tInfo.iCY = 300;

	m_fSpeed = 1.f;

	m_eGroup = GROUPID::OBJECT;

	return S_OK;
}

int CMonster::Update()
{
	if (m_bDead)
		return OBJ_DEAD;


	Update_Rect();
	return OBJ_NOEVENT;
}

void CMonster::Late_Update()
{

}

void CMonster::Render(HDC _DC)
{

}

void CMonster::Release()
{
}
