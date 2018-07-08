// ShootingGameView.h : CShootingGameView クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOOTINGGAMEVIEW_H__2652D79D_3C2A_49F8_99B1_10F9976A8782__INCLUDED_)
#define AFX_SHOOTINGGAMEVIEW_H__2652D79D_3C2A_49F8_99B1_10F9976A8782__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>
#include "EnemyObj.h"
#include "EnemyPlane.h"
#include "MyPlane.h"
#include "ScenarioManager.h"
#include "MyBullet.h"


class CShootingGameView : public CView
{
protected: // シリアライズ機能のみから作成します。
	CShootingGameView();
	DECLARE_DYNCREATE(CShootingGameView)
	CScenarioManager m_clSM;
// アトリビュート
	void	GameOver();
public:
	// my plane
	CMyPlane	m_mp;
	CPoint m_oldMousePos;
	
	// bullet
	CArray<CMyBullet*,CMyBullet*> m_arB;
	
	// enemy
	CArray<CEnemyObj*, CEnemyObj*> m_arE;

	//enemy's bullets
	CArray<CEnemyBullet*, CEnemyBullet*> m_arEB;

	// screen
	CDC MemDC,BackDC;
	CBitmap m_bmpM, m_bmpE, m_bmpB, m_bmpEB, m_bmpBackDC, m_bmpBackground;

	// game 
	BOOL m_MoveFlag, m_RBtnDnFlg, m_bGameOver, bGameOverMsg;
	CRect m_rect;
	int m_iEnemyGenMode;
	long m_timeCnt;
	
// オペレーション
public:
	CShootingGameDoc* GetDocument();
	//void AddEnemy();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CShootingGameView)
	public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画する際にオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CShootingGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CShootingGameView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ShootingGameView.cpp ファイルがデバッグ環境の時使用されます。
inline CShootingGameDoc* CShootingGameView::GetDocument()
   { return (CShootingGameDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_SHOOTINGGAMEVIEW_H__2652D79D_3C2A_49F8_99B1_10F9976A8782__INCLUDED_)
