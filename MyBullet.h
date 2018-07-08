// MyBullet.h: CMyBullet クラスのインターフェイス
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYBULLET_H__0460B346_4722_498D_BF92_CF0441262CD3__INCLUDED_)
#define AFX_MYBULLET_H__0460B346_4722_498D_BF92_CF0441262CD3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>
#include "EnemyObj.h"

class CMyBullet  
{
public:
	CMyBullet();
	virtual ~CMyBullet();

	void	GiveAtt(POINT p, CDC* backDC, CArray<CEnemyObj*, CEnemyObj*> *arE);
	short	CheckAndDraw();
	POINT	m_point;

private:
	CDC		*m_backDC,m_memDC;
	CBitmap m_bmpB;
	CArray<CEnemyObj*, CEnemyObj*> *m_arE;

	void	Draw();
	void	Move();
};

#endif // !defined(AFX_MYBULLET_H__0460B346_4722_498D_BF92_CF0441262CD3__INCLUDED_)
