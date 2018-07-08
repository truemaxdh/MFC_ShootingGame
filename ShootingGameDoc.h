// ShootingGameDoc.h : CShootingGameDoc クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOOTINGGAMEDOC_H__F96BD02D_82D7_479F_B2B0_200140381B30__INCLUDED_)
#define AFX_SHOOTINGGAMEDOC_H__F96BD02D_82D7_479F_B2B0_200140381B30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShootingGameDoc : public CDocument
{
protected: // シリアライズ機能のみから作成します。
	CShootingGameDoc();
	DECLARE_DYNCREATE(CShootingGameDoc)

// アトリビュート
public:

// オペレーション
public:

//オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CShootingGameDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CShootingGameDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CShootingGameDoc)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_SHOOTINGGAMEDOC_H__F96BD02D_82D7_479F_B2B0_200140381B30__INCLUDED_)
