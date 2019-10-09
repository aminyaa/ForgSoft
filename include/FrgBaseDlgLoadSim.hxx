#pragma once
#ifndef _FrgBaseDlgLoadSim_Header
#define _FrgBaseDlgLoadSim_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseDlgNewSim.hxx>

#include <QtWidgets/QLineEdit>

BeginFrgBaseLib

class FORGBASE_EXPORT FrgBaseDlgLoadSim : public FrgBaseDlgNewSim
{
	Q_OBJECT

private:

	QLabel* theBrowseLabel_ = FrgNullPtr;
	QLineEdit* theBrowseLineEdit_ = FrgNullPtr;
	QPushButton* theBrowseBtn_ = FrgNullPtr;
	QHBoxLayout* theBrowseLayout_ = FrgNullPtr;

public:

	FrgBaseDlgLoadSim(FrgBaseMainWindow* parent = FrgNullPtr);

	FrgString GetFileName() const { return theBrowseLineEdit_->text(); }

protected slots:

	void ShowBrowseDialog();


};

EndFrgBaseLib

#endif // !_FrgBaseDlgLoadSim_Header
