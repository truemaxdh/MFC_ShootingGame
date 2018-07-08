// EnemyPlane.cpp: CEnemyPlane クラスのインプリメンテ?ション
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ShootingGame.h"
#include "EnemyPlane.h"
#include <math.h>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// ?築/消滅
//////////////////////////////////////////////////////////////////////

CEnemyPlane::CEnemyPlane()
{
	m_specify = 0;
	m_objWidth = 14;
	m_objHeight = 27;
}

CEnemyPlane::~CEnemyPlane()
{
	
}

void CEnemyPlane::GiveAtt(int iStyle, long x, long y, CDC *backDC, CArray<CEnemyBullet*, CEnemyBullet*> *arEB)
{
	m_iMoveStyle = iStyle;
	switch(iStyle)
	{
	case 0:
		m_ang = 0;
		m_dang = 3.141592 / 30;
		m_rad = 100;
		m_iLifeMax = 300;
		m_iShootInterval = 150;
		break;
	case 1:
		m_ang = 0;
		m_dang = 3.141592 / 60;
		m_rad = 100;
		m_iLifeMax = 300;
		m_iShootInterval = 200;
		break;
	case 2:
		m_ang = 3.141592 / 2 * 3;;
		m_dang = 3.141592 / 30;
		m_rad = 100;
		m_iLifeMax = 300;
		m_iShootInterval = 230;
		break;
	case 3:
		m_ang = 0;
		m_dang = 3.141592 / 30;
		m_rad = 100;
		m_iLifeMax = 300;
		m_iShootInterval = 260;
		break;
	case 4:
		m_ang = 0;
		m_dang = 3.141592 / 30;
		m_rad = 100;
		m_iLifeMax = 300;
		m_iShootInterval = 290;
		break;
	case 5:
		m_ang = 0;
		m_dang = 3.141592 / 100;
		m_rad = 100;
		m_iLifeMax = 300;
		m_iShootInterval = 320;
		break;
	case 6:
		m_ang = 0;
		m_dang = 3.141592 / 90;
		m_rad = 100;
		m_iLifeMax = 300;
		m_iShootInterval = 150;
		break;
	}
	m_iLifeNowTime = 0;
	m_point.x = m_ox = x;
	m_point.y = m_oy = y;
	m_backDC = backDC;
	m_bmpE.LoadBitmap(IDB_E_G);
	m_memDC.CreateCompatibleDC(backDC);
	m_memDC.SelectObject(&m_bmpE);
	m_arEB = arEB;
}

short CEnemyPlane::CheckAndDraw(POINT mp)
{
	m_iLifeNowTime++;
	Move();
	Draw();
	if((mp.x >= m_point.x && mp.x - m_point.x < 15 || mp.x < m_point.x && m_point.x - mp.x < 20)
		&& (mp.y >= m_point.y && mp.y - m_point.y < 25 || mp.y < m_point.y && m_point.y - mp.y < 31))
		return -1;
	int iRand = rand() * m_iShootInterval / RAND_MAX;
	if(iRand == 0)
	{
		CEnemyBullet *eb = new CEnemyBullet();
		eb->GiveAtt(m_iMoveStyle, mp, m_point, m_backDC);
		m_arEB->Add(eb);
	}

	if(m_iLifeNowTime >= m_iLifeMax)
		return 1;
	return 0;
}


void CEnemyPlane::Move()
{
	switch(m_iMoveStyle)
	{
	case 0:
		m_point.x = cos(m_ang + m_dang * m_iLifeNowTime) * m_rad + m_ox;
		m_point.y = sin(m_ang + m_dang * m_iLifeNowTime) * m_rad + m_oy;
		m_ox +=3;
		m_oy +=3;
		break;
	case 1:
		m_point.x = cos(m_ang + m_dang * m_iLifeNowTime) * m_rad + m_ox;
		m_point.y = sin(m_ang + m_dang * m_iLifeNowTime) * m_rad + m_oy;
		m_ox +=1;
		m_oy +=4;
		break;
	case 2:
		m_point.x +=4;
		m_point.y = sin(m_ang + m_dang * m_iLifeNowTime) * m_rad + m_oy;
		m_oy +=1;
		break;
	case 3:
		m_point.x = cos(m_ang + m_dang * m_iLifeNowTime) * m_rad + m_ox;
		m_ox +=2;
		m_point.y +=4;
		break;
	case 4:
		m_point.x = cos(m_ang + m_dang * m_iLifeNowTime) * m_rad + m_ox;
		m_ox +=4;
		m_point.y +=2;
		break;
	case 5:
		m_point.x = cos(m_ang + m_dang * m_iLifeNowTime) * m_rad + m_ox;
		m_point.y = sin(m_ang + m_dang * m_iLifeNowTime) * m_rad + m_oy;
		m_ox +=3;
		m_oy +=3;
		break;
	case 6:
		m_point.x = cos(m_ang + m_dang * m_iLifeNowTime) * m_rad + m_ox;
		m_point.y = sin(m_ang + m_dang * m_iLifeNowTime) * m_rad + m_oy;
		m_ox +=4;
		m_oy +=4;
		break;
	}

}