/********************************************************************************
** Form generated from reading UI file 'EnvironmentDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENVIRONMENTDIALOG_H
#define UI_ENVIRONMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EnvironmentDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *Search;
    QSpacerItem *horizontalSpacer;
    QPushButton *AddEntry;
    QPushButton *RemoveEntry;
    QTreeView *Environment;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EnvironmentDialog)
    {
        if (EnvironmentDialog->objectName().isEmpty())
            EnvironmentDialog->setObjectName(QStringLiteral("EnvironmentDialog"));
        EnvironmentDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(EnvironmentDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(EnvironmentDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        Search = new QLineEdit(EnvironmentDialog);
        Search->setObjectName(QStringLiteral("Search"));

        horizontalLayout->addWidget(Search);

        horizontalSpacer = new QSpacerItem(12, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        AddEntry = new QPushButton(EnvironmentDialog);
        AddEntry->setObjectName(QStringLiteral("AddEntry"));
        QIcon icon;
        QString iconThemeName = QStringLiteral("list-add");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral(":/Icons/Plus16.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        AddEntry->setIcon(icon);

        horizontalLayout->addWidget(AddEntry);

        RemoveEntry = new QPushButton(EnvironmentDialog);
        RemoveEntry->setObjectName(QStringLiteral("RemoveEntry"));
        QIcon icon1;
        iconThemeName = QStringLiteral("list-remove");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QStringLiteral(":/Icons/Delete16.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        RemoveEntry->setIcon(icon1);

        horizontalLayout->addWidget(RemoveEntry);


        verticalLayout->addLayout(horizontalLayout);

        Environment = new QTreeView(EnvironmentDialog);
        Environment->setObjectName(QStringLiteral("Environment"));

        verticalLayout->addWidget(Environment);

        buttonBox = new QDialogButtonBox(EnvironmentDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(Search);
#endif // QT_NO_SHORTCUT

        retranslateUi(EnvironmentDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EnvironmentDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EnvironmentDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EnvironmentDialog);
    } // setupUi

    void retranslateUi(QDialog *EnvironmentDialog)
    {
        EnvironmentDialog->setWindowTitle(QApplication::translate("EnvironmentDialog", "Environment Editor", Q_NULLPTR));
        label->setText(QApplication::translate("EnvironmentDialog", "S&earch:", Q_NULLPTR));
        AddEntry->setText(QApplication::translate("EnvironmentDialog", "&Add Entry", Q_NULLPTR));
        RemoveEntry->setText(QApplication::translate("EnvironmentDialog", "&Remove Entry", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EnvironmentDialog: public Ui_EnvironmentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENVIRONMENTDIALOG_H
