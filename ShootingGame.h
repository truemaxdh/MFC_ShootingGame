// ShootingGame.h : SHOOTINGGAME �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//

#if !defined(AFX_SHOOTINGGAME_H__6E4710A8_8213_4F19_9EF3_41E5FF56A674__INCLUDED_)
#define AFX_SHOOTINGGAME_H__6E4710A8_8213_4F19_9EF3_41E5FF56A674__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // ���C�� �V���{��

/////////////////////////////////////////////////////////////////////////////
// CShootingGameApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� ShootingGame.cpp �t�@�C�����Q�Ƃ��Ă��������B
//
class CShootingGameApp : public CWinApp
{
public:
	CShootingGameApp();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CShootingGameApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
	//{{AFX_MSG(CShootingGameApp)
	afx_msg void OnAppAbout();
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_SHOOTINGGAME_H__6E4710A8_8213_4F19_9EF3_41E5FF56A674__INCLUDED_)
