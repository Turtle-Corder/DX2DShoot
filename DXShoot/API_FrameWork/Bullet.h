#pragma once

#ifndef __BULLET_H__
#define __BULLET_H__

#include "Obj.h"
class CBullet : public CObj
{
public:
	CBullet();
	virtual ~CBullet();

public:
	virtual HRESULT Initialize() override;
	virtual int Update() override;
	virtual void Late_Update();
	virtual void Render(HDC _DC) override;
	virtual void Release() override;

};


#endif // !__BULLET_H__
