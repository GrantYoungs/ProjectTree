/**
 * \file StartAndHarvestDlg.h
 *
 * \author Grant Youngs
 *
 * Dialogue box to edit the start and harvest times of the tree
 */

#pragma once

#include "TreeAdapter.h"


// CStartAndHarvestDlg dialog

/**
 * Dialogue box to edit the start and harvest times of the tree
 */
class CStartAndHarvestDlg : public CDialog
{
	DECLARE_DYNAMIC(CStartAndHarvestDlg)

public:
	CStartAndHarvestDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CStartAndHarvestDlg();

	/**
	* Sets the tree adapter
	* \param treeAdapter The tree adapter
	*/
	void SetTreeAdapter(CTreeAdapter* treeAdapter) { mTreeAdapter = treeAdapter; }

	void Take();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STARTANDHARVEST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	/// The time in frames at which the tree should start growing
	int mStartTime;

	/// The time in frames at which the tree should harvest
	int mHarvestTime;

	/// The tree adapter we'll pass the start time and harvest time values to
	CTreeAdapter* mTreeAdapter;
};
