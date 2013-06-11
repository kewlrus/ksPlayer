/********************************************************************************
** Form generated from reading UI file 'testproject.ui'
**
** Created: Tue 23. Apr 10:37:07 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTPROJECT_H
#define UI_TESTPROJECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>
#include <phonon/seekslider.h>
#include <phonon/videoplayer.h>
#include <phonon/volumeslider.h>

QT_BEGIN_NAMESPACE

class Ui_TestProjectClass
{
public:
    QWidget *centralWidget;
    QWebView *webView;
    QPushButton *pushButton;
    Phonon::VolumeSlider *volumeSlider;
    Phonon::VideoPlayer *videoPlayer;
    QPushButton *pushButton_2;
    QTextBrowser *textBrowser;
    QLabel *label;
    QTextEdit *MusicPathTextEdit;
    QCheckBox *TrueRndCheckBox;
    Phonon::SeekSlider *seekSlider;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *ButtonPause;
    QPushButton *PreviousButton;
    QPushButton *ButtonStop;
    QPushButton *ButtonNext;
    QPushButton *PlayButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestProjectClass)
    {
        if (TestProjectClass->objectName().isEmpty())
            TestProjectClass->setObjectName(QString::fromUtf8("TestProjectClass"));
        TestProjectClass->resize(421, 535);
        TestProjectClass->setMinimumSize(QSize(421, 535));
        TestProjectClass->setMaximumSize(QSize(421, 535));
        centralWidget = new QWidget(TestProjectClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        webView = new QWebView(centralWidget);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setEnabled(true);
        webView->setGeometry(QRect(10, 450, 91, 41));
        webView->setUrl(QUrl(QString::fromUtf8("http://www.random.org/integers/?num=1&min=1&max=6&col=1&base=10&format=plain&rnd=new")));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(560, 380, 75, 23));
        volumeSlider = new Phonon::VolumeSlider(centralWidget);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        volumeSlider->setGeometry(QRect(10, 50, 401, 22));
        videoPlayer = new Phonon::VideoPlayer(centralWidget);
        videoPlayer->setObjectName(QString::fromUtf8("videoPlayer"));
        videoPlayer->setEnabled(true);
        videoPlayer->setGeometry(QRect(590, 490, 491, 351));
        videoPlayer->setMouseTracking(false);
        videoPlayer->setContextMenuPolicy(Qt::DefaultContextMenu);
        videoPlayer->setAcceptDrops(false);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 170, 75, 23));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setEnabled(true);
        textBrowser->setGeometry(QRect(10, 220, 401, 221));
        textBrowser->setReadOnly(true);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 130, 61, 16));
        MusicPathTextEdit = new QTextEdit(centralWidget);
        MusicPathTextEdit->setObjectName(QString::fromUtf8("MusicPathTextEdit"));
        MusicPathTextEdit->setGeometry(QRect(70, 120, 341, 31));
        TrueRndCheckBox = new QCheckBox(centralWidget);
        TrueRndCheckBox->setObjectName(QString::fromUtf8("TrueRndCheckBox"));
        TrueRndCheckBox->setGeometry(QRect(10, 170, 271, 17));
        TrueRndCheckBox->setChecked(true);
        seekSlider = new Phonon::SeekSlider(centralWidget);
        seekSlider->setObjectName(QString::fromUtf8("seekSlider"));
        seekSlider->setGeometry(QRect(10, 90, 401, 20));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 401, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ButtonPause = new QPushButton(layoutWidget);
        ButtonPause->setObjectName(QString::fromUtf8("ButtonPause"));

        horizontalLayout->addWidget(ButtonPause);

        PreviousButton = new QPushButton(layoutWidget);
        PreviousButton->setObjectName(QString::fromUtf8("PreviousButton"));

        horizontalLayout->addWidget(PreviousButton);

        ButtonStop = new QPushButton(layoutWidget);
        ButtonStop->setObjectName(QString::fromUtf8("ButtonStop"));

        horizontalLayout->addWidget(ButtonStop);

        ButtonNext = new QPushButton(layoutWidget);
        ButtonNext->setObjectName(QString::fromUtf8("ButtonNext"));

        horizontalLayout->addWidget(ButtonNext);

        PlayButton = new QPushButton(layoutWidget);
        PlayButton->setObjectName(QString::fromUtf8("PlayButton"));

        horizontalLayout->addWidget(PlayButton);

        TestProjectClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TestProjectClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 421, 21));
        TestProjectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestProjectClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TestProjectClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TestProjectClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TestProjectClass->setStatusBar(statusBar);

        retranslateUi(TestProjectClass);

        QMetaObject::connectSlotsByName(TestProjectClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestProjectClass)
    {
        TestProjectClass->setWindowTitle(QApplication::translate("TestProjectClass", "TestProject", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("TestProjectClass", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("TestProjectClass", "Refresh BD", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TestProjectClass", "Music path", 0, QApplication::UnicodeUTF8));
        TrueRndCheckBox->setText(QApplication::translate("TestProjectClass", "Use True random (internet connection required)", 0, QApplication::UnicodeUTF8));
        ButtonPause->setText(QApplication::translate("TestProjectClass", "Pause", 0, QApplication::UnicodeUTF8));
        PreviousButton->setText(QApplication::translate("TestProjectClass", "Previous", 0, QApplication::UnicodeUTF8));
        ButtonStop->setText(QApplication::translate("TestProjectClass", "Stop", 0, QApplication::UnicodeUTF8));
        ButtonNext->setText(QApplication::translate("TestProjectClass", "Next", 0, QApplication::UnicodeUTF8));
        PlayButton->setText(QApplication::translate("TestProjectClass", "Play", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TestProjectClass: public Ui_TestProjectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTPROJECT_H
