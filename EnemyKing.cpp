// EnemyKing.cpp: CEnemyKing クラスのインプリメンテ?ション
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ShootingGame.h"
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

CEnemyKing::CEnemyKing()
{
	m_specify = 1;
	m_objWidth = 97;
	m_objHeight = 97;
	m_iPersistence = 1000;
}

CEnemyKing::~CEnemyKing()
{

}


void CEnemyKing::GiveAtt(int iStyle, long x, long y, CDC *backDC, CArray<CEnemyBullet*, CEnemyBullet*> *arEB)
{
	m_iMoveStyle = 0;
	m_ang = 0;
	m_dang = 3.141592 / 30;
	m_rad = 0;
	//m_iLifeMax = 1100;
	
	
	m_iLifeNowTime = 0;
	m_point.x = m_ox = x;
	m_point.y = m_oy = y;
	m_backDC = backDC;
	m_bmpE.LoadBitmap(IDB_EK_G);
	m_memDC.CreateCompatibleDC(backDC);
	m_memDC.SelectObject(&m_bmpE);
	m_arEB = arEB;
}

short CEnemyKing::CheckAndDraw(POINT mp)
{
	m_iLifeNowTime++;
	Move();
	Draw();
	if((mp.x < m_point.x && m_point.x - mp.x < 20 || mp.x >= m_point.x && mp.x - m_point.x < m_objWidth)
		&& (mp.y < m_point.y && m_point.y - mp.y < 31 || mp.y >= m_point.y && mp.y - m_point.y < m_objHeight))
		return -1;
	int iRand = rand() * m_iShootInterval / RAND_MAX;
	if(iRand == 0)
	{
		CEnemyBullet *eb = new CEnemyBullet();
		eb->GiveAtt(m_iMissileSpeed, mp, m_point, m_backDC);
		m_arEB->Add(eb);
	}
	/*
	if(m_iLifeNowTime >= m_iLifeMax)
		return 1;
	*/
	return 0;
}

void CEnemyKing::Move()
{
	switch(m_iMoveStyle)
	{
	case 0:
		m_iShootInterval = 9;
		m_iMissileSpeed = 8;
		m_point.x += 6;
		m_ox += 6;
		if(m_iLifeNowTime > 160)
			m_iMoveStyle++;
		break;
	case 1:
		m_iShootInterval = 15;
		m_iMissileSpeed = 6;
		m_point.x -= 3;
		m_point.y += 2;
		m_ox = m_point.x;
		m_oy = m_point.y;
		if(m_iLifeNowTime > 300)
			m_iMoveStyle++;
		break;
	case 2:
		m_iShootInterval = 15;
		m_iMissileSpeed = 9;
		if(m_iLifeNowTime > 450)
			m_iMoveStyle++;
		break;
	case 3:
		POINT p;

		m_iShootInterval = 1000;
		p.x = cos(m_ang + m_dang * m_iLifeNowTime) * 100 + m_point.x;
		p.y = sin(m_ang + m_dang * m_iLifeNowTime) * 100 + m_point.y;
		m_arEB->Add(new CEnemyBullet());
		m_arEB->GetAt(m_arEB->GetSize() - 1)->GiveAtt(m_iMissileSpeed, p, m_point, m_backDC);
		if(m_iLifeNowTime > 600)
			m_iMoveStyle++;
			m_rad = 0;
		break;
	case 4:
		m_iShootInterval = 9;
		m_point.x = cos(m_ang + m_dang * m_iLifeNowTime) * m_rad + m_ox;
		m_point.y = sin(m_ang + m_dang * m_iLifeNowTime) * m_rad + m_oy;
		m_rad++;
		if(m_iLifeNowTime > 800)
			m_iMoveStyle++;
		break;
	case 5:
		m_iShootInterval = 9;
		m_point.x = cos(m_ang + m_dang * m_iLifeNowTime) * m_rad + m_ox;
		m_point.y = sin(m_ang + m_dang * m_iLifeNowTime) * m_rad + m_oy;
		m_rad--;
		if(m_iLifeNowTime > 1000)
			m_iMoveStyle++;
		break;
	case 6:
		m_iShootInterval = 1000;
		if((m_iLifeNowTime % 10) == 0)
		{
			for(int angCnt = 0; angCnt < 20; angCnt ++)
			{
				p.x = cos(m_ang + m_dang * angCnt) * 100 + m_point.x;
				p.y = sin(m_ang + m_dang * angCnt) * 100 + m_point.y;
				m_arEB->Add(new CEnemyBullet());
				m_arEB->GetAt(m_arEB->GetSize() - 1)->GiveAtt(m_iMissileSpeed, p, m_point, m_backDC);
			}
		}
		if(m_iLifeNowTime > 1200)
			m_iMoveStyle++;
		break;
	case 7:
		static float fRot = 0;

		m_iShootInterval = 1000;
		if((m_iLifeNowTime % 10) == 0)
		{
			for(int angCnt = 0; angCnt < 20; angCnt ++)
			{
				p.x = cos(m_ang + fRot + m_dang * angCnt) * 100 + m_point.x;
				p.y = sin(m_ang + fRot + m_dang * angCnt) * 100 + m_point.y;
				m_arEB->Add(new CEnemyBullet());
				m_arEB->GetAt(m_arEB->GetSize() - 1)->GiveAtt(m_iMissileSpeed, p, m_point, m_backDC);
			}
			fRot += 0.2f;
		}
		
		if(m_iLifeNowTime > 1400)
		{	m_iMoveStyle = 2;
			m_iLifeNowTime = 300;
		}
		break;

	}

}


short CEnemyKing::DiminishPersistence()
{
	return (--m_iPersistence);
	
}