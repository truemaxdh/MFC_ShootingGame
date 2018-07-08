// ScenarioManager.cpp: CScenarioManager クラスのインプリメンテ?ション
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ShootingGame.h"
#include "ScenarioManager.h"
#include "EnemyObj.h"
#include "EnemyPlane.h"
#include "EnemyKing.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// ?築/消滅
//////////////////////////////////////////////////////////////////////

CScenarioManager::CScenarioManager()
{

}

CScenarioManager::~CScenarioManager()
{

}
void CScenarioManager::MakeFormation(int iStyle)
{
	switch(iStyle)
	{
	case 0:
		AddEnemy(iStyle,0,-10);
		AddEnemy(iStyle,20,-10);
		AddEnemy(iStyle,40,-10);
		AddEnemy(iStyle,60,-10);
		AddEnemy(iStyle,80,-10);
		AddEnemy(iStyle,100,-10);
		AddEnemy(iStyle,120,-10);
		AddEnemy(iStyle,140,-10);
		AddEnemy(iStyle,160,-10);
		AddEnemy(iStyle,180,-10);
		break;
	case 1:
		AddEnemy(iStyle,500,-10);
		AddEnemy(iStyle,520,-10);
		AddEnemy(iStyle,540,-10);
		AddEnemy(iStyle,560,-10);
		AddEnemy(iStyle,580,-10);
		AddEnemy(iStyle,600,-10);
		AddEnemy(iStyle,620,-10);
		AddEnemy(iStyle,640,-10);
		AddEnemy(iStyle,660,-10);
		AddEnemy(iStyle,680,-10);
		break;
	case 2:
		AddEnemy(iStyle,0,50);
		AddEnemy(iStyle,20,50);
		AddEnemy(iStyle,40,50);
		AddEnemy(iStyle,60,50);
		AddEnemy(iStyle,80,50);
		AddEnemy(iStyle,100,50);
		AddEnemy(iStyle,120,50);
		AddEnemy(iStyle,140,50);
		AddEnemy(iStyle,160,50);
		AddEnemy(iStyle,180,50);
		break;
	case 3:
		AddEnemy(iStyle,500,-10);
		AddEnemy(iStyle,520,-10);
		AddEnemy(iStyle,540,-10);
		AddEnemy(iStyle,560,-10);
		AddEnemy(iStyle,580,-10);
		AddEnemy(iStyle,600,-10);
		AddEnemy(iStyle,620,-10);
		AddEnemy(iStyle,640,-10);
		AddEnemy(iStyle,660,-10);
		AddEnemy(iStyle,680,-10);
		break;
	case 4:
		AddEnemy(iStyle,0,-10);
		AddEnemy(iStyle,20,-10);
		AddEnemy(iStyle,40,-10);
		AddEnemy(iStyle,60,-10);
		AddEnemy(iStyle,80,-10);
		AddEnemy(iStyle,100,-10);
		AddEnemy(iStyle,120,-10);
		AddEnemy(iStyle,140,-10);
		AddEnemy(iStyle,160,-10);
		AddEnemy(iStyle,180,-10);
		break;
	case 5:
		AddEnemy(iStyle,500,-10);
		AddEnemy(iStyle,520,-10);
		AddEnemy(iStyle,540,-10);
		AddEnemy(iStyle,560,-10);
		AddEnemy(iStyle,580,-10);
		AddEnemy(iStyle,600,-10);
		AddEnemy(iStyle,620,-10);
		AddEnemy(iStyle,640,-10);
		AddEnemy(iStyle,660,-10);
		AddEnemy(iStyle,680,-10);
		break;
	case 6:
		AddEnemy(iStyle,0,0);
		AddEnemy(iStyle,-20,0);
		AddEnemy(iStyle,-40,0);
		AddEnemy(iStyle,-60,0);
		AddEnemy(iStyle,-80,0);
		AddEnemy(iStyle,-100,0);
		AddEnemy(iStyle,-120,0);
		AddEnemy(iStyle,-140,0);
		AddEnemy(iStyle,-160,0);
		AddEnemy(iStyle,-180,0);
		break;
	case 7:
		AddKing(iStyle,0,0);
		break;
	}
}

void CScenarioManager::Unfold(long timeCnt)
{

	switch(timeCnt)
	{
	
	case 5:
		MakeFormation(0);
		break;
	case 100:
		MakeFormation(1);
		break;
	case 200:
		MakeFormation(2);
		break;
	case 300:
		MakeFormation(3);
		break;
	case 400:
		MakeFormation(4);
		break;
	case 500:
		MakeFormation(5);
		break;
	case 600:
		MakeFormation(6);
		break;
	case 700:
		MakeFormation(0);
		break;
	case 710:
		MakeFormation(1);
		break;
	case 800:
		MakeFormation(2);
		break;
	case 810:
		MakeFormation(3);
		break;
	case 900:
		MakeFormation(4);
		break;
	case 910:
		MakeFormation(5);
		break;
	case 920:
		MakeFormation(6);
		break;
	case 930:
		MakeFormation(0);
		break;
	case 940:
		MakeFormation(1);
		break;
	case 950:
		MakeFormation(2);
		break;
	case 960:
		MakeFormation(3);
		break;
	case 970:
		MakeFormation(4);
		break;
	case 980:
		MakeFormation(5);
		break;
	case 990:
		MakeFormation(6);
		break;
	case 1200:
		MakeFormation(7);
		break;
	}
}

void CScenarioManager::AddEnemy(int iStyle, int x, int y)
{
	//CEnemyObj *anEnemy = new CEnemyObj();
	//anEnemy->GiveAtt(iStyle,x,y,m_backDC, m_arEB);
	CEnemyPlane *anEP = new CEnemyPlane();
	anEP->GiveAtt(iStyle,x,y,m_backDC, m_arEB);
	m_arE->Add(anEP);
}

void CScenarioManager::AddKing(int iStyle, int x, int y)
{
	//CEnemyObj *anEnemy = new CEnemyObj();
	//anEnemy->GiveAtt(iStyle,x,y,m_backDC, m_arEB);
	CEnemyKing *anK = new CEnemyKing();
	anK->GiveAtt(iStyle,x,y,m_backDC, m_arEB);
	m_arE->Add(anK);
}