#pragma once
#ifndef __TIMEMGR_H__
#define __TIMEMGR_H__


class CTimeMgr
{
public:
	void Update_Time();

	DWORD Get_Time()		{ return m_dwCurTime; }
	DWORD Get_DeltaTime()	{ return m_dwDeltaTime; }


public:
	static CTimeMgr* Get_Instance()
	{
		if (!m_pInstance)
			m_pInstance = new CTimeMgr;

		return m_pInstance;
	}

	static void Destroy_Instance()
	{
		SAFE_DELETE(m_pInstance);
	}


private:
	CTimeMgr();
	~CTimeMgr();


private:
	static CTimeMgr* m_pInstance;

	DWORD m_dwPreTime;
	DWORD m_dwCurTime;
	DWORD m_dwDeltaTime;
};

#endif // !__TIMEMGR_H__
