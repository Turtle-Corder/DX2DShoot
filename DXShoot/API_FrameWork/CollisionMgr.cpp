#include "stdafx.h"
#include "CollisionMgr.h"
#include "obj.h"


CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}

//void CCollisionMgr::Collision_Rect(list<CObj*>& _Dst, list<CObj*>& _Src)
//{
//	RECT rc = {};
//
//	for (auto& Dst : _Dst)
//	{
//		for (auto& Src : _Src)
//		{
//			if (IntersectRect(&rc, &Dst->Get_Rect(), &Src->Get_Rect()))
//			{
//				Dst->Set_Dead();
//				Src->Set_Dead();
//			}
//		}
//	}
//}

void CCollisionMgr::Collision_RectEx(list<CObj*>& _Dst, list<CObj*>& _Src)
{
	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			float fX = 0.f, fY = 0.f;
			if (Check_Rect(Dst, Src, &fX, &fY))
			{
				if (fX < fY)	// ÁÂ¿ì
				{
					if(Dst->Get_Info().matWorld._41 > Src->Get_Info().matWorld._41)
						Src->Set_PosX(-fX);
					else
						Src->Set_PosX(fX);
				}
				else // »óÇÏ
				{
					if (Dst->Get_Info().matWorld._42 > Src->Get_Info().matWorld._42)
						Src->Set_PosY(-fY);
					else
						Src->Set_PosY(fY);
				}
			}
		}
	}
}

void CCollisionMgr::Collision_Sphere(list<CObj*>& _Dst, list<CObj*>& _Src)
{
	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (Check_Sphere(Dst, Src))
			{
				Dst->Set_Dead();
				Src->Set_Dead();
			}
		}
	}
}

bool CCollisionMgr::Check_Sphere(CObj* _Dst, CObj* _Src)
{
	//float fX = _Dst->Get_Info().matWorld._41 - _Src->Get_Info().matWorld._41;
	//float fY = _Dst->Get_Info().matWorld._42 - _Src->Get_Info().matWorld._42;
	//float fDia = sqrtf(fX * fX + fY * fY);

	//float fDis = (float)((_Dst->Get_Info().vSize.x * _Dst->Get_Info().matWorld._11
	//	+ _Src->Get_Info().vSize.x * _Src->Get_Info().matWorld._11) * 0.5f);

	//if (fDia <= fDis)
	//	return true;
	return false;
}

bool CCollisionMgr::Check_Rect(CObj* _Dst, CObj* _Src, float* _x, float* _y)
{
	//float fX = (float)((_Dst->Get_Info().matWorld._41 * _Dst->Get_Info().vSize.x 
	//				  + _Src->Get_Info().matWorld._41 * _Src->Get_Info().vSize.x) * 0.5f);
	//float fY = (float)((_Dst->Get_Info().matWorld._42 * _Dst->Get_Info().vSize.y
	//				  + _Src->Get_Info().matWorld._42 * _Src->Get_Info().vSize.y) * 0.5f);

	//float fXDis = abs(_Dst->Get_Info().fX - _Src->Get_Info().fX);
	//float fYDis = abs(_Dst->Get_Info().fY - _Src->Get_Info().fY);

	//if (fX > fXDis && fY > fYDis)
	//{
	//	*_x = fX - fXDis;
	//	*_y = fY - fYDis;
	//	return true;
	//}
	return false;
}
