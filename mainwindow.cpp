#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    m_boardPanel = new GameOfLifePanel(ui->boardWidget);
    {
        m_boardPanel->CreateBoard(100, 100);
    }
    QBoxLayout* layout = new QBoxLayout(QBoxLayout::TopToBottom);
    layout->addWidget(m_boardPanel, 1);
    ui->boardWidget->setLayout(layout);

    QString tooltip(
        "Use the following pattern to place seed properly: x, y\n"
        "where x is the row value, y is the column value\n"
        "Each seed should be place one in a row\n"
        "For example: \n"
        "2,3\n"
        "10,2\n"
        "6,14\n"
        "\n"
        "Any invalid seed will not be update"
    );


    //connect
    connect(ui->startButton, &QPushButton::clicked, m_boardPanel, &GameOfLifePanel::StartGame);
    connect(ui->stopButton, &QPushButton::clicked, m_boardPanel, &GameOfLifePanel::PauseGame);
    connect(ui->resetButton, &QPushButton::clicked, m_boardPanel, &GameOfLifePanel::ResetGame);
    connect(m_boardPanel, &GameOfLifePanel::UpdateFinish, ui->generationLabel, [=](){
        ui->generationLabel->setText("Generation: " + QString::number(m_boardPanel->GetGenerationCount()));
    });
    connect(m_boardPanel, &GameOfLifePanel::UpdateFinish, ui->populationLabel, [=](){
        ui->populationLabel->setText("Population: " + QString::number(m_boardPanel->GetPopulationCount()));
    });
    connect(ui->speedSlider, &QSlider::valueChanged, m_boardPanel, &GameOfLifePanel::GameSpeedChange);
    connect(ui->speedSlider, &QSlider::valueChanged, [=](int value){
        ui->speedLabel->setText("FPS: " + QString::number(value));
    });
    connect(ui->helpButton, &QPushButton::clicked, [=](){
        QMessageBox::information(NULL, "Help button",
        tooltip, QMessageBox::Ok);
    });
    connect(ui->nextButton, &QPushButton::clicked, m_boardPanel, &GameOfLifePanel::NextStep);
    connect(ui->seedEditor, &QTextEdit::textChanged, [=](){
        QString seedStr = ui->seedEditor->toPlainText();
        m_boardPanel->UpdateSeed(seedStr);
    });
    //init
    ui->boardSizeLabel->setText(
        "Board size: " + QString::number(m_boardPanel->GetNumberOfRow())
        + "x" + QString::number(m_boardPanel->GetNumberOfColumn())
        );

    ui->speedSlider->setMinimum(MIN_GAME_SPEED);
    ui->speedSlider->setMaximum(MAX_GAME_SPEED);
    ui->speedSlider->setValue(GAME_SPEED_DEFAULT);

    ui->helpButton->setToolTip(tooltip);
}

MainWindow::~MainWindow()
{
    delete m_boardPanel;
    delete ui;
}
