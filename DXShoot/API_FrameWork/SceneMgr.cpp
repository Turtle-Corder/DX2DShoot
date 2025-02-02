#include "stdafx.h"
#include "SceneMgr.h"
#include "Logo.h"
#include "MyMenu.h"
#include "Stage.h"

CSceneMgr* CSceneMgr::m_pInstance = nullptr;
CSceneMgr::CSceneMgr()
	: m_pScene(nullptr), m_ePreScene(END), m_eCurScene(END)
{
}


CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::Update()
{
	m_pScene->Update();
}

void CSceneMgr::Late_Update()
{
	m_pScene->Late_Update();
}

void CSceneMgr::Render(HDC _DC)
{
	m_pScene->Render(_DC);
}

void CSceneMgr::Release()
{
	SAFE_DELETE(m_pScene);
}

void CSceneMgr::Scene_Change(SCENEID _eID)
{
	m_eCurScene = _eID;

	if (m_ePreScene != m_eCurScene)
	{
		SAFE_DELETE(m_pScene);

		switch (m_eCurScene)
		{
		case LOGO:
			m_pScene = new CLogo;
			break;
		case MENU:
			m_pScene = new CMyMenu;
			break;
		case STAGE:
			m_pScene = new CStage;
			break;
		}
		m_pScene->Initialize();
		m_ePreScene = m_eCurScene;
	}
}
