/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QWidget *topWidget;
    QGridLayout *gridLayout;
    QLabel *generationLabel;
    QLabel *populationLabel;
    QLabel *boardSizeLabel;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QWidget *boardWidget;
    QWidget *bottomWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *nextButton;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *resetButton;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *speedLabel;
    QSlider *speedSlider;
    QLabel *label;
    QWidget *rightWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QToolButton *helpButton;
    QTextEdit *seedEditor;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1013, 662);
        MainWindow->setMinimumSize(QSize(0, 60));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        topWidget = new QWidget(centralwidget);
        topWidget->setObjectName("topWidget");
        topWidget->setMinimumSize(QSize(0, 60));
        topWidget->setMaximumSize(QSize(16777215, 180));
        gridLayout = new QGridLayout(topWidget);
        gridLayout->setObjectName("gridLayout");
        generationLabel = new QLabel(topWidget);
        generationLabel->setObjectName("generationLabel");
        generationLabel->setMinimumSize(QSize(140, 0));
        generationLabel->setMaximumSize(QSize(180, 16777215));

        gridLayout->addWidget(generationLabel, 0, 1, 1, 1);

        populationLabel = new QLabel(topWidget);
        populationLabel->setObjectName("populationLabel");
        populationLabel->setMinimumSize(QSize(140, 0));
        populationLabel->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(populationLabel, 1, 1, 1, 1);

        boardSizeLabel = new QLabel(topWidget);
        boardSizeLabel->setObjectName("boardSizeLabel");
        boardSizeLabel->setMinimumSize(QSize(140, 40));
        boardSizeLabel->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(boardSizeLabel, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);


        verticalLayout->addWidget(topWidget);

        boardWidget = new QWidget(centralwidget);
        boardWidget->setObjectName("boardWidget");

        verticalLayout->addWidget(boardWidget);

        bottomWidget = new QWidget(centralwidget);
        bottomWidget->setObjectName("bottomWidget");
        bottomWidget->setMinimumSize(QSize(0, 80));
        bottomWidget->setBaseSize(QSize(0, 100));
        horizontalLayout = new QHBoxLayout(bottomWidget);
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(50, -1, 50, -1);
        nextButton = new QPushButton(bottomWidget);
        nextButton->setObjectName("nextButton");
        nextButton->setMinimumSize(QSize(50, 50));

        horizontalLayout->addWidget(nextButton);

        startButton = new QPushButton(bottomWidget);
        startButton->setObjectName("startButton");
        startButton->setMinimumSize(QSize(50, 50));
        startButton->setMaximumSize(QSize(150, 50));

        horizontalLayout->addWidget(startButton);

        stopButton = new QPushButton(bottomWidget);
        stopButton->setObjectName("stopButton");
        stopButton->setMinimumSize(QSize(50, 50));
        stopButton->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(stopButton);

        resetButton = new QPushButton(bottomWidget);
        resetButton->setObjectName("resetButton");
        resetButton->setMinimumSize(QSize(50, 50));
        resetButton->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(resetButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        widget = new QWidget(bottomWidget);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(50, 50));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        speedLabel = new QLabel(widget);
        speedLabel->setObjectName("speedLabel");
        speedLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(speedLabel, 0, 1, 1, 2);

        speedSlider = new QSlider(widget);
        speedSlider->setObjectName("speedSlider");
        speedSlider->setMinimum(1);
        speedSlider->setMaximum(100);
        speedSlider->setSingleStep(10);
        speedSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(speedSlider, 1, 2, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 1, 1, 1, 1);


        horizontalLayout->addWidget(widget);

        horizontalLayout->setStretch(4, 2);

        verticalLayout->addWidget(bottomWidget);

        verticalLayout->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout);

        rightWidget = new QWidget(centralwidget);
        rightWidget->setObjectName("rightWidget");
        rightWidget->setMinimumSize(QSize(50, 0));
        verticalLayout_2 = new QVBoxLayout(rightWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        label_2 = new QLabel(rightWidget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        helpButton = new QToolButton(rightWidget);
        helpButton->setObjectName("helpButton");

        horizontalLayout_2->addWidget(helpButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        seedEditor = new QTextEdit(rightWidget);
        seedEditor->setObjectName("seedEditor");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(seedEditor->sizePolicy().hasHeightForWidth());
        seedEditor->setSizePolicy(sizePolicy);
        seedEditor->setMinimumSize(QSize(50, 50));

        verticalLayout_2->addWidget(seedEditor);


        horizontalLayout_3->addWidget(rightWidget);

        horizontalLayout_3->setStretch(0, 14);
        horizontalLayout_3->setStretch(1, 2);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        generationLabel->setText(QCoreApplication::translate("MainWindow", "Generation: 0", nullptr));
        populationLabel->setText(QCoreApplication::translate("MainWindow", "Population: 0", nullptr));
        boardSizeLabel->setText(QCoreApplication::translate("MainWindow", "Board Size: 0 x 0", nullptr));
        nextButton->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Auto", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        speedLabel->setText(QCoreApplication::translate("MainWindow", "FPS: 1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "FPS", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Seed Editor", nullptr));
#if QT_CONFIG(tooltip)
        helpButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        helpButton->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        seedEditor->setPlaceholderText(QCoreApplication::translate("MainWindow", "Place your seed here", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
