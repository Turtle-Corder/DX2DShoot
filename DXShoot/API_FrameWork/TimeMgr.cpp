#include "stdafx.h"
#include "TimeMgr.h"


CTimeMgr* CTimeMgr::m_pInstance = nullptr;
void CTimeMgr::Update_Time()
{
	m_dwPreTime = m_dwCurTime;
	m_dwCurTime = GetTickCount();
	m_dwDeltaTime = m_dwCurTime - m_dwPreTime;
}


CTimeMgr::CTimeMgr()
	: m_dwPreTime(GetTickCount()), m_dwCurTime(GetTickCount()), m_dwDeltaTime(0)
{
}


CTimeMgr::~CTimeMgr()
{
}
