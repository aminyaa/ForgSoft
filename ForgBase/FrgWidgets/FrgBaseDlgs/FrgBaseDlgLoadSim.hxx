#pragma once
#ifndef _FrgDlgLoadSim_Header
#define _FrgDlgLoadSim_Header

#include <FrgBaseGlobals.hxx>
#include <FrgDlgNewSim.hxx>

#include <QtWidgets/QLineEdit>

BeginFrgBaseLib

class FORGBASE_EXPORT FrgDlgLoadSim : public FrgDlgNewSim
{
	Q_OBJECT

private:

	QLabel* theBrowseLabel_ = FrgNullPtr;
	QLineEdit* theBrowseLineEdit_ = FrgNullPtr;
	QPushButton* theBrowseBtn_ = FrgNullPtr;
	QHBoxLayout* theBrowseLayout_ = FrgNullPtr;

public:

	FrgDlgLoadSim(FrgMainWindow* parent = FrgNullPtr);

	FrgString GetFileName() const { return theBrowseLineEdit_->text(); }

protected slots:

	void ShowBrowseDialog();


};

EndFrgBaseLib

#endif // !_FrgDlgLoadSim_Header
