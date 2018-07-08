// EnemyObj.h: CEnemyObj クラスのイン??フェイス
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENEMYOBJ_H__9905D021_33F9_42D3_91D9_32EBCB58FD65__INCLUDED_)
#define AFX_ENEMYOBJ_H__9905D021_33F9_42D3_91D9_32EBCB58FD65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>
#include "EnemyBullet.h"

class CEnemyObj  
{
public:
	CEnemyObj();
	virtual ~CEnemyObj();

	short	m_specify, m_objWidth, m_objHeight;
	short	m_crashedTime;
	POINT	m_point;

	CDC		*m_backDC,m_memDC;
	CBitmap m_bmpE, m_bmpECrashed, m_bmpECrashed1;
	
	CArray<CEnemyBullet*, CEnemyBullet*> *m_arEB;

	void	Draw();
	void	Move();
	short	CheckAndDraw(POINT mp);
	short   Attacked();
};

#endif // !defined(AFX_ENEMYOBJ_H__9905D021_33F9_42D3_91D9_32EBCB58FD65__INCLUDED_)
