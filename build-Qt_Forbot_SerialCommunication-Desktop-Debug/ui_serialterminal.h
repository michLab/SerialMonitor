/********************************************************************************
** Form generated from reading UI file 'serialterminal.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALTERMINAL_H
#define UI_SERIALTERMINAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_SerialTerminal
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBoxLogs;
    QGridLayout *gridLayout_3;
    QTextEdit *textEditLogs;
    QPushButton *pushButtonClean;
    QGroupBox *groupBoxConnection;
    QGridLayout *gridLayout;
    QPushButton *pushButtonConnect;
    QPushButton *pushButtonSearch;
    QComboBox *comboBoxDevices;
    QLabel *labelBaudrate;
    QPushButton *pushButtonDisconnect;
    QComboBox *comboBoxBaudrate;

    void setupUi(QDialog *SerialTerminal)
    {
        if (SerialTerminal->objectName().isEmpty())
            SerialTerminal->setObjectName(QStringLiteral("SerialTerminal"));
        SerialTerminal->resize(789, 381);
        gridLayout_2 = new QGridLayout(SerialTerminal);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBoxLogs = new QGroupBox(SerialTerminal);
        groupBoxLogs->setObjectName(QStringLiteral("groupBoxLogs"));
        gridLayout_3 = new QGridLayout(groupBoxLogs);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        textEditLogs = new QTextEdit(groupBoxLogs);
        textEditLogs->setObjectName(QStringLiteral("textEditLogs"));

        gridLayout_3->addWidget(textEditLogs, 0, 0, 1, 1);

        pushButtonClean = new QPushButton(groupBoxLogs);
        pushButtonClean->setObjectName(QStringLiteral("pushButtonClean"));

        gridLayout_3->addWidget(pushButtonClean, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBoxLogs, 1, 0, 1, 1);

        groupBoxConnection = new QGroupBox(SerialTerminal);
        groupBoxConnection->setObjectName(QStringLiteral("groupBoxConnection"));
        gridLayout = new QGridLayout(groupBoxConnection);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButtonConnect = new QPushButton(groupBoxConnection);
        pushButtonConnect->setObjectName(QStringLiteral("pushButtonConnect"));

        gridLayout->addWidget(pushButtonConnect, 1, 0, 1, 1);

        pushButtonSearch = new QPushButton(groupBoxConnection);
        pushButtonSearch->setObjectName(QStringLiteral("pushButtonSearch"));

        gridLayout->addWidget(pushButtonSearch, 0, 0, 1, 1);

        comboBoxDevices = new QComboBox(groupBoxConnection);
        comboBoxDevices->setObjectName(QStringLiteral("comboBoxDevices"));

        gridLayout->addWidget(comboBoxDevices, 0, 1, 1, 1);

        labelBaudrate = new QLabel(groupBoxConnection);
        labelBaudrate->setObjectName(QStringLiteral("labelBaudrate"));

        gridLayout->addWidget(labelBaudrate, 0, 2, 1, 1);

        pushButtonDisconnect = new QPushButton(groupBoxConnection);
        pushButtonDisconnect->setObjectName(QStringLiteral("pushButtonDisconnect"));

        gridLayout->addWidget(pushButtonDisconnect, 1, 1, 1, 1);

        comboBoxBaudrate = new QComboBox(groupBoxConnection);
        comboBoxBaudrate->setObjectName(QStringLiteral("comboBoxBaudrate"));

        gridLayout->addWidget(comboBoxBaudrate, 0, 3, 1, 1);


        gridLayout_2->addWidget(groupBoxConnection, 0, 0, 1, 1);


        retranslateUi(SerialTerminal);

        QMetaObject::connectSlotsByName(SerialTerminal);
    } // setupUi

    void retranslateUi(QDialog *SerialTerminal)
    {
        SerialTerminal->setWindowTitle(QApplication::translate("SerialTerminal", "SerialTerminal", Q_NULLPTR));
        groupBoxLogs->setTitle(QApplication::translate("SerialTerminal", "Logs", Q_NULLPTR));
        pushButtonClean->setText(QApplication::translate("SerialTerminal", "Clean", Q_NULLPTR));
        groupBoxConnection->setTitle(QApplication::translate("SerialTerminal", "Connection", Q_NULLPTR));
        pushButtonConnect->setText(QApplication::translate("SerialTerminal", "Connect", Q_NULLPTR));
        pushButtonSearch->setText(QApplication::translate("SerialTerminal", "Search", Q_NULLPTR));
        labelBaudrate->setText(QApplication::translate("SerialTerminal", "Baudrate:", Q_NULLPTR));
        pushButtonDisconnect->setText(QApplication::translate("SerialTerminal", "Disconnect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SerialTerminal: public Ui_SerialTerminal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALTERMINAL_H
