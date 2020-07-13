#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "ObjMgr.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"
#include "TimeMgr.h"


CPlayer::CPlayer()
	: m_fPosinDis(0.f)
	, m_bCanFire(true), m_dwFireDelay(0)
{
	ZeroMemory(&m_tPosin, sizeof(m_tPosin));
}


CPlayer::~CPlayer()
{
	Release();
}

HRESULT CPlayer::Initialize()
{
	m_tInfo.vPos =	{ (float)((MAPCX >> 1) + MAP_STARTX), (float)(MAP_ENDY - 100), 0.f };
	m_tInfo.vSize = { 20.f, 20.f, 0.f };
	m_tInfo.vDir =	{ 0.f, -1.f, 0.f };
	m_tInfo.vLook = { 1.f, 0.f, 0.f };

	ZeroMemory(m_vOrigin, sizeof(m_vOrigin));

	m_fSpeed = 2.f;
	m_fPosinDis = 100.f;

	m_eGroup = GROUPID::OBJECT;

	float fHalfCX = m_tInfo.vSize.x * 0.5f;
	float fHalfCY = m_tInfo.vSize.y * 0.5f;

	m_vOrigin[0] = { -fHalfCX, -fHalfCY, 0.f };
	m_vOrigin[1] = { fHalfCX, -fHalfCY, 0.f };
	m_vOrigin[2] = { fHalfCX, fHalfCY, 0.f };
	m_vOrigin[3] = { -fHalfCX, fHalfCY, 0.f };

	m_dwFireDelay = 50;

	return S_OK;
}

int CPlayer::Update()
{
	D3DXMATRIX matTrans;
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f);
	m_tInfo.matWorld = matTrans;

	Update_Rect();
	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
	Key_Check();
	Update_Fire();
}

void CPlayer::Render(HDC _DC)
{
	//MoveToEx();
	//Rectangle(_DC, (int)m_vProcess[0].x, (int)m_vProcess[0].y, (int)m_vProcess[2].x, (int)m_vProcess[2].y);
	Ellipse(_DC, (int)m_vProcess[0].x, (int)m_vProcess[0].y, (int)m_vProcess[2].x, (int)m_vProcess[2].y);
}

void CPlayer::Release()
{
}

void CPlayer::Key_Check()
{
	Move_Check();
	Fire_Check();
}

void CPlayer::Move_Check()
{
	if (CKeyMgr::Get_Instance()->Key_Pressing('J'))
	{
		if (CKeyMgr::Get_Instance()->Key_Pressing('I'))
		{
			m_tInfo.vDir = { -1.f, -1.f, 0.f };
		}
		else if (CKeyMgr::Get_Instance()->Key_Pressing('K'))
		{
			m_tInfo.vDir = { -1.f, 1.f, 0.f };
		}
		else
		{
			m_tInfo.vDir = { -1.f, 0.f, 0.f };
		}
	}

	else if (CKeyMgr::Get_Instance()->Key_Pressing('L'))
	{
		if (CKeyMgr::Get_Instance()->Key_Pressing('I'))
		{
			m_tInfo.vDir = { 1.f, -1.f, 0.f };
		}
		else if (CKeyMgr::Get_Instance()->Key_Pressing('K'))
		{
			m_tInfo.vDir = { 1.f, 1.f, 0.f };
		}
		else
		{
			m_tInfo.vDir = { 1.f, 0.f, 0.f };
		}
	}

	else if (CKeyMgr::Get_Instance()->Key_Pressing('I'))
	{
		m_tInfo.vDir = { 0.f, -1.f, 0.f };
	}
	else if (CKeyMgr::Get_Instance()->Key_Pressing('K'))
	{
		m_tInfo.vDir = { 0.f, 1.f, 0.f };
	}
	else
	{
		m_tInfo.vDir = { 0.f, 0.f, 0.f };
	}

	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;
}

void CPlayer::Fire_Check()
{
	if (CKeyMgr::Get_Instance()->Key_Pressing('Z'))
	{
		if (m_bCanFire)
		{
			m_bCanFire = !m_bCanFire;
			m_dwNextFireTime = CTimeMgr::Get_Instance()->Get_Time() + m_dwFireDelay;

			// UNDONE : 일단 가운데 때려
			CObj* pObj = CAbstractFactory<CBullet>::Create(m_tInfo.vPos.x, m_tInfo.vPos.y);
			CObjMgr::Get_Instance()->Add_Object(OBJID::PLAYER_BULLET, pObj);
		}
	}
}

void CPlayer::Update_Fire()
{
	if (!m_bCanFire)
	{
		if (CTimeMgr::Get_Instance()->Get_Time() >= m_dwNextFireTime)
		{
			m_bCanFire = !m_bCanFire;
		}
	}
}
