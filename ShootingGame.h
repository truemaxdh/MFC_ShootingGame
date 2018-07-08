// ShootingGame.h : SHOOTINGGAME アプリケーションのメイン ヘッダー ファイル
//

#if !defined(AFX_SHOOTINGGAME_H__6E4710A8_8213_4F19_9EF3_41E5FF56A674__INCLUDED_)
#define AFX_SHOOTINGGAME_H__6E4710A8_8213_4F19_9EF3_41E5FF56A674__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // メイン シンボル

/////////////////////////////////////////////////////////////////////////////
// CShootingGameApp:
// このクラスの動作の定義に関しては ShootingGame.cpp ファイルを参照してください。
//
class CShootingGameApp : public CWinApp
{
public:
	CShootingGameApp();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CShootingGameApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション
	//{{AFX_MSG(CShootingGameApp)
	afx_msg void OnAppAbout();
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_SHOOTINGGAME_H__6E4710A8_8213_4F19_9EF3_41E5FF56A674__INCLUDED_)
