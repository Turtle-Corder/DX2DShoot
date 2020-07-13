#pragma once

#ifndef __OBJ_H__
#define __OBJ_H__


class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	virtual HRESULT Initialize() = 0;
	virtual int Update() = 0;
	virtual void Late_Update() = 0;
	virtual void Render(HDC _DC) = 0;
	virtual void Release() = 0;

public:
	void Set_Pos(float _x, float _y) { m_tInfo.vPos.x = _x; m_tInfo.vPos.y = _y; }
	void Set_PosX(float _x) { m_tInfo.vPos.x = _x; }
	void Set_PosY(float _y) { m_tInfo.vPos.y = _y; }
	void Set_Dead() { m_bDead = true; }
	void Set_Angle(float _fAngle) { m_fAngle = _fAngle; }
	void Set_Target(CObj* _pTarget) { m_pTarget = _pTarget; }

public:
	const INFO& Get_Info() const { return m_tInfo; }
	const GROUPID::ID Get_GroupID() const { return m_eGroup; }

protected:
	void Update_Rect();

protected:
	INFO	m_tInfo;

	D3DXVECTOR3 m_vOrigin[4];
	D3DXVECTOR3 m_vProcess[4];

	float	m_fSpeed;
	float	m_fAngle;

	bool	m_bDead;

	CObj*	m_pTarget;

	GROUPID::ID		m_eGroup;
};


#endif // !__OBJ_H__

