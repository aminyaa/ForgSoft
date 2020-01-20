#pragma once
#ifndef _ProgressWidget_Header
#define _ProgressWidget_Header

#include <QScopedPointer>
#include <QtWidgets/QWidget>

#include <FrgBase_PrptsVrntInt.hxx>
#include <FrgBase_PrptsVrntDouble.hxx>
#include <FrgBase_PrptsVrntString.hxx>
#include <FrgBase_PrptsVrntBool.hxx>

class AA
	: public QWidget
{
	Q_OBJECT

	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntInt* myInt READ GetMyInt WRITE SetMyInt)
	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntDouble* myDouble READ GetMyDouble WRITE SetMyDouble)
	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntString* myString READ GetMyString WRITE SetMyString)
	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntString* myString2 READ GetMyString2 WRITE SetMyString2)
	Q_PROPERTY(ForgBaseLib::FrgBase_PrptsVrntBool* myBool READ GetMyBool WRITE SetMyBool)

public:

	AA() 
	{
		this->setObjectName("MyObject");
		theMyInt_ = new ForgBaseLib::FrgBase_PrptsVrntInt("Number of items", 15, 0, 22, 1, "", "[mm]");
		theMyDouble_ = new ForgBaseLib::FrgBase_PrptsVrntDouble("Ship length", 1.23, 0.0, 17.5, 0.01, "", "[ft]");
		theMyString_ = new ForgBaseLib::FrgBase_PrptsVrntString("Your text", "salam khoobi?", "", "");
		theMyString2_ = new ForgBaseLib::FrgBase_PrptsVrntString("Your text2", "salam khoobi2?", "", "");
		theMyBool_ = new ForgBaseLib::FrgBase_PrptsVrntBool("Is alive", true, "", "");
	}

	ForgBaseLib::FrgBase_PrptsVrntInt* GetMyInt() const { return theMyInt_; }
	void SetMyInt(ForgBaseLib::FrgBase_PrptsVrntInt* value) { theMyInt_ = value; }

	ForgBaseLib::FrgBase_PrptsVrntDouble* GetMyDouble() const { return theMyDouble_; }
	void SetMyDouble(ForgBaseLib::FrgBase_PrptsVrntDouble* value) { theMyDouble_ = value; }

	ForgBaseLib::FrgBase_PrptsVrntString* GetMyString() const { return theMyString_; }
	void SetMyString(ForgBaseLib::FrgBase_PrptsVrntString* value) { theMyString_ = value; }

	ForgBaseLib::FrgBase_PrptsVrntString* GetMyString2() const { return theMyString2_; }
	void SetMyString2(ForgBaseLib::FrgBase_PrptsVrntString* value) { theMyString2_ = value; }

	ForgBaseLib::FrgBase_PrptsVrntBool* GetMyBool() const { return theMyBool_; }
	void SetMyBool(ForgBaseLib::FrgBase_PrptsVrntBool* value) { theMyBool_ = value; }

private:

	ForgBaseLib::FrgBase_PrptsVrntInt* theMyInt_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntDouble* theMyDouble_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntString* theMyString_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntString* theMyString2_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntBool* theMyBool_ = nullptr;
};

class QToolButton;
class pqProgressWidgetLabel;

/**
 * @class pqProgressWidget
 * @brief widget to show progress in a QStatusBar.
 *
 * pqProgressWidget is a widget designed to be used in the QStatusBar of the
 * application to show progress for time consuming tasks in the application.
 *
 * pqProgressWidget is a replacement for QProgressBar. It has the following
 * differences with QProgressBar.
 *
 * \li 1. It adds support for an abort button that can be enabled to allow
 *        aborting for interruptible processing while progress in active.
 * \li 2. It does not use QMacStyle on OsX instead uses "fusion" or "cleanlooks"
 *        show that the text is shown on the progress bar.
 * \li 3. It does not render progress bar grove for a more "flat" look and avoid
 *        dramatic UI change when toggling between showing progress and not.
 */
class pqProgressWidget : public QWidget
{
	Q_OBJECT;
	typedef QWidget Superclass;
	Q_PROPERTY(QString readyText READ readyText WRITE setReadyText)
		Q_PROPERTY(QString busyText READ busyText WRITE setBusyText)
public:
	pqProgressWidget(QWidget* parent = 0);
	~pqProgressWidget() override;

	/**
	 * @deprecated in ParaView 5.5. Use `abortButton` instead.
	 */
	QToolButton* getAbortButton() const { return this->AbortButton; }

	/**
	 * Provides access to the abort button.
	 */
	QToolButton* abortButton() const { return this->AbortButton; }

	//@{
	/**
	 * Set the text to use by default when the progress bar is not enabled
	 * which typically corresponds to application not being busy.
	 * Default value is empty.
	 */
	void setReadyText(const QString&);
	const QString& readyText() const { return this->ReadyText; }
	//@}

	//@{
	/**
	 * Set the text to use by default when the progress bar is enabled
	 * which typically corresponds to application being busy.
	 * Default value is "Busy".
	 */
	void setBusyText(const QString&);
	const QString& busyText() const { return this->BusyText; }
	//@}

public slots:
	/**
	 * Set the progress. Progress must be enabled by calling 'enableProgress`
	 * otherwise this method will have no effect.
	 */
	void setProgress(const QString& message, int value);

	/**
	 * Enabled/disable the progress. This is different from
	 * enabling/disabling the widget itself. This shows/hides
	 * the progress part of the widget.
	 */
	void enableProgress(bool enabled);

	/**
	 * Enable/disable the abort button.
	 */
	void enableAbort(bool enabled);

signals:
	/**
	 * triggered with the abort button is pressed.
	 */
	void abortPressed();

protected:
	pqProgressWidgetLabel* ProgressBar;
	QToolButton* AbortButton;

	/**
	 * request Qt to paint the widgets.
	 */
	void updateUI();

private:
	Q_DISABLE_COPY(pqProgressWidget);
	QString ReadyText;
	QString BusyText;
};

#endif // !_ProgressWidget_Header
