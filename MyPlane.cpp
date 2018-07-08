// MyPlane.cpp: CMyPlane クラスのインプリメンテーション
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ShootingGame.h"
#include "MyPlane.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// 構築/消滅
//////////////////////////////////////////////////////////////////////

CMyPlane::CMyPlane()
{
	m_mpWidth = 20;
	m_mpHeight = 31;
}

CMyPlane::~CMyPlane()
{

}

void CMyPlane::GiveAtt(long x, long y, CDC *backDC)
{
	m_point.x = x;
	m_point.y = y;
	m_backDC = backDC;
	m_bmpM.LoadBitmap(IDB_M_G);
	m_bmpCrashed.LoadBitmap(IDB_CRASHED);
	m_bmpCrashed1.LoadBitmap(IDB_CRASHED1);
	m_memDC.CreateCompatibleDC(backDC);
	m_memDC.SelectObject(&m_bmpM);
	m_MyVelocityX = m_MyVelocityY = 0;
	m_bombCnt = 3;
}

void CMyPlane::CheckAndDraw(POINT mp)
{
	m_point.x +=m_MyVelocityX;
	m_point.y +=m_MyVelocityY;
	m_MyVelocityX = (mp.x - m_point.x) / 3;
	m_MyVelocityY = (mp.y - m_point.y) / 3;
		
	Draw();
}

void CMyPlane::Draw()
{
	m_backDC->BitBlt(m_point.x, m_point.y,20,31,&m_memDC,0,0, SRCCOPY);	
}

void CMyPlane::ChgToCrashedStat()
{
	static short sFlipFlg;
	sFlipFlg++;
	
	if(sFlipFlg > 19)
		sFlipFlg = 0;

	if(sFlipFlg < 9)
		m_memDC.SelectObject(&m_bmpCrashed);
	else
		m_memDC.SelectObject(&m_bmpCrashed1);
	
}
