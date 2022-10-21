#pragma once
#ifndef _FrgCAD_DlgEntity_Header
#define _FrgCAD_DlgEntity_Header

#include <FrgCAD_Global.hxx>
#include <QtWidgets/QWidget>

class QVBoxLayout;
class QPushButton;

BeginForgCADLib

class FORGCAD_EXPORT FrgCAD_DlgEntity
	: public QWidget
{

	Q_OBJECT

public:

	FrgCAD_DlgEntity(QWidget* parent = nullptr);

	virtual void SetFocused(bool condition = true) = 0;

	bool IsInEditing() const { return theIsInEditing_; }

	virtual void SetValue(std::vector<double> values) = 0;

	Q_SIGNAL void OKClickedSignal();
	Q_SIGNAL void CancelClickedSignal();
	Q_SIGNAL void IsInEditingSignal(bool);

protected:

	virtual void FormDlg();
	void SetGeometry(int w, int h);

	void enterEvent(QEvent* event) override;
	void leaveEvent(QEvent* event) override;
	void keyPressEvent(QKeyEvent* event) override;
	bool eventFilter(QObject* watched, QEvent* event) override;

protected:

	QVBoxLayout* theLayout_ = nullptr;

	bool theIsInEditing_;

	QPushButton* theOKButton_ = nullptr;
	QPushButton* theCancelButton_ = nullptr;

	QWidget* theParent_ = nullptr;

	QCursor theTmpCursor_;
};

EndForgCADLib

#endif // !_FrgCAD_DlgEntity_Header
