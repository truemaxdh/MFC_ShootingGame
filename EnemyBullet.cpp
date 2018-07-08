// EnemyBullet.cpp: CEnemyBullet クラスのインプリメンテ?ション
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ShootingGame.h"
#include "EnemyBullet.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// ?築/消滅
//////////////////////////////////////////////////////////////////////

CEnemyBullet::CEnemyBullet()
{

}

CEnemyBullet::~CEnemyBullet()
{

}


void CEnemyBullet::GiveAtt(short iMoveStyle, POINT mp, POINT p, CDC *backDC)
{
	m_point = p;
	int dx = mp.x - p.x;
	int dy = mp.y - p.y;
	if (dx == 0 && dy == 0)
		dx = dy = 1;
	float distant = sqrt((float)(dx * dx + dy * dy));

	m_speed.x = dx / distant * (iMoveStyle + 1) * 2;
	m_speed.y = dy / distant * (iMoveStyle + 1) * 2;

	m_backDC = backDC;
	m_bmpEB.LoadBitmap(IDB_EB_G);
	m_memDC.CreateCompatibleDC(backDC);
	m_memDC.SelectObject(&m_bmpEB);
}

short CEnemyBullet::CheckAndDraw(POINT mp)
{
	Move();
	Draw();
	if((mp.x >= m_point.x && mp.x - m_point.x < 9 || mp.x < m_point.x && m_point.x - mp.x < 20)
		&& (mp.y >= m_point.y && mp.y - m_point.y < 18 || mp.y < m_point.y && m_point.y - mp.y < 31))
		return -1;
	if(m_point.x < 0 || m_point.x > SCREENWIDTH || m_point.y < 0 || m_point.y > SCREENHEIGHT) return 1;
	return 0;
}

void CEnemyBullet::Draw()
{
	m_backDC->BitBlt(m_point.x, m_point.y,9,18,&m_memDC,0,0, SRCCOPY);	
}

void CEnemyBullet::Move()
{
	m_point.x +=m_speed.x;
	m_point.y +=m_speed.y;
}