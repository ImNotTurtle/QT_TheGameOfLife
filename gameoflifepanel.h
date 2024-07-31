#ifndef GAMEOFLIFEPANEL_H
#define GAMEOFLIFEPANEL_H

#include <QWidget>
#include <QTimer>
#include <tuple>
#include <map>


#define MIN_GAME_SPEED                  1//1 FPS
#define MAX_GAME_SPEED                  450 //450 FPS
#define GAME_SPEED_DEFAULT              MAX_GAME_SPEED

class GameOfLifeData{
public:
    enum STATE{
        ALIVE,
        DEAD,
        DEFAULT = DEAD
    };
    GameOfLifeData();

    void SetState(STATE state);
    STATE GetState(void);
    void Live(void);
    void Die(void);
    bool IsLive(void);
    bool IsDead(void);
    QColor GetColor(void);
    static std::map<STATE, QColor> s_colorMap;
private:
    STATE m_state;
};


using GameOfLifeBoard = QVector<QVector<GameOfLifeData>>;
using Coord = std::tuple<int, int>;

class GameOfLifePanel : public QWidget
{
    Q_OBJECT
public:
    explicit GameOfLifePanel(QWidget *parent = nullptr);

    void CreateBoard(const int& row, const int& col);
    void ResizeBoard(const int& row, const int& col);

    void NextGeneration(void);
    int GetGenerationCount(void);
    int GetPopulationCount(void);

    //return the data of the neighbours of a cell
    QVector<GameOfLifeData> GetNeighbours(const int& x, const int& y);
    //apply the game of life rules on a board then return the new board with rules applied
    GameOfLifeBoard ApplyRules(GameOfLifeBoard board);


    int GetNumberOfRow(void);
    int GetNumberOfColumn(void);

    void SetGenerationSpeed(int speed);

signals:
    void UpdateFinish(void);
public slots:
    void timerEvent();
    void StartGame(void);
    void PauseGame(void);
    void ResetGame(void);
    void NextStep(void);
    void GameSpeedChange(int speed);
    void UpdateSeed(QString str);
protected:
    void paintEvent(QPaintEvent* event) override;

private:
    GameOfLifeBoard m_gameBoard;
    QTimer m_timer;
    QVector<Coord> m_setupList;
    int m_generationCount;
    int m_populationCount;

    bool IsValidXY(const int &x, const int& y);
    void ApplySeed(void);
};

#endif // GAMEOFLIFEPANEL_H
