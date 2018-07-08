// MyPlane.h: CMyPlane クラスのインターフェイス
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYPLANE_H__507BB7A9_4546_44F1_90D1_91C67E89CEE4__INCLUDED_)
#define AFX_MYPLANE_H__507BB7A9_4546_44F1_90D1_91C67E89CEE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>

class CMyPlane  
{
public:
	CMyPlane();
	virtual ~CMyPlane();
	
	POINT	m_point;
	float	m_MyVelocityX, m_MyVelocityY;
	short	m_bombCnt;

	void	GiveAtt(long x, long y, CDC* backDC);
	void	CheckAndDraw(POINT mp);
	void	ChgToCrashedStat();
private:
	CDC		*m_backDC,m_memDC;
	CBitmap m_bmpM, m_bmpCrashed, m_bmpCrashed1;
	short	m_mpWidth, m_mpHeight;
	void	Draw();
};

#endif // !defined(AFX_MYPLANE_H__507BB7A9_4546_44F1_90D1_91C67E89CEE4__INCLUDED_)
