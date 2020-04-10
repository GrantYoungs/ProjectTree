// StartAndHarvestDlg.cpp : implementation file
//

#include "pch.h"
#include "CanadianExperience.h"
#include "StartAndHarvestDlg.h"
#include "afxdialogex.h"
#include "TreeAdapter.h"


// CStartAndHarvestDlg dialog

IMPLEMENT_DYNAMIC(CStartAndHarvestDlg, CDialog)

/**
 * Constructor
 * \param pParent Bruh I ain't even know
 */
CStartAndHarvestDlg::CStartAndHarvestDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_STARTANDHARVEST, pParent)
	, mStartTime(0)
	, mHarvestTime(0)
{

}

/**
 * Destructor
 */
CStartAndHarvestDlg::~CStartAndHarvestDlg()
{
}

/**
 * Sets the start and harvest times of the Tree Adapter
 */
void CStartAndHarvestDlg::Take()
{
	mTreeAdapter->SetStartTime(mStartTime);
	mTreeAdapter->SetHarvestTime(mHarvestTime);
}

/**
 * Sets the values of mStartTime and mHarvestTime
 * \param pDX Bruh
 */
void CStartAndHarvestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STARTTIME, mStartTime);
	DDV_MinMaxInt(pDX, mStartTime, 0, 900);
	DDX_Text(pDX, IDC_HARVESTTIME, mHarvestTime);
	DDV_MinMaxInt(pDX, mHarvestTime, 0, 900);
}


BEGIN_MESSAGE_MAP(CStartAndHarvestDlg, CDialog)
END_MESSAGE_MAP()


// CStartAndHarvestDlg message handlers
