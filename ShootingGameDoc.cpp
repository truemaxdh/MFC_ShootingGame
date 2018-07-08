// ShootingGameDoc.cpp : CShootingGameDoc クラスの動作の定義を行います。
//

#include "stdafx.h"
#include "ShootingGame.h"

#include "ShootingGameDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShootingGameDoc

IMPLEMENT_DYNCREATE(CShootingGameDoc, CDocument)

BEGIN_MESSAGE_MAP(CShootingGameDoc, CDocument)
	//{{AFX_MSG_MAP(CShootingGameDoc)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShootingGameDoc クラスの構築/消滅

CShootingGameDoc::CShootingGameDoc()
{
	// TODO: この位置に１度だけ呼ばれる構築用のコードを追加してください。

}

CShootingGameDoc::~CShootingGameDoc()
{
}

BOOL CShootingGameDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CShootingGameDoc シリアライゼーション

void CShootingGameDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: この位置に保存用のコードを追加してください。
	}
	else
	{
		// TODO: この位置に読み込み用のコードを追加してください。
	}
}

/////////////////////////////////////////////////////////////////////////////
// CShootingGameDoc クラスの診断

#ifdef _DEBUG
void CShootingGameDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShootingGameDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShootingGameDoc コマンド
