#include "mainwindow.h"
#include "./ui_mainwindow.h"

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
    //init
    ui->boardSizeLabel->setText(
        "Board size: " + QString::number(m_boardPanel->GetNumberOfRow())
        + "x" + QString::number(m_boardPanel->GetNumberOfColumn())
        );
    ui->speedSlider->setMinimum(MIN_GAME_SPEED);
    ui->speedSlider->setMaximum(MAX_GAME_SPEED);

}

MainWindow::~MainWindow()
{
    delete m_boardPanel;
    delete ui;
}
