#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGomoku.h"
#include "BoardScene.h"
#include "StaticDefinition.h"
#include "Alpha-Beta.h"
#include "Robot.h"


class QtGomoku : public QMainWindow
{
	Q_OBJECT

public:
	QtGomoku(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGomokuClass ui;
	BoardScene * m_scene;
	QPixmap * WhiteStone;
	QPixmap * BlackStone;
	//AiAgent *m_ai;
	Robot * robot;
public:
	Color HumanColor = black;	//����ִ������ɫ����
	Color AiColor = white;		//Aiִ������ɫ����
	Player CurrentTurn = Human; //��ǰ�ֵ�˭����
	Color BoardMap[15][15];		//�������,�������ֻ������������ӵ�ʱ���ж��Ƿ�Ϸ�,���ж���Ϸ�Ƿ����

private:
	void UpdateWholeBoardView();//���ݵ�ǰ�������ˢ����������
	void PutDownStone(int x,int y);//����
	bool isGameOver(int x,int y);//�ж���Ϸ�Ƿ���Ϊ�ո����µ�������Ӷ�����
public slots:
	void OnMouseReleaseOnBoardSense(QPoint *pos);//����������Ͽ��ͷ�
	void OnAiComplete(POINT * pos);
signals:
	void IsTimeForAiToCalculate(POINT*);//����ʱ����������ӵ�
};