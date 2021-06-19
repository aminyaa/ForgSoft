#include <FrgBase_PrptsWdgFieldDialog.hxx>
#include <FrgBase_PrptsWdgFieldScalar.hxx>
#include <FrgBase_PrptsVrntFieldScalar.hxx>
#include <FrgBase_PrptsVrntFieldVector.hxx>
#include <FrgBase_PrptsVrntFieldVector.hxx>
#include <FrgBase_PrptsWdgFieldVector.hxx>
#include <FrgBase_ToolsParameter_TItem.hxx>
#include <FrgBase_ToolsParameters_TItem.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_PropertiesPanel.hxx>

#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QLayout>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtGui/QKeyEvent>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>
#include <QtWidgets/QFileDialog>
#include <QtCore/QTextStream>

#include <QCodeEditor>
#include <QSyntaxStyle>
#include <QExprtkCompleter>
#include <QCXXHighlighter>

#include <exprtk.hpp>

ForgBaseLib::FrgBase_PrptsWdgFieldDialog::FrgBase_PrptsWdgFieldDialog
(
	QWidget* parent,
	Qt::WindowFlags f
)
	: QDialog(parent, f)
{
	theLableColor_ = "black";

	const auto& wdgField = dynamic_cast<FrgBase_PrptsWdgField*>(parent);
	if (wdgField)
	{
		if (wdgField->GetParentTItem()->GetParentMainWindow()->IsThemeDark())
			theLableColor_ = "white";
		else
			theLableColor_ = "black";
	}
}

ForgBaseLib::FrgBase_PrptsWdgFieldDialog::~FrgBase_PrptsWdgFieldDialog()
{
	FreePointer(theImportCodeButton_);
	FreePointer(theOKButton_);
	FreePointer(theCancelButton_);
	FreePointer(theHelpButton_);
	FreePointer(thePreviewLabel_);
	FreePointer(theParametersTable_);
	FreePointer(theFunctionsTree_);
	FreePointer(theCodeEditor_);
	FreePointer(theCompleter_);
}

void ForgBaseLib::FrgBase_PrptsWdgFieldDialog::FormWidget()
{
	QVBoxLayout* myLayout = new QVBoxLayout;
	theCodeEditor_ = new QCodeEditor();
	theFunctionsTree_ = new QTreeWidget(nullptr);
	theParametersTable_ = new QTableWidget();
	thePreviewLabel_ = new QLabel("");
	thePreviewLabel_->setStyleSheet("QLabel { border: 5px solid " + theLableColor_ + "; }");

	QHBoxLayout* buttonsLayout = new QHBoxLayout;
	theRealTimeCompilation_ = new QCheckBox("Real time compilation");
	theRealTimeCompilation_->setChecked(true);
	theImportCodeButton_ = new QPushButton("Import Code");
	theOKButton_ = new QPushButton("OK");
	theCancelButton_ = new QPushButton("Cancel");
	theHelpButton_ = new QPushButton("Help");

	buttonsLayout->addStretch(1);
	buttonsLayout->addWidget(theRealTimeCompilation_);
	buttonsLayout->addWidget(theImportCodeButton_);
	buttonsLayout->addWidget(theOKButton_);
	buttonsLayout->addWidget(theCancelButton_);
	buttonsLayout->addWidget(theHelpButton_);

	QSplitter* mySplitter1 = new QSplitter(this);
	QSplitter* mySplitter2 = new QSplitter(this);

	mySplitter2->addWidget(theFunctionsTree_);
	mySplitter2->addWidget(theParametersTable_);

	QWidget* container = new QWidget;
	QVBoxLayout* container_layout = new QVBoxLayout;
	container_layout->addWidget(mySplitter2);
	container->setLayout(container_layout);

	mySplitter1->setOrientation(Qt::Orientation::Vertical);
	mySplitter1->addWidget(theCodeEditor_);
	mySplitter1->addWidget(mySplitter2);
	myLayout->addWidget(mySplitter1);
	myLayout->addWidget(thePreviewLabel_);
	myLayout->addLayout(buttonsLayout);

	for (int i = 0; i < mySplitter1->count(); i++)
		mySplitter1->setCollapsible(i, false);
	for (int i = 0; i < mySplitter2->count(); i++)
		mySplitter2->setCollapsible(i, false);

	this->setLayout(myLayout);

	// CodeEditor
	theCompleter_ = new QExprtkCompleter(this);
	theCodeEditor_->setSyntaxStyle(QSyntaxStyle::defaultStyle());
	theCodeEditor_->setCompleter(theCompleter_);
	theCodeEditor_->setHighlighter(new QCXXHighlighter);

	FormParametersTable();
	FormFunctionsTree();

	connect(theCodeEditor_, &QCodeEditor::textChanged, this, &FrgBase_PrptsWdgFieldDialog::CodeEditorTextChangedSlot);
	connect(theRealTimeCompilation_, &QCheckBox::stateChanged, [this](int) {emit theCodeEditor_->textChanged(); });
	connect(theImportCodeButton_, &QPushButton::clicked, this, &FrgBase_PrptsWdgFieldDialog::ImportCodeButtonClickedSlot);
	connect(theOKButton_, &QPushButton::clicked, this, &FrgBase_PrptsWdgFieldDialog::onOK);
	connect(theCancelButton_, &QPushButton::clicked, [this](bool) {reject(); });
	connect(theFunctionsTree_, &QTreeWidget::itemDoubleClicked, [this](QTreeWidgetItem* item, int column)
		{
			theCodeEditor_->InsertCompletedCommand(item->text(0));
			theCodeEditor_->setFocus();
		});
	connect(theParametersTable_, &QTableWidget::itemDoubleClicked, [this](QTableWidgetItem* item)
		{
			int row = theParametersTable_->row(item);
			QString name = theParametersTable_->item(row, 0)->data(0).toString();
			theCodeEditor_->InsertCompletedCommand("${" + name + "}");
			theCodeEditor_->setFocus();
		});

	emit theCodeEditor_->textChanged();

	QString styleAddress = ":/styles/QCodeEditor/drakula.xml";
	QFile fl(styleAddress);

	if (!fl.open(QIODevice::ReadOnly))
	{
		return;
	}

	auto style = new QSyntaxStyle(this);

	if (!style->load(fl.readAll()))
	{
		delete style;
		return;
	}

	theCodeEditor_->setSyntaxStyle(style);

	this->setModal(true);
	SetGeometry(60);
	//this->adjustSize();
}

const std::vector<double>& ForgBaseLib::FrgBase_PrptsWdgFieldDialog::GetValues() const
{
	return theValues_;
}

void ForgBaseLib::FrgBase_PrptsWdgFieldDialog::SetValues(const std::vector<double>& values)
{
	theValues_.clear();

	theValues_.reserve(values.size());
	for (auto x : values)
		theValues_.push_back(x);
}

void ForgBaseLib::FrgBase_PrptsWdgFieldDialog::CodeEditorTextChangedSlot()
{
	thePreviewLabel_->setText("");

	QString str = RemoveVariablesDecorations(theCodeEditor_->toPlainText());

	/*auto myPrptsWdg = dynamic_cast<FrgBase_PrptsWdgField*>(this->parentWidget());
	if (myPrptsWdg)
	{
		auto myParentTItem = dynamic_cast<FrgBase_ToolsParameter_TItem*>(myPrptsWdg->GetParentTItem());
		if (myParentTItem)
		{
			QString strForTest = QString::fromStdString(str);
			if (strForTest.contains(myParentTItem->GetVariableName()))
			{
				thePreviewLabel_->setText("Cannot evaluate \"" + myParentTItem->GetVariableName() + "\" here.");
				thePreviewLabel_->setStyleSheet("QLabel {color : red;}");

				theOKButton_->setEnabled(false);
				return;
			}
		}
	}*/

	expression_t myExpression;
	myExpression.register_symbol_table(*theSymbolTableT_);

	QString strForTest = str;
	if (strForTest.size() > 2 && strForTest.at(0) == '[' && strForTest.at(strForTest.size() - 1) == ']')
	{
		thePreviewLabel_->setText(strForTest);
		str = "return " + str;
	}

	parser_t myParser;
	//myParser.settings().disable_all_assignment_ops();
	std::vector<std::string> variable_list;

	if (exprtk::collect_variables(str.toStdString(), variable_list))
	{
		const auto& myPrptsWdg = dynamic_cast<FrgBase_PrptsWdgField*>(this->parentWidget());
		if (myPrptsWdg)
		{
			const auto& myParentTItem = dynamic_cast<FrgBase_ToolsParameter_TItem*>(myPrptsWdg->GetParentTItem());
			if (myParentTItem)
			{
				for (const auto& var : variable_list)
					if (var == myParentTItem->GetVariableName().toStdString())
					{
						thePreviewLabel_->setText("Cannot use \"" + QString::fromStdString(var) + "\" here.");
						thePreviewLabel_->setStyleSheet("QLabel {color : red;}");

						theOKButton_->setEnabled(false);
					}
			}
		}
	}
	bool compiled = myParser.compile(str.toStdString(), myExpression);
	if (!compiled)
	{
		thePreviewLabel_->setText(QString::fromStdString(myParser.error()));
		thePreviewLabel_->setStyleSheet("QLabel {color : red;}");

		theOKButton_->setEnabled(false);
	}

	if (theRealTimeCompilation_->isChecked())
	{
		{
			thePreviewLabel_->setStyleSheet("QLabel {color : " + theLableColor_ + ";}");
			double result = myExpression.value();

			bool areValuesAcceptable = true;
			QString totalOutput("Output = ");

			if (myExpression.results().count())
			{
				typedef exprtk::results_context<double> results_context_t;
				typedef typename results_context_t::type_store_t type_t;
				typedef typename type_t::scalar_view scalar_t;
				typedef typename type_t::vector_view vector_t;
				typedef typename type_t::string_view string_t;

				const results_context_t& results = myExpression.results();

				if (results.count() > 1)
					totalOutput = "[";

				if (results.count() != theValues_.size())
				{
					thePreviewLabel_->setStyleSheet("QLabel {color : red;}");
					thePreviewLabel_->setText("You should enter " + QString::number(theValues_.size()) + (theValues_.size() > 1 ? " values." : " value."));
					return;
				}

				for (std::size_t i = 0; i < results.count(); ++i)
				{
					if (i > 0)
						totalOutput += ", ";

					type_t t = results[i];

					if (t.type == type_t::e_scalar)
					{
						auto value = scalar_t(t);

						if (std::isinf(value()))
							areValuesAcceptable = false;
						else if (std::isnan(value()))
							areValuesAcceptable = false;

						totalOutput += QString::number(value());
						theValues_[i] = value();
					}

					else if (t.type == type_t::e_vector)
					{
						QString output;

						auto value = vector_t(t);
						for (std::size_t iter = 0; iter < value.size(); iter++)
						{
							if (std::isinf(value[iter]))
								areValuesAcceptable = false;
							else if (std::isnan(value[iter]))
								areValuesAcceptable = false;

							if (iter == 0)
								output += ("[" + QString::number(value[iter]) + ", ");
							else if (iter == value.size() - 1)
								output += (QString::number(value[iter]) + "]");
							else
								output += (QString::number(value[iter]) + ", ");

							//theValues_.push_back(value[iter]);
						}

						totalOutput += output;
					}
					else if (t.type == type_t::e_string)
					{
						QString output = "\"";

						auto value = string_t(t);
						for (std::size_t iter = 0; iter < value.size(); iter++)
							output += value[iter];

						output += "\"";

						totalOutput += output;
					}
				}
				if (results.count() > 1)
					totalOutput += "]";
			}
			else
			{
				totalOutput += QString::number(result);

				if (std::isinf(result))
					areValuesAcceptable = false;
				else if (std::isnan(result))
					areValuesAcceptable = false;

				for (auto& x : theValues_)
					x = result;
			}

			thePreviewLabel_->setText(totalOutput);

			if (areValuesAcceptable)
				theOKButton_->setEnabled(true);
			else
				theOKButton_->setEnabled(false);
		}
	}
	else
	{
		//theOKButton_->setEnabled(false);
	}
}

void ForgBaseLib::FrgBase_PrptsWdgFieldDialog::onOK()
{
	auto scalarWidget = dynamic_cast<FrgBase_PrptsWdgFieldScalar*>(this->parentWidget());
	if (scalarWidget)
	{
		scalarWidget->SetValueString(theCodeEditor_->toPlainText().replace(QRegularExpression("\\s+"), QString()));
		scalarWidget->SetValue(theValues_[0]);

		if (theSymbolTableT_)
		{
			auto myPrptsWdg = dynamic_cast<FrgBase_PrptsWdgField*>(this->parentWidget());
			if (myPrptsWdg)
			{
				//theCodeEditor_->setText(myPrptsWdg->GetValueString());

				auto myParentTItem = dynamic_cast<FrgBase_ToolsParameter_TItem*>(myPrptsWdg->GetParentTItem());
				if (myParentTItem)
				{
					//theSymbolTableT_->get_variable(myParentTItem->GetVariableName().toStdString())->ref() = theValues_[0];
				}
			}
		}
	}

	auto vectorWidget = dynamic_cast<FrgBase_PrptsWdgFieldVector*>(this->parentWidget());
	if (vectorWidget)
	{
		vectorWidget->SetValueString(theCodeEditor_->toPlainText().replace(QRegularExpression("\\s+"), QString()));

		auto vectorVariant = dynamic_cast<FrgBase_PrptsVrntFieldVector*>(vectorWidget->GetVariantBasePtr());
		if (vectorVariant)
		{
			//vectorVariant->SetValue(theValues_);
			vectorVariant->SetValue(std::move(theValues_));
			//emit vectorVariant->ValueChangedSignal(theValues_);
		}
	}

	accept();
}

void ForgBaseLib::FrgBase_PrptsWdgFieldDialog::ImportCodeButtonClickedSlot()
{
	QString fileName = QFileDialog::getOpenFileName(this, "Open code or value", "", "Text (*.txt)");

	if (fileName.isEmpty())
		return;

	QFile f(fileName);
	if (!f.open(QFile::ReadOnly | QFile::Text)) return;
	QTextStream in(&f);
	QString data = in.readAll();

	theCodeEditor_->setText(data);
}

void ForgBaseLib::FrgBase_PrptsWdgFieldDialog::keyPressEvent(QKeyEvent* event)
{
	switch (event->key())
	{
	case Qt::Key_Escape:
		break;
	}
}

void ForgBaseLib::FrgBase_PrptsWdgFieldDialog::SetGeometry(int PercentageOfScreen)
{
	int x, y, w, h;
	QRect rect = QApplication::desktop()->screenGeometry();
	int screen_width = rect.width();
	int screen_height = rect.height();

	//Represent Percentage in decimals
	float PercentageOfScreenFloat = (float)PercentageOfScreen / 100;

	//Calculate w and h
	w = (PercentageOfScreenFloat * screen_width);
	h = (PercentageOfScreenFloat * screen_height);

	//Check for max and min size hints
	int minW = this->minimumWidth();
	int minH = this->minimumHeight();

	int maxW = this->maximumWidth();
	int maxH = this->maximumHeight();

	if (w < minW || h < minH)
	{
		w = minW;
		h = minH;
	}
	else if (w > maxW || h > maxH)
	{
		w = maxW;
		h = maxH;
	}

	//Now Calculate x and y
	x = screen_width / 2;
	x = x - w / 2;

	y = screen_height / 2;
	y = y - h / 2;

	this->setGeometry(x, y, w, h);
}

void ForgBaseLib::FrgBase_PrptsWdgFieldDialog::FormParametersTable()
{
	theParametersTable_->setColumnCount(3);
	theParametersTable_->setHorizontalHeaderLabels({ "Variable", "Value", "Type" });
	theParametersTable_->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
	theParametersTable_->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);

	auto myPrptsWdg = dynamic_cast<FrgBase_PrptsWdgField*>(this->parentWidget());
	if (myPrptsWdg)
	{
		theCodeEditor_->setText(myPrptsWdg->GetValueString());
		auto tc = theCodeEditor_->textCursor();
		tc.movePosition(QTextCursor::End);
		theCodeEditor_->setTextCursor(tc);

		auto myParentTItem = dynamic_cast<FrgBase_ToolsParameter_TItem*>(myPrptsWdg->GetParentTItem());
		if (myParentTItem)
		{
			if (!theSymbolTableT_)
			{
				auto symbolTableT = myParentTItem->GetSymbolTableT();
				if (symbolTableT)
					theSymbolTableT_ = symbolTableT;
			}
			if (theSymbolTableT_)
			{
				std::vector<std::string> variableList;
				theSymbolTableT_->get_variable_list(variableList);

				const auto& scalarVariant = dynamic_cast<ForgBaseLib::FrgBase_PrptsVrntFieldScalar*>(myPrptsWdg->GetVariantBasePtr());

				const auto& vectorVariant = dynamic_cast<ForgBaseLib::FrgBase_PrptsVrntFieldVector*>(myPrptsWdg->GetVariantBasePtr());

				bool isNeededToShowNonParentalParameters = true;
				if (scalarVariant)
					isNeededToShowNonParentalParameters = scalarVariant->ShowNonParentalParameters();
				else if (vectorVariant)
					isNeededToShowNonParentalParameters = vectorVariant->ShowNonParentalParameters();

				for (auto x : variableList)
				{
					if (myParentTItem->GetVariableName().toStdString() == x)
						continue;

					bool found = false;
					if (!isNeededToShowNonParentalParameters)
					{
						const auto& parentOfMyParentTItem = dynamic_cast<ForgBaseLib::FrgBase_TreeItem*>(myParentTItem->QTreeWidgetItem::parent());
						if (parentOfMyParentTItem)
						{
							const auto& myChildren = parentOfMyParentTItem->GetAllChildrenToTheRoot();
							for (const auto& myChild : myChildren)
							{
								const auto& parameterTItem = dynamic_cast<FrgBase_ToolsParameter_TItem*>(myChild);
								if (parameterTItem)
								{
									if (parameterTItem->GetVariableName().toStdString() == x)
									{
										found = true;
										break;
									}
								}
							}
						}
					}
					else
						found = true;

					if (found)
					{
						auto myVariable = theSymbolTableT_->get_variable(x);
						theParametersTable_->setRowCount(theParametersTable_->rowCount() + 1);

						auto item0 = new QTableWidgetItem(QString::fromStdString(x));
						theParametersTable_->setItem(theParametersTable_->rowCount() - 1, 0, item0);

						auto item1 = new QTableWidgetItem(QString::number(myVariable->value()));
						theParametersTable_->setItem(theParametersTable_->rowCount() - 1, 1, item1);

						auto item2 = new QTableWidgetItem(QString("SCALAR"));
						theParametersTable_->setItem(theParametersTable_->rowCount() - 1, 2, item2);

						item0->setFlags(Qt::ItemFlag::ItemIsSelectable | Qt::ItemFlag::ItemIsEnabled);
						item1->setFlags(Qt::ItemFlag::ItemIsSelectable | Qt::ItemFlag::ItemIsEnabled);
						item2->setFlags(Qt::ItemFlag::ItemIsSelectable | Qt::ItemFlag::ItemIsEnabled);

						theCompleter_->AddCompleter(QString::fromStdString(x));
					}
				}

				std::vector<std::string> vectorList;
				theSymbolTableT_->get_vector_list(vectorList);
				for (auto x : vectorList)
				{
					if (myParentTItem->GetVariableName().toStdString() == x)
						continue;

					auto myVector = theSymbolTableT_->get_vector(x);
					QString value;
					for (std::size_t i = 0; i < myVector->size(); i++)
					{
						if (i == 0)
							value += "[" + QString::number((*myVector->operator[](i)), 'G') + ", ";
						else if (i == myVector->size() - 1)
							value += QString::number(*myVector->operator[](i), 'G') + "]";
						else
							value += QString::number(*myVector->operator[](i), 'G') + ", ";
					}

					theParametersTable_->setRowCount(theParametersTable_->rowCount() + 1);

					auto item0 = new QTableWidgetItem(QString::fromStdString(x));
					theParametersTable_->setItem(theParametersTable_->rowCount() - 1, 0, item0);

					auto item1 = new QTableWidgetItem(value);
					theParametersTable_->setItem(theParametersTable_->rowCount() - 1, 1, item1);

					auto item2 = new QTableWidgetItem(QString("VECTOR"));
					theParametersTable_->setItem(theParametersTable_->rowCount() - 1, 2, item2);

					item0->setFlags(Qt::ItemFlag::ItemIsSelectable | Qt::ItemFlag::ItemIsEnabled);
					item1->setFlags(Qt::ItemFlag::ItemIsSelectable | Qt::ItemFlag::ItemIsEnabled);
					item2->setFlags(Qt::ItemFlag::ItemIsSelectable | Qt::ItemFlag::ItemIsEnabled);

					theCompleter_->AddCompleter(QString::fromStdString(x));
				}

				theParametersTable_->installEventFilter(this);

				theParametersTable_->horizontalHeader()->setStretchLastSection(true);
				theParametersTable_->setAlternatingRowColors(true);
			}
		}
	}
}

#define AddTItemToFunctionsTree(parentTItem, varName, title, description, example)		\
auto varName = new QTreeWidgetItem;														\
varName->setText(0, title);																\
varName->setText(1, description);														\
varName->setText(2, example);															\
parentTItem->addChild(varName);															\
varName->setToolTip(0, description);

void ForgBaseLib::FrgBase_PrptsWdgFieldDialog::FormFunctionsTree()
{
	/*if (theFunctionsTree_)
	{
		if (!theFunctionsTree_->children().isEmpty())
		{
			delete theFunctionsTree_;
			theFunctionsTree_ = nullptr;
		}
	}

	if (!theFunctionsTree_)
		theFunctionsTree_ = new QTreeWidget;*/

		// Form Tree
	theFunctionsTree_->setHeaderLabels({ "Function", "Description", "Example" });

	auto generalFunctionsTItem = new QTreeWidgetItem;
	generalFunctionsTItem->setText(0, "General Functions");
	generalFunctionsTItem->setIcon(0, QIcon(ICONTreeItemEye));
	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		absGFunc,
		"abs",
		"Absolute value of x.", "abs(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		avgGFunc,
		"avg",
		"Average of all the inputs.",
		"avg(x,y,z,w,u,v) == (x + y + z + w + u + v) / 6"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		ceilGFunc,
		"ceil",
		"Smallest integer that is greater than or equal to x.",
		"ceil(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		clampGFunc,
		"clamp",
		"Clamp x in range between r0 and r1, where r0 < r1.",
		"clamp(r0,x,r1)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		equalGFunc,
		"equal",
		"Equality test between x and y using normalised epsilon.",
		"equal(x, y)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		erfGFunc,
		"erf",
		"Error function of x.",
		"erf(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		erfcGFunc,
		"erfc",
		"Complimentary error function of x.",
		"erfc(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		expGFunc,
		"exp",
		"e to the power of x.",
		"exp(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		expm1GFunc,
		"expm1",
		"e to the power of x minus 1, where x is very small.",
		"expm1(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		floorGFunc,
		"floor",
		"Largest integer that is less than or equal to x.",
		"floor(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		fracGFunc,
		"frac",
		"Fractional portion of x.",
		"frac(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		hypotGFunc,
		"hypot",
		"Hypotenuse of x and y.",
		"hypot(x,y) == sqrt(x*x + y*y)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		iclampGFunc,
		"iclamp",
		"Inverse-clamp x outside of the range r0 and r1. Where r0 < r1.If x is within the range it will snap to the closest bound.",
		"iclamp(r0,x,r1)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		inrangeGFunc,
		"inrange",
		"In-range returns 'true' when x is within the range r0 and r1. Where r0 < r1.",
		"inrange(r0,x,r1)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		logGFunc,
		"log",
		"Natural logarithm of x.",
		"log(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		log10GFunc,
		"log10",
		"Base 10 logarithm of x.",
		"log10(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		log1pGFunc,
		"log1p",
		"Natural logarithm of 1 + x, where x is very small.",
		"log1p(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		log2GFunc,
		"log2",
		"Base 2 logarithm of x.",
		"log2(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		lognGFunc,
		"logn",
		"Base N logarithm of x. where n is a positive integer.",
		"logn(x, 8)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		maxGFunc,
		"max",
		"Largest value of all the inputs.",
		"max(x,y,z,w,u,v)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		minGFunc,
		"min",
		"Smallest value of all the inputs.",
		"min(x,y,z,w,u,v)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		modGFunc,
		"mod",
		"returns the remainder of a division.",
		"mod(56, 10) == 6"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		mulGFunc,
		"mul",
		"Product of all the inputs.",
		"mul(x,y,z,w,u,v,t) == (x * y * z * w * u * v * t)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		ncdfGFunc,
		"ncdf",
		"Normal cumulative distribution function.",
		"ncdf(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		powGFunc,
		"pow",
		"x to the power of y.",
		"pow(x,y) == x ^ y"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		rootGFunc,
		"root",
		"Nth-Root of x. where n is a positive integer.",
		"root(x,3) == x^(1/3)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		roundGFunc,
		"round",
		"Round x to the nearest integer.",
		"round(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		roundnGFunc,
		"roundn",
		"Round x to n decimal places. where n > 0 and is an integer.",
		"roundn(1.2345678,4) == 1.2346"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		sgnGFunc,
		"sgn",
		"Sign of x, -1 where x < 0, +1 where x > 0, else zero.",
		"sgn(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		sqrtGFunc,
		"sqrt",
		"Square root of x, where x >= 0.",
		"sqrt(x)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		sumGFunc,
		"sum",
		"Sum of all the inputs.",
		"sum(x,y,z,w,u,v,t) == (x + y + z + w + u + v + t)"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		swapGFunc,
		"swap",
		"Swap the values of the variables x and y and return the current value of y.",
		"swap(x,y) or x <=> y"
	);

	AddTItemToFunctionsTree
	(
		generalFunctionsTItem,
		truncGFunc,
		"trunc",
		"Integer portion of x.",
		"trunc(x)"
	);

	auto trigonometryFunctionsTItem = new QTreeWidgetItem;
	trigonometryFunctionsTItem->setText(0, "Trigonometry Functions");
	trigonometryFunctionsTItem->setIcon(0, QIcon(ICONTreeItemEye));
	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		acosTFunc,
		"acos",
		"Arc cosine of x expressed in radians. Interval [-1,+1]",
		"acos(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		acoshTFunc,
		"acosh",
		"Inverse hyperbolic cosine of x expressed in radians.",
		"acosh(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		asinTFunc,
		"asin",
		"Arc sine of x expressed in radians. Interval [-1,+1]",
		"asin(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		asinhTFunc,
		"asinh",
		"Inverse hyperbolic sine of x expressed in radians.",
		"asinh(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		atanTFunc,
		"atan",
		"Arc tangent of x expressed in radians. Interval [-1,+1]",
		"atan(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		atan2TFunc,
		"atan2",
		"Arc tangent of (x / y) expressed in radians. [-pi,+pi]",
		"atan2(x, y)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		atanhTFunc,
		"atanh",
		"Inverse hyperbolic tangent of x expressed in radians.",
		"atanh(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		cosTFunc,
		"cos",
		"Cosine of x. x is in radians.",
		"cos(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		coshTFunc,
		"cosh",
		"Hyperbolic cosine of x. x is in radians.",
		"cosh(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		cotTFunc,
		"cot",
		"Cotangent of x. x is in radians.",
		"cot(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		cscTFunc,
		"csc",
		"Cosecant of x. x is in radians.",
		"csc(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		secTFunc,
		"sec",
		"Secant of x. x is in radians.",
		"sec(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		sinTFunc,
		"sin",
		"Sine of x. x is in radians.",
		"sin(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		sincTFunc,
		"sinc",
		"Sine cardinal of x. x is in radians.",
		"sinc(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		sinhTFunc,
		"sinh",
		"Hyperbolic sine of x. x is in radians.",
		"sinh(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		tanTFunc,
		"tan",
		"Tangent of x. x is in radians.",
		"tan(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		tanhTFunc,
		"tanh",
		"Hyperbolic tangent of x. x is in radians.",
		"tanh(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		deg2radTFunc,
		"deg2rad",
		"Convert x from degrees to radians.",
		"deg2rad(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		deg2gradTFunc,
		"deg2grad",
		"Convert x from degrees to gradians.",
		"deg2grad(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		rad2degTFunc,
		"rad2deg",
		"Convert x from radians to degrees.",
		"rad2deg(x)"
	);

	AddTItemToFunctionsTree
	(
		trigonometryFunctionsTItem,
		grad2degTFunc,
		"grad2deg",
		"Convert x from gradians to degrees.",
		"grad2deg(x)"
	);

	theFunctionsTree_->addTopLevelItem(generalFunctionsTItem);
	theFunctionsTree_->addTopLevelItem(trigonometryFunctionsTItem);

	theFunctionsTree_->expandAll();
	for (int iColumn = 0; iColumn < theFunctionsTree_->columnCount(); iColumn++)
		theFunctionsTree_->resizeColumnToContents(iColumn);
	theFunctionsTree_->collapseAll();
}

QString ForgBaseLib::FrgBase_PrptsWdgFieldDialog::RemoveVariablesDecorations(const QString& str)
{
	QString result = str;
	bool started = false;
	int i = 0;
	for (const auto& c : result)
	{
		if (c == "$")
		{
			result.remove(i, 1);
			started = true;
		}

		if (started)
		{
			if (c == "{")
				result.remove(i, 1);
			else if (c == "}")
			{
				result.remove(i, 1);
				started = false;
			}
		}

		i++;
	}

	return std::move(result);
}

bool ForgBaseLib::FrgBase_PrptsWdgFieldDialog::eventFilter(QObject* watched, QEvent* event)
{
	return QDialog::eventFilter(watched, event);
}