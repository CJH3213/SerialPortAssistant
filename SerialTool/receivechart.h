#ifndef RECEIVECHART_H
#define RECEIVECHART_H

#include <QWidget>
#include "mainwidget.h"
#include <QtCharts>
#include "protocol.h"

namespace Ui {
class ReceiveChart;
}

class ReceiveChart : public QWidget
{
    Q_OBJECT

public:
    explicit ReceiveChart(MainWidget* baseWidget, QWidget *parent = nullptr);
    ~ReceiveChart();


private slots:
    void ReadSerialData(QByteArray bytes);

    void on_mVerticalScaleDial_valueChanged(int value);

    void on_mVerticalPositionDial_valueChanged(int value);

    void on_mHorizontalScaleDial_valueChanged(int value);

    void on_mHorizontalPositionDial_valueChanged(int value);

    void on_mVerticalScaleLineEdit_editingFinished();

    void on_mVerticalPositionLineEdit_editingFinished();

    void on_mHorizontalScaleLineEdit_editingFinished();

    void on_mHorizontalPositionLineEdit_editingFinished();

    void on_mRunOrStopButton_clicked();

    void on_mSingleButton_clicked();

    void on_mDirectOrDecodeButton_clicked();

private:
    Ui::ReceiveChart *ui;
    QChart *mChart;
    QValueAxis *mAxisX;
    QValueAxis *mAxisY;
    QLineSeries *mSeries;
    QMap<QString, QLineSeries*> mSeriesMap;
    // QChartView *mChartView;
    int mAxisXRange;
    bool mIsRunning = true;
    bool mIsSingleTriggerMode = false;
    bool mIsDecodeMode = false;
    QDateTime mFirstTime;
    QDateTime mLastTime;
    Protocol mProtocol;

    void InitChart();
    void InitDials();

    void SetChartVerticalRange(qreal scale, qreal offset);
    void SetChartHorizontalRange(qreal scale, qreal offset);

};

#endif // RECEIVECHART_H
