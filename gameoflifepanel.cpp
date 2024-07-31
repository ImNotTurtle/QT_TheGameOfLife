#include "gameoflifepanel.h"
#include <QPainter>
#include <QMessageBox>
#include "shareddata.h"


static int Map(int inp, int inpMin, int inpMax, int outMin, int outMax){
    return outMin + (inp - inpMin) * (outMax - outMin) / (inpMax - inpMin);
}


std::map<GameOfLifeData::STATE, QColor> GameOfLifeData::s_colorMap = {
    {GameOfLifeData::STATE::ALIVE, QColor(255, 255, 255)},
    {GameOfLifeData::STATE::DEAD, QColor(0, 0, 0)}
};


GameOfLifeData::GameOfLifeData(){
    m_state = DEFAULT;
}

void GameOfLifeData::SetState(STATE state){
    m_state = state;
}
void GameOfLifeData::Live(void){
    this->SetState(ALIVE);
}

void GameOfLifeData::Die(void){
    this->SetState(DEAD);
}
bool GameOfLifeData::IsLive(void){
    return this->GetState() == ALIVE;
}
bool GameOfLifeData::IsDead(void){
    return this->GetState() == DEAD;
}

GameOfLifeData::STATE GameOfLifeData::GetState(void){
    return m_state;
}
QColor GameOfLifeData::GetColor(void){
    try{
        return s_colorMap.at(m_state);
    }
    catch(std::out_of_range){

    }
    return s_colorMap.at(DEFAULT);
}






GameOfLifePanel::GameOfLifePanel(QWidget *parent)
    : QWidget{parent}
{
    m_timer.setParent(this);
    m_timer.setInterval(GAME_SPEED_DEFAULT);
    connect(&m_timer, &QTimer::timeout, this, &GameOfLifePanel::timerEvent);

    this->setBackgroundRole(QPalette::Dark);
    this->setAutoFillBackground(true);
}

void GameOfLifePanel::CreateBoard(const int& row, const int& col){
    m_generationCount = 0;
    m_populationCount = 0;

    //resize the board
    this->ResizeBoard(row, col);

    //re-construct the data
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            m_gameBoard[i][j] = GameOfLifeData();
        }
    }
    //apply the seed as initial state of the board
    this->ApplySeed();

}
void GameOfLifePanel::ResizeBoard(const int& row, const int& col){
    m_gameBoard.resize(row);
    for(auto &r : m_gameBoard){
        r.resize(col);
    }
}
void GameOfLifePanel::StartGame(void){
    m_timer.start();
}
void GameOfLifePanel::PauseGame(void){
    m_timer.stop();
}
void GameOfLifePanel::ResetGame(void){
    m_timer.stop();
    //re init the board
    this->CreateBoard(this->GetNumberOfRow(), this->GetNumberOfColumn());
}
void GameOfLifePanel::NextStep(void){
    this->NextGeneration();

}
void GameOfLifePanel::GameSpeedChange(int speed){
    this->SetGenerationSpeed(speed);
}
void GameOfLifePanel::UpdateSeed(QString str){
    //reset the previous setup list before apply new list
    for(auto& item : m_setupList){
        int x = get<0>(item);
        int y = get<1>(item);
        m_gameBoard[x][y].Die();
    }
    m_setupList.clear();
    m_setupList.resize(0);
    //split the string by \n
    QVector<QString> list = SharedData::Split(str, "\n");
    for(auto &coord : list){
        //check if the coord is valid
        //1. split by ,
        auto coordList = SharedData::Split(coord, ",");
        //this should contains 2 value
        if(coordList.size() == 2){
            //2.try to convert to number
            try{
                std::string temp = coordList[0].toStdString();
                int x = std::stoi(temp);
                temp = coordList[1].toStdString();
                int y = std::stoi(temp);
                //3. apply if convert success
                if(this->IsValidXY(x, y)){
                    m_setupList.push_back({x, y});
                }
            }
            catch(std::invalid_argument){

            }
            catch(std::out_of_range){

            }
            catch(std::exception &e){
                qDebug() << "In GameOfLifePanel::UpdateSeed(): " << e.what();
            }
        }
    }
    //apply the setup list
    this->ApplySeed();
    this->update();
}

void GameOfLifePanel::NextGeneration(void){
    //make a copy of the board as the next generation and apply the rules
    m_generationCount++;
    auto nextGeneration = this->ApplyRules(m_gameBoard);

    //apply the next generation to the current board
    m_gameBoard = nextGeneration;
    this->update();

    emit UpdateFinish();
}
int GameOfLifePanel::GetGenerationCount(void){
    return m_generationCount;
}

int GameOfLifePanel::GetPopulationCount(void){
    return m_populationCount;
}

QVector<GameOfLifeData> GameOfLifePanel::GetNeighbours(const int& x, const int& y){
    QVector<GameOfLifeData> retList;

    //neighbour offset : 8 directions
    QVector<int> dx = {1,0,0,-1,1,-1,-1,1};
    QVector<int> dy = {0,1,-1,0,1,1,-1,-1};
    for(int i = 0; i< dx.size(); i++){
        int neiX = x + dx[i];
        int neiY = y + dy[i];
        if(this->IsValidXY(neiX, neiY)){
            retList.push_back(m_gameBoard[neiX][neiY]);
        }
    }

    return retList;
}

GameOfLifeBoard GameOfLifePanel::ApplyRules(GameOfLifeBoard board){
    /*
     * Here is the rules
     * 1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
     * 2. Any live cell with two or three live neighbours lives on to the next generation.
     * 3. Any live cell with more than three live neighbours dies, as if by overpopulation.
     * 4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
    */
    GameOfLifeBoard retBoard = board;
    m_populationCount = 0;

    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            int liveNeighbourCount = 0;
            GameOfLifeData currentCell = board[i][j];
            auto neighbourList = this->GetNeighbours(i, j);
            for(auto nei : neighbourList){
                if(nei.IsLive()){
                    liveNeighbourCount++;
                }
            }
            //apply the rules
            if(currentCell.IsLive()){
                if((liveNeighbourCount < 2) || (liveNeighbourCount > 3)){
                    currentCell.Die();
                }
            }
            else if(currentCell.IsDead()){
                if((liveNeighbourCount == 3)){
                    currentCell.Live();
                }
            }
            //assign the current cell to the retboard
            if(currentCell.IsLive()){
                m_populationCount++;
            }
            retBoard[i][j] = currentCell;
        }
    }

    return retBoard;
}
int GameOfLifePanel::GetNumberOfRow(void){
    return m_gameBoard.size();
}
int GameOfLifePanel::GetNumberOfColumn(void){
    if(m_gameBoard.size() > 0){
        return m_gameBoard[0].size();
    }
    return 0;
}
void GameOfLifePanel::SetGenerationSpeed(int speed){
    int newSpeed = Map(speed, MIN_GAME_SPEED, MAX_GAME_SPEED, 1000, 10000 / MAX_GAME_SPEED);
    m_timer.setInterval(newSpeed);
}

void GameOfLifePanel::paintEvent(QPaintEvent* event){
    auto panel = this;
    QPainter painter(panel);

    //draw the board
    try{
        int row = this->GetNumberOfRow();
        int col = this->GetNumberOfColumn();
        /*the division below will leave the board with space (not divisible value)
         * to fix that: calculate the width which is left by the division, called padW
         * so there should be the number of padW cell increase the width by 1
         * here is a example:
         * if width = 764, cols = 100, cellW = 7, leave 64 pixel in the width
         * so 64 pixel should have the size of cellW + 1 to fill the gap
         * this also apply to the height
        */

        int cellW = panel->size().width() / col;
        int cellH = panel->size().height() / row;
        int padH = panel->size().height() % row;
        QPoint pos;
        for(int i = 0; i < row; i++){
            pos.setX(0);
            //the number of padW cells reset for every row
            int padW = panel->size().width() % col;
            for(int j = 0; j < col; j++){
                int width = cellW;
                int height = cellH;
                //do we achive the number of padW cells ?
                if(padW > 0){
                    padW--;
                    width++;
                    //padding with
                    pos += QPoint(1, 0);
                }
                if(padH > 0){
                    height++;
                }

                painter.setPen(QColor(115, 112, 111));
                painter.setBrush(m_gameBoard[i][j].GetColor());
                painter.drawRect(pos.x(), pos.y(), width, height);
                pos.setX(pos.x() + cellW);
            }
            pos.setY(pos.y()  + cellH);
            if(padH > 0){
                padH--;
                //padding height
                pos += QPoint(0, 1);
            }
        }
    }
    catch(std::logic_error e){
        QMessageBox::critical(this, "Error", e.what());
    }
}

bool GameOfLifePanel::IsValidXY(const int &x, const int& y){
    return 0 <= x && x < this->GetNumberOfRow() && 0 <= y && y < this->GetNumberOfColumn();
}
void GameOfLifePanel::ApplySeed(void){
    for(auto &item : m_setupList){
        int x = get<0>(item);
        int y = get<1>(item);
        m_gameBoard[x][y].Live();
    }
    this->update();
}


void GameOfLifePanel::timerEvent(){
    this->NextGeneration();
}
