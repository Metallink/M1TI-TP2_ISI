/********************************************************************************
** Form generated from reading UI file 'my_gui_form.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MY_GUI_FORM_H
#define UI_MY_GUI_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "my_qglviewer.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionOpen;
    QAction *actionAbout;
    QAction *actionOpen_off;
    QWidget *centralwidget;
    QVBoxLayout *vboxLayout;
    MyQGLViewer *viewer;
    QHBoxLayout *hboxLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;
    QSpacerItem *spacerItem;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_wireframe;
    QCheckBox *checkBox_smooth;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_normals;
    QCheckBox *checkBox_flipnormals;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QDoubleSpinBox *radiusSpinBox;
    QMenuBar *menubar;
    QMenu *menuHelp;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionOpen_off = new QAction(MainWindow);
        actionOpen_off->setObjectName(QString::fromUtf8("actionOpen_off"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        vboxLayout = new QVBoxLayout(centralwidget);
        vboxLayout->setSpacing(6);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(3, 3, 3, 0);
        viewer = new MyQGLViewer(centralwidget);
        viewer->setObjectName(QString::fromUtf8("viewer"));

        vboxLayout->addWidget(viewer);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(1);
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout_2->addWidget(checkBox);

        checkBox_3 = new QCheckBox(centralwidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setEnabled(true);

        verticalLayout_2->addWidget(checkBox_3);

        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        verticalLayout_2->addWidget(checkBox_2);


        horizontalLayout->addLayout(verticalLayout_2);


        hboxLayout->addLayout(horizontalLayout);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkBox_wireframe = new QCheckBox(centralwidget);
        checkBox_wireframe->setObjectName(QString::fromUtf8("checkBox_wireframe"));

        verticalLayout->addWidget(checkBox_wireframe);

        checkBox_smooth = new QCheckBox(centralwidget);
        checkBox_smooth->setObjectName(QString::fromUtf8("checkBox_smooth"));

        verticalLayout->addWidget(checkBox_smooth);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        checkBox_normals = new QCheckBox(centralwidget);
        checkBox_normals->setObjectName(QString::fromUtf8("checkBox_normals"));

        horizontalLayout_2->addWidget(checkBox_normals);

        checkBox_flipnormals = new QCheckBox(centralwidget);
        checkBox_flipnormals->setObjectName(QString::fromUtf8("checkBox_flipnormals"));
        checkBox_flipnormals->setSizeIncrement(QSize(0, 0));
        QFont font;
        font.setPointSize(8);
        checkBox_flipnormals->setFont(font);

        horizontalLayout_2->addWidget(checkBox_flipnormals);


        verticalLayout->addLayout(horizontalLayout_2);


        hboxLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(horizontalSpacer);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label);

        radiusSpinBox = new QDoubleSpinBox(centralwidget);
        radiusSpinBox->setObjectName(QString::fromUtf8("radiusSpinBox"));
        radiusSpinBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        radiusSpinBox->setMinimum(0.1);
        radiusSpinBox->setMaximum(5);
        radiusSpinBox->setSingleStep(0.5);

        horizontalLayout_5->addWidget(radiusSpinBox);


        verticalLayout_4->addLayout(horizontalLayout_5);


        hboxLayout->addLayout(verticalLayout_4);


        vboxLayout->addLayout(hboxLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionAbout);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);
        QObject::connect(checkBox, SIGNAL(clicked(bool)), viewer, SLOT(setFPSIsDisplayed(bool)));
        QObject::connect(viewer, SIGNAL(FPSIsDisplayedChanged(bool)), checkBox, SLOT(setChecked(bool)));
        QObject::connect(checkBox_2, SIGNAL(clicked(bool)), viewer, SLOT(setGridIsDrawn(bool)));
        QObject::connect(viewer, SIGNAL(gridIsDrawnChanged(bool)), checkBox_2, SLOT(setChecked(bool)));
        QObject::connect(checkBox_3, SIGNAL(clicked(bool)), viewer, SLOT(setAxisIsDrawn(bool)));
        QObject::connect(viewer, SIGNAL(axisIsDrawnChanged(bool)), checkBox_3, SLOT(setChecked(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ISIviewer", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionOpen_off->setText(QApplication::translate("MainWindow", "open .off ...", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "FPS", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("MainWindow", "Axis", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("MainWindow", "Grid", 0, QApplication::UnicodeUTF8));
        checkBox_wireframe->setText(QApplication::translate("MainWindow", "wireframe", 0, QApplication::UnicodeUTF8));
        checkBox_smooth->setText(QApplication::translate("MainWindow", "smooth", 0, QApplication::UnicodeUTF8));
        checkBox_normals->setText(QApplication::translate("MainWindow", "normals", 0, QApplication::UnicodeUTF8));
        checkBox_flipnormals->setText(QApplication::translate("MainWindow", "flipped", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Radius :", 0, QApplication::UnicodeUTF8));
        radiusSpinBox->setPrefix(QString());
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MY_GUI_FORM_H
