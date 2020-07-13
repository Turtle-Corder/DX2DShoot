#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
	: m_fSpeed(0.f), m_bDead(false), m_fAngle(0.f), m_pTarget(nullptr)
	, m_eGroup(GROUPID::END)
{
	ZeroMemory(&m_tInfo, sizeof(m_tInfo));
}


CObj::~CObj()
{
}

void CObj::Update_Rect()
{
	for (int iCnt = 0; iCnt < 4; ++iCnt)
	{
		D3DXVec3TransformCoord(&m_vProcess[iCnt], &m_vOrigin[iCnt], &m_tInfo.matWorld);
	}
}

