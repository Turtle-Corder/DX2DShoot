#pragma once

#ifndef __PLAYER_H__
#define __PLAYER_H__


#include "Obj.h"
class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();


	virtual HRESULT Initialize() override;
	virtual int Update() override;
	virtual void Late_Update();
	virtual void Render(HDC _DC) override;
	virtual void Release() override;



private:
	void Key_Check();
	
	void Move_Check();
	void Fire_Check();

	void Update_Fire();


private:
	POINT			m_tPosin;
	float			m_fPosinDis;

	bool			m_bCanFire;
	DWORD			m_dwNextFireTime;
	DWORD			m_dwFireDelay;
};


#endif // !__PLAYER_H__
