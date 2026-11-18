/********************************************************************************
** Form generated from reading UI file 'envgui.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENVGUI_H
#define UI_ENVGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EnvGui
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonSelectExecutable;
    QPushButton *pushButtonAddEnvVariable;
    QPushButton *pushButtonLaunchApp;
    QTableWidget *tableWidgetEnvVars;
    QTextEdit *textEditOutput;
    QLabel *labelSelectedExecutablePath;

    void setupUi(QWidget *EnvGui)
    {
        if (EnvGui->objectName().isEmpty())
            EnvGui->setObjectName("EnvGui");
        EnvGui->resize(734, 487);
        verticalLayoutWidget = new QWidget(EnvGui);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(9, 9, 721, 471));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonSelectExecutable = new QPushButton(verticalLayoutWidget);
        pushButtonSelectExecutable->setObjectName("pushButtonSelectExecutable");

        verticalLayout->addWidget(pushButtonSelectExecutable);

        pushButtonAddEnvVariable = new QPushButton(verticalLayoutWidget);
        pushButtonAddEnvVariable->setObjectName("pushButtonAddEnvVariable");

        verticalLayout->addWidget(pushButtonAddEnvVariable);

        pushButtonLaunchApp = new QPushButton(verticalLayoutWidget);
        pushButtonLaunchApp->setObjectName("pushButtonLaunchApp");

        verticalLayout->addWidget(pushButtonLaunchApp);

        tableWidgetEnvVars = new QTableWidget(verticalLayoutWidget);
        if (tableWidgetEnvVars->columnCount() < 2)
            tableWidgetEnvVars->setColumnCount(2);
        tableWidgetEnvVars->setObjectName("tableWidgetEnvVars");
        tableWidgetEnvVars->setColumnCount(2);
        tableWidgetEnvVars->horizontalHeader()->setMinimumSectionSize(358);
        tableWidgetEnvVars->horizontalHeader()->setDefaultSectionSize(358);

        verticalLayout->addWidget(tableWidgetEnvVars);

        textEditOutput = new QTextEdit(verticalLayoutWidget);
        textEditOutput->setObjectName("textEditOutput");

        verticalLayout->addWidget(textEditOutput);

        labelSelectedExecutablePath = new QLabel(verticalLayoutWidget);
        labelSelectedExecutablePath->setObjectName("labelSelectedExecutablePath");

        verticalLayout->addWidget(labelSelectedExecutablePath);


        retranslateUi(EnvGui);

        QMetaObject::connectSlotsByName(EnvGui);
    } // setupUi

    void retranslateUi(QWidget *EnvGui)
    {
        EnvGui->setWindowTitle(QCoreApplication::translate("EnvGui", "Form", nullptr));
        pushButtonSelectExecutable->setText(QCoreApplication::translate("EnvGui", "Select executable", nullptr));
        pushButtonAddEnvVariable->setText(QCoreApplication::translate("EnvGui", "Add Environment Variable", nullptr));
        pushButtonLaunchApp->setText(QCoreApplication::translate("EnvGui", "Launch Application", nullptr));
        labelSelectedExecutablePath->setText(QCoreApplication::translate("EnvGui", "Selected executable:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnvGui: public Ui_EnvGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENVGUI_H
