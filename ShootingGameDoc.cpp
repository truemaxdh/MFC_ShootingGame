// ShootingGameDoc.cpp : CShootingGameDoc �N���X�̓���̒�`���s���܂��B
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
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShootingGameDoc �N���X�̍\�z/����

CShootingGameDoc::CShootingGameDoc()
{
	// TODO: ���̈ʒu�ɂP�x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CShootingGameDoc::~CShootingGameDoc()
{
}

BOOL CShootingGameDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CShootingGameDoc �V���A���C�[�[�V����

void CShootingGameDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���̈ʒu�ɕۑ��p�̃R�[�h��ǉ����Ă��������B
	}
	else
	{
		// TODO: ���̈ʒu�ɓǂݍ��ݗp�̃R�[�h��ǉ����Ă��������B
	}
}

/////////////////////////////////////////////////////////////////////////////
// CShootingGameDoc �N���X�̐f�f

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
// CShootingGameDoc �R�}���h
