/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <codeeditor.h>
#include <console.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNewFile;
    QAction *actionOpen;
    QAction *actionSelectAll;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionAbout;
    QAction *actionDocument;
    QAction *actionSave_File;
    QAction *actionRun;
    QAction *actionSetting;
    QWidget *centralWidget;
    CodeEditor *editor;
    Console *outputText;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuEdit_O;
    QMenu *menuHelp_H;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(636, 496);
        actionNewFile = new QAction(MainWindow);
        actionNewFile->setObjectName(QString::fromUtf8("actionNewFile"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("assets/New.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewFile->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("assets/Open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSelectAll = new QAction(MainWindow);
        actionSelectAll->setObjectName(QString::fromUtf8("actionSelectAll"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("assets/Undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon2);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("assets/Redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon3);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("assets/About.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon4);
        actionDocument = new QAction(MainWindow);
        actionDocument->setObjectName(QString::fromUtf8("actionDocument"));
        actionSave_File = new QAction(MainWindow);
        actionSave_File->setObjectName(QString::fromUtf8("actionSave_File"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("assets/Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_File->setIcon(icon5);
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("assets/Run.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon6);
        actionSetting = new QAction(MainWindow);
        actionSetting->setObjectName(QString::fromUtf8("actionSetting"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("assets/Setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetting->setIcon(icon7);
        actionSetting->setVisible(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        editor = new CodeEditor(centralWidget);
        editor->setObjectName(QString::fromUtf8("editor"));
        editor->setGeometry(QRect(10, 0, 611, 331));
        outputText = new Console(centralWidget);
        outputText->setObjectName(QString::fromUtf8("outputText"));
        outputText->setGeometry(QRect(10, 340, 611, 81));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 636, 25));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuEdit_O = new QMenu(menuBar);
        menuEdit_O->setObjectName(QString::fromUtf8("menuEdit_O"));
        menuHelp_H = new QMenu(menuBar);
        menuHelp_H->setObjectName(QString::fromUtf8("menuHelp_H"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setIconSize(QSize(24, 24));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuEdit_O->menuAction());
        menuBar->addAction(menuHelp_H->menuAction());
        menu->addAction(actionNewFile);
        menu->addAction(actionOpen);
        menu->addAction(actionSave_File);
        menuEdit_O->addAction(actionSelectAll);
        menuEdit_O->addAction(actionUndo);
        menuEdit_O->addAction(actionRedo);
        menuHelp_H->addAction(actionAbout);
        menuHelp_H->addAction(actionDocument);
        mainToolBar->addAction(actionNewFile);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave_File);
        mainToolBar->addAction(actionUndo);
        mainToolBar->addAction(actionRedo);
        mainToolBar->addAction(actionRun);
        mainToolBar->addAction(actionSetting);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Editor", nullptr));
        actionNewFile->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
#ifndef QT_NO_TOOLTIP
        actionNewFile->setToolTip(QApplication::translate("MainWindow", "\346\226\260\345\273\272\344\270\200\344\270\252C++\344\273\243\347\240\201\346\226\207\344\273\266", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionNewFile->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200...", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266...", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSelectAll->setText(QApplication::translate("MainWindow", "\345\205\250\351\200\211", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSelectAll->setToolTip(QApplication::translate("MainWindow", "\351\200\211\346\213\251\345\205\250\351\203\250\346\226\207\346\234\254", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionSelectAll->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_NO_SHORTCUT
        actionUndo->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200", nullptr));
#ifndef QT_NO_SHORTCUT
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionRedo->setText(QApplication::translate("MainWindow", "\351\207\215\345\201\232", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216Editor", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "\345\205\263\344\272\216Editor", nullptr));
#endif // QT_NO_TOOLTIP
        actionDocument->setText(QApplication::translate("MainWindow", "\350\257\264\346\230\216\346\226\207\346\241\243", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDocument->setToolTip(QApplication::translate("MainWindow", "\346\237\245\347\234\213\350\257\264\346\230\216\346\226\207\346\241\243", nullptr));
#endif // QT_NO_TOOLTIP
        actionSave_File->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave_File->setToolTip(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionSave_File->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionRun->setText(QApplication::translate("MainWindow", "\350\277\220\350\241\214", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRun->setToolTip(QApplication::translate("MainWindow", "\347\274\226\350\257\221\345\271\266\350\277\220\350\241\214\344\273\243\347\240\201", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionRun->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        actionSetting->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSetting->setToolTip(QApplication::translate("MainWindow", "\346\233\264\346\224\271\347\274\226\350\276\221\345\231\250\347\232\204\350\256\276\347\275\256", nullptr));
#endif // QT_NO_TOOLTIP
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menuEdit_O->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menuHelp_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
