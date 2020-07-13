#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet()
{
}


CBullet::~CBullet()
{
	Release();
}

HRESULT CBullet::Initialize()
{
	m_tInfo.vSize = { 5.f, 5.f, 0.f };
	m_tInfo.vDir = { 0.f, -1.f, 0.f };
	m_tInfo.vLook = { 1.f, 0.f, 0.f };

	ZeroMemory(m_vOrigin, sizeof(m_vOrigin));

	m_fSpeed = 4.f;

	m_eGroup = GROUPID::OBJECT;

	float fHalfCX = m_tInfo.vSize.x * 0.5f;
	float fHalfCY = m_tInfo.vSize.y * 0.5f;

	m_vOrigin[0] = { -fHalfCX, -fHalfCY, 0.f };
	m_vOrigin[1] = { fHalfCX, -fHalfCY, 0.f };
	m_vOrigin[2] = { fHalfCX, fHalfCY, 0.f };
	m_vOrigin[3] = { -fHalfCX, fHalfCY, 0.f };

	return S_OK;
}

int CBullet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;

	D3DXMATRIX matTrans;
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f);
	m_tInfo.matWorld = matTrans;

	Update_Rect();
	return OBJ_NOEVENT;
}

void CBullet::Late_Update()
{
	if (MAP_STARTX >= m_tInfo.vPos.x || MAP_ENDX <= m_tInfo.vPos.x 
		|| MAP_STARTY >= m_tInfo.vPos.y || MAP_ENDY <= m_tInfo.vPos.y)
		m_bDead = true;
}

void CBullet::Render(HDC _DC)
{
	Ellipse(_DC, (int)m_vProcess[0].x, (int)m_vProcess[0].y, (int)m_vProcess[2].x, (int)m_vProcess[2].y);
}

void CBullet::Release()
{
}
