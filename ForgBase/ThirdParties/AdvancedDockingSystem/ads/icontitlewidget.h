#ifndef ICONTITLEWIDGET_H
#define ICONTITLEWIDGET_H

#include <QFrame>

namespace ForgBaseLib
{
	class FrgBase_Menu;
}

class QIcon;
class QString;
class QLabel;
class QPushButton;

class IconTitleWidget : public QFrame
{
	Q_OBJECT

public:
	explicit IconTitleWidget(const QIcon& icon, const QString& title, QWidget *parent = 0);

public slots:
	void setIcon(const QIcon& icon);
	void setTitle(const QString& title);
	void polishUpdate();

public:
	QLabel* _iconLabel = nullptr;
	QLabel* _titleLabel = nullptr;
	QPushButton* _closeButton = nullptr;

signals:

	void CloseButtonClicked();
	void CloseAllButtonClicked();
	void CloseOtherButtonClicked();
	void TabClicked();
	void TabScrolled(int);
	void TabShifted(int);

protected:

	void keyPressEvent(QKeyEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void wheelEvent(QWheelEvent* event) override;
	void ShowContextMenu(const QPoint& globalPos);

	ForgBaseLib::FrgBase_Menu* theContextMenu_ = nullptr;

};

#endif // ICONTITLEWIDGET_H
