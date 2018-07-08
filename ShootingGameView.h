// ShootingGameView.h : CShootingGameView �N���X�̐錾����уC���^�[�t�F�C�X�̒�`�����܂��B
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
protected: // �V���A���C�Y�@�\�݂̂���쐬���܂��B
	CShootingGameView();
	DECLARE_DYNCREATE(CShootingGameView)
	CScenarioManager m_clSM;
// �A�g���r���[�g
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
	
// �I�y���[�V����
public:
	CShootingGameDoc* GetDocument();
	//void AddEnemy();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CShootingGameView)
	public:
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷��ۂɃI�[�o�[���C�h����܂��B
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~CShootingGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ���b�Z�[�W �}�b�v�֐�
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

#ifndef _DEBUG  // ShootingGameView.cpp �t�@�C�����f�o�b�O���̎��g�p����܂��B
inline CShootingGameDoc* CShootingGameView::GetDocument()
   { return (CShootingGameDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_SHOOTINGGAMEVIEW_H__2652D79D_3C2A_49F8_99B1_10F9976A8782__INCLUDED_)
