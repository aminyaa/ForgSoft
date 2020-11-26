#pragma once

// Qt
#include <QCompleter> // Required for inheritance

/**
 * @brief Class, that describes completer with
 * glsl specific types and functions.
 */
	class QExprtkCompleter : public QCompleter
{
	Q_OBJECT

public:

	/**
	 * @brief Constructor.
	 * @param parent Pointer to parent QObject.
	 */
	explicit QExprtkCompleter(QObject* parent = nullptr);

	void AddCompleter(const QString& completer);
	void RemoveCompleter(const QString& completer);
};


