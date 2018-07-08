// EnemyObj.cpp: CEnemyObj クラスのインプリメンテ?ション
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ShootingGame.h"
#include "EnemyObj.h"
#include "EnemyPlane.h"
#include "EnemyKing.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// ?築/消滅
//////////////////////////////////////////////////////////////////////

CEnemyObj::CEnemyObj()
{
	m_bmpECrashed.LoadBitmap(IDB_ECRASHED);
	m_bmpECrashed1.LoadBitmap(IDB_ECRASHED1);
	m_crashedTime = 0;
}

CEnemyObj::~CEnemyObj()
{

}



void CEnemyObj::Draw()
{
	m_backDC->BitBlt(m_point.x, m_point.y, m_objWidth, m_objHeight, &m_memDC, 0, 0, SRCCOPY);	
}

short CEnemyObj::CheckAndDraw(POINT mp)
{
	switch(m_specify)
	{
	case 0:
		return ((CEnemyPlane *)this)->CheckAndDraw(mp);
	case 1:
		return ((CEnemyKing *)this)->CheckAndDraw(mp);
	case 2:
		Draw();
		switch(m_crashedTime)
		{
		case 0:
			m_memDC.SelectObject(&m_bmpECrashed);
			break;
		case 7:
			m_memDC.SelectObject(&m_bmpECrashed1);
			break;
		case 15:
			return 1;
		}
		m_crashedTime++;
		return 0;
	case 3:
		Draw();
		switch(m_crashedTime)
		{
		case 0:
			m_memDC.SelectObject(&m_bmpECrashed);
			break;
		case 12:
			m_memDC.SelectObject(&m_bmpECrashed1);
			break;
		case 25:
			return 1;
		}
		m_crashedTime++;
		return 0;
	}
}

short CEnemyObj::Attacked()
{
	switch(m_specify)
	{
	case 0:
		return 0;
	case 1:
		return ((CEnemyKing *)this)->DiminishPersistence();
	case 2:
		return 1;
	}
}