#include "stdafx.h"
#include "ObjMgr.h"
#include "Obj.h"
#include "CollisionMgr.h"

CObjMgr* CObjMgr::m_pInstance = nullptr;

CObjMgr::CObjMgr()
{
}


CObjMgr::~CObjMgr()
{
	Release();
}

void CObjMgr::Add_Object(OBJID::ID _eID, CObj * _pObj)
{
	m_listObj[_eID].emplace_back(_pObj);
}

void CObjMgr::Update()
{
	for (int i = 0; i < OBJID::END; ++i)
	{
		auto& iter = m_listObj[i].begin();
		for (; iter != m_listObj[i].end(); )
		{
			int iEvent = (*iter)->Update();
			if (OBJ_DEAD == iEvent)
			{
				SAFE_DELETE(*iter);
				iter = m_listObj[i].erase(iter);
			}
			else
				++iter;
		}
	}

	//CCollisionMgr::Collision_Rect(m_listObj[OBJID::MONSTER], m_listObj[OBJID::BULLET]);
	//CCollisionMgr::Collision_Sphere(m_listObj[OBJID::MONSTER], m_listObj[OBJID::MOUSE]);
	//CCollisionMgr::Collision_RectEx(m_listObj[OBJID::MOUSE], m_listObj[OBJID::MONSTER]);
	//CCollisionMgr::Collision_RectEx(m_listObj[OBJID::MONSTER], m_listObj[OBJID::PLAYER]);
}

void CObjMgr::Late_Update()
{
	for (int i = 0; i < OBJID::END; ++i)
	{
		for (auto& pObj : m_listObj[i])
		{
			pObj->Late_Update();
			if (m_listObj[i].empty())
				break;

			GROUPID::ID		eID = pObj->Get_GroupID();
			m_listRender[eID].emplace_back(pObj);
		}
	}
}

void CObjMgr::Render(HDC _DC)
{
	for (int i = 0; i < GROUPID::END; ++i)
	{
		if (i == GROUPID::OBJECT)
			m_listRender[i].sort(CompareY<CObj*>);

		for (auto& pObj : m_listRender[i])
			pObj->Render(_DC);

		m_listRender[i].clear();
	}

	int iPBullet = m_listObj[OBJID::PLAYER_BULLET].size();
	int iEBullet = m_listObj[OBJID::ENEMY_BULLET].size();
	int iEnemy = m_listObj[OBJID::ENEMY].size();

	TCHAR szDebug[32];
	ZeroMemory(szDebug, sizeof(szDebug));
	StringCchPrintf(szDebug, _countof(szDebug), _T("PB:%d / EB:%d / E:%d"), iPBullet, iEBullet, iEnemy);
	TextOut(_DC, 50, 50, szDebug, _tcslen(szDebug));
}

void CObjMgr::Release()
{
	for (int i = 0; i < OBJID::END; ++i)
	{
		for_each(m_listObj[i].begin(), m_listObj[i].end(), Safe_Delete<CObj*>);
		m_listObj[i].clear();
	}
}

void CObjMgr::Delete_ID(OBJID::ID _eID)
{
	for_each(m_listObj[_eID].begin(), m_listObj[_eID].end(), Safe_Delete<CObj*>);
	m_listObj[_eID].clear();
}
