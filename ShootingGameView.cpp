// ShootingGameView.cpp : CShootingGameView クラスの動作の定義を行います。
//

#include "stdafx.h"
#include "ShootingGame.h"

#include "ShootingGameDoc.h"
#include "ShootingGameView.h"
#include  <math.h>
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShootingGameView

IMPLEMENT_DYNCREATE(CShootingGameView, CView)

BEGIN_MESSAGE_MAP(CShootingGameView, CView)
	//{{AFX_MSG_MAP(CShootingGameView)
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	//}}AFX_MSG_MAP
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShootingGameView クラスの構築/消滅

CShootingGameView::CShootingGameView()
{
	// TODO: この場所に構築用のコードを追加してください。

}

CShootingGameView::~CShootingGameView()
{
}

BOOL CShootingGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CShootingGameView クラスの描画

void CShootingGameView::OnDraw(CDC* pDC)
{
	CShootingGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}

/////////////////////////////////////////////////////////////////////////////
// CShootingGameView クラスの印刷

BOOL CShootingGameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// デフォルトの印刷準備
	return DoPreparePrinting(pInfo);
}

void CShootingGameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CShootingGameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}

/////////////////////////////////////////////////////////////////////////////
// CShootingGameView クラスの診断

#ifdef _DEBUG
void CShootingGameView::AssertValid() const
{
	CView::AssertValid();
}

void CShootingGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CShootingGameDoc* CShootingGameView::GetDocument() // 非デバッグ バージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShootingGameDoc)));
	return (CShootingGameDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShootingGameView クラスのメッセージ ハンドラ

void CShootingGameView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	CClientDC dc(this);
	
	GetClientRect(&m_rect);
	
	m_rect.left = 0;
	m_rect.top = 0;
	
	//Load bitmaps
//	m_bmpBackground.LoadBitmap(IDB_BMP_BACKGROUND);

	m_bmpEB.LoadBitmap(IDB_EB_G);
	
	
	//Create compatible DC
	BackDC.CreateCompatibleDC(&dc);
	m_bmpBackDC.CreateCompatibleBitmap(&dc,m_rect.Width(),m_rect.Height());
	BackDC.SelectObject(&m_bmpBackDC);
	
	MemDC.CreateCompatibleDC(&dc);

	//Initialize  myplane's position
	m_mp.GiveAtt(m_rect.Width() / 2,m_rect.Height() / 2, &BackDC);

	//Initialize scenario
	m_clSM.m_arE = &m_arE;
	m_clSM.m_backDC = &BackDC;
	m_clSM.m_arEB = &m_arEB;

	//Initialize enemy
	m_arE.RemoveAll();
	m_iEnemyGenMode = 0;

	//Initialize enemy's bullets
	m_arEB.RemoveAll();

	//Initialize bullets 
	m_arB.RemoveAll();

	
	//Initialize game parameter
	m_MoveFlag = FALSE;
	m_oldMousePos.x = m_rect.Width() / 2;
	m_oldMousePos.y = m_rect.Height() / 2;
	m_bGameOver = FALSE;
	bGameOverMsg = FALSE;
	m_RBtnDnFlg = FALSE;

	//Set timer
	m_timeCnt = 0;
	SetTimer(0,30,NULL);
}
/*
void CShootingGameView::AddEnemy()
{
	CEnemyObj* enemy = new CEnemyObj();
	enemy->GiveLife(m_iEnemyGenMode, &m_rect);
	m_arE.Add(enemy);

	m_iEnemyGenMode++;
	if(m_iEnemyGenMode > MAX_E_SPECIES) 
		m_iEnemyGenMode = 0;
}
*/
void CShootingGameView::OnTimer(UINT nIDEvent) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	int i;
                
	CClientDC dc(this);
	GetClientRect(&m_rect);
	
	//Enable copy from background to foreground
	BackDC.SelectObject(&m_bmpBackDC);

	//Clear screen
	CBrush brush(RGB(255,255,255));
	BackDC.FillRect(m_rect, &brush );

	//Draw Me
	m_mp.CheckAndDraw(m_oldMousePos);

	//Draw Enemies
	MemDC.SelectObject(&m_bmpE);
	for(i = 0; i < m_arE.GetSize(); i++)
	{
		short flg = m_arE[i]->CheckAndDraw(m_mp.m_point);
		switch(flg)
		{
		case -1:
			//KillTimer(0);
			m_bGameOver = TRUE;
			break;
		case 1:
			m_arE[i]->~CEnemyObj();
			m_arE.RemoveAt(i);
			i--;
			break;
		}
	}

	//Draw Bullets
	for(i = m_arB.GetSize() - 1; i >=0 ; i--)
	{
		if(m_arB[i]->CheckAndDraw() == 1)
		{
			m_arB[i]->~CMyBullet();
			m_arB.RemoveAt(i);
			i--;
		}
	}

	//Draw Enemy's Bullets
	for(i = m_arEB.GetSize() - 1; i >=0 ; i--)
	{
		switch(m_arEB[i]->CheckAndDraw(m_mp.m_point))
		{
		case -1:
			//KillTimer(0);
			m_bGameOver = TRUE;
			break;
		case 1:
			m_arEB[i]->~CEnemyBullet();
			m_arEB.RemoveAt(i);
			i--;
		}
	}

	//Draw Full Screen
	dc.BitBlt(0,0,m_rect.Width(), m_rect.Height(),&BackDC,0,0,SRCCOPY);
	
	if(m_RBtnDnFlg)
	{
		if(m_arB.GetSize()<MAX_BULLETS)
		{
			CMyBullet *bullet = new CMyBullet();
			POINT pos = m_mp.m_point;
			bullet->GiveAtt(pos, &BackDC, &m_arE);
			m_arB.Add(bullet);
		}
	}
	
	//for when the game has been ended...
	if(m_bGameOver)
	{
		m_mp.ChgToCrashedStat();
		GameOver();
	}
	m_timeCnt++;
	m_clSM.Unfold(m_timeCnt);
	SetFocus();
	CView::OnTimer(nIDEvent);
}

void CShootingGameView::GameOver()
{
	
	if	(bGameOverMsg)	
		return;
	bGameOverMsg = TRUE;

	if (AfxMessageBox("Do you want to play another game?",MB_YESNO) == IDYES)
		(CMainFrame*)GetParentFrame( )->PostMessage(WM_COMMAND,ID_FILE_NEW);	
	else
	{
		(CMainFrame*)GetParentFrame( )->PostMessage(WM_COMMAND,ID_APP_EXIT);	
	}
}


BOOL CShootingGameView::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	if(pMsg->message == WM_KEYDOWN && 
		(pMsg->wParam == VK_RIGHT || pMsg->wParam == VK_LEFT || pMsg->wParam == VK_UP || pMsg->wParam == VK_DOWN))
	{
		SendMessage(pMsg->message, pMsg->wParam, pMsg->lParam);
	}
	if(pMsg->message == WM_KEYDOWN &&  pMsg->wParam == VK_SPACE)
	{
		if(m_arB.GetSize()<MAX_BULLETS)
		{
			CMyBullet *bullet = new CMyBullet();
			POINT pos = m_mp.m_point;
			bullet->GiveAtt(pos, &BackDC, &m_arE);
			m_arB.Add(bullet);
		}
	}

	return CView::PreTranslateMessage(pMsg);
}


void CShootingGameView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	switch(nChar)
	{
	case VK_NUMPAD4:
	case VK_LEFT:
		m_mp.m_MyVelocityX--;
		break;
	case VK_NUMPAD6:
	case VK_RIGHT:
		m_mp.m_MyVelocityX++;
		break;
	case VK_NUMPAD8:
	case VK_UP:
		m_mp.m_MyVelocityY--;
		break;
	case VK_NUMPAD2:
	case VK_DOWN:
		m_mp.m_MyVelocityY++;
		break;
	}	

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CShootingGameView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	m_MoveFlag = TRUE;
	
	CView::OnLButtonDown(nFlags, point);
}

void CShootingGameView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	m_MoveFlag = FALSE;
	
	CView::OnLButtonUp(nFlags, point);
}

void CShootingGameView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	if(!m_MoveFlag)
		return;
	m_oldMousePos = point;
	
	CView::OnMouseMove(nFlags, point);
}

void CShootingGameView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	m_RBtnDnFlg = TRUE;
	CView::OnRButtonDown(nFlags, point);
}

void CShootingGameView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	m_RBtnDnFlg = FALSE;
	CView::OnRButtonUp(nFlags, point);
}
