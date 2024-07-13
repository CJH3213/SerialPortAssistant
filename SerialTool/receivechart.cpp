#include "receivechart.h"
#include "ui_receivechart.h"
#include <QRandomGenerator>
#include <QValidator>
#include "protocol.h"

ReceiveChart::ReceiveChart(MainWidget *baseWidget, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ReceiveChart)
{
    ui->setupUi(this);
    setWindowTitle("串口示波器");

    mFirstTime = QDateTime::currentDateTime();

    InitChart();
    InitDials();

    connect(baseWidget, SIGNAL(sendReceiveBytes(QByteArray)), this, SLOT(ReadSerialData(QByteArray)));
    // for(int i = 0; i< 60; i++)
    //     mSeries->append(mTimeCount++, QRandomGenerator::global()->bounded(64));
}

ReceiveChart::~ReceiveChart()
{
    delete ui;
}

void ReceiveChart::ReadSerialData(QByteArray bytes)
{
    if(mIsRunning == false)
        return;

    QDateTime nowTime = QDateTime::currentDateTime();
    double secs = mFirstTime.msecsTo(nowTime) / 1000.0;

    if(secs > mAxisX->max())
    {
        // 单次触发，显示满了停止刷新
        if(mIsSingleTriggerMode == true)
        {
            on_mRunOrStopButton_clicked();
            on_mSingleButton_clicked();
            return;
        }
        mLastTime = nowTime;
        SetChartHorizontalRange(ui->mHorizontalScaleLineEdit->text().toDouble(),
                                ui->mHorizontalPositionLineEdit->text().toDouble());
    }

    // 不需要解码
    if(mIsDecodeMode == false)
    {
        for(int i = 0; i< bytes.size(); i++)
        {
            mSeries->append(secs + i*0.001, bytes[i]);
        }
        return;
    }

    // 以下为解码
    mProtocol.InputNewData(bytes);
    auto decodeBytes = mProtocol.GetDecodedList();

    foreach (auto bytes, decodeBytes)
    {
        // 操作码为0xF0时才绘制波形
        if((uint8_t)bytes[0] != 0x0F || bytes.size() < 6)
            continue;

        QString name = "Serie_" + QString::number((uint8_t)bytes[1]);
        bool cvtOk = false;
        float value = Protocol::BytesToFloat(bytes.mid(2), &cvtOk);
        if(cvtOk == false)
            continue;

        QLineSeries *series = mSeriesMap.value(name, nullptr);
        if(series == nullptr)
        {
            if(mSeriesMap.count() > 12)
                continue;

            series = new QLineSeries;
            series->setName(name);
            QColor color((Qt::GlobalColor)(mSeriesMap.count()+4));   // map的序号去索引颜色
            series->setColor(color);
            series->setPen(QPen(color, 2));
            mChart->addSeries(series);  // 必须先将线添加到图表再设置轴，
            series->attachAxis(mAxisX);
            series->attachAxis(mAxisY);
            mSeriesMap[name] = series;
        }
        series->append(secs, value);
    }
}

void ReceiveChart::InitChart()
{
    // 对widget设置chart
    mChart = new QChart;
    ui->mChartWidget->setChart(mChart);
    ui->mChartWidget->setRenderHint(QPainter::Antialiasing);    // 抗锯齿
    ui->mChartWidget->setRubberBand(QChartView::RectangleRubberBand);  // 缩放
    ui->mChartWidget->setDragMode(QGraphicsView::ScrollHandDrag);   // 拖拽
    // 轴
    //设置X轴属性
    mAxisX = new QValueAxis;
    mChart->addAxis(mAxisX, Qt::AlignBottom);
    mAxisX->setRange(0, 60);
        //设置Y轴属性
    mAxisY = new QValueAxis;
    mChart->addAxis(mAxisY, Qt::AlignLeft);
    mAxisY->setRange(-128, 127);

    // 曲线
    mSeries = new QLineSeries;
    mSeries->setName("Direct");
    mSeries->setColor(Qt::red);
    mSeries->setPen(QPen(Qt::red, 2));
    mChart->addSeries(mSeries);
    mSeries->attachAxis(mAxisX);
    mSeries->attachAxis(mAxisY);
}

void ReceiveChart::InitDials()
{
    QValidator *validator = new QDoubleValidator(this);
    ui->mVerticalScaleLineEdit->setValidator(validator);
    ui->mVerticalPositionLineEdit->setValidator(validator);
    ui->mHorizontalScaleLineEdit->setValidator(validator);
    ui->mHorizontalPositionLineEdit->setValidator(validator);

    on_mVerticalScaleDial_valueChanged(ui->mVerticalScaleDial->value());
    on_mVerticalPositionDial_valueChanged(ui->mVerticalPositionDial->value());
    on_mHorizontalScaleDial_valueChanged(ui->mHorizontalScaleDial->value());
    on_mHorizontalPositionDial_valueChanged(ui->mHorizontalPositionDial->value());
}

void ReceiveChart::SetChartVerticalRange(qreal scale, qreal offset)
{
    mAxisY->setRange(-scale/2+offset, scale/2+offset);
}

void ReceiveChart::SetChartHorizontalRange(qreal scale, qreal offset)
{
    int secs = mFirstTime.secsTo(mLastTime);
    offset += secs;
    mAxisX->setRange(offset, scale+offset);
}

void ReceiveChart::on_mVerticalScaleDial_valueChanged(int value)
{
    ui->mVerticalScaleLineEdit->setText(QString::number(value));
    SetChartVerticalRange(ui->mVerticalScaleLineEdit->text().toDouble(),
                          ui->mVerticalPositionLineEdit->text().toDouble());
}


void ReceiveChart::on_mVerticalPositionDial_valueChanged(int value)
{
    ui->mVerticalPositionLineEdit->setText(QString::number(value));
    SetChartVerticalRange(ui->mVerticalScaleLineEdit->text().toDouble(),
                          ui->mVerticalPositionLineEdit->text().toDouble());
}


void ReceiveChart::on_mHorizontalScaleDial_valueChanged(int value)
{
    ui->mHorizontalScaleLineEdit->setText(QString::number(value));
    SetChartHorizontalRange(ui->mHorizontalScaleLineEdit->text().toDouble(),
                          ui->mHorizontalPositionLineEdit->text().toDouble());
}


void ReceiveChart::on_mHorizontalPositionDial_valueChanged(int value)
{
    ui->mHorizontalPositionLineEdit->setText(QString::number(value));
    SetChartHorizontalRange(ui->mHorizontalScaleLineEdit->text().toDouble(),
                            ui->mHorizontalPositionLineEdit->text().toDouble());
}


void ReceiveChart::on_mVerticalScaleLineEdit_editingFinished()
{
    int value = ui->mVerticalScaleLineEdit->text().toDouble();
    ui->mVerticalScaleDial->setValue(value);
}


void ReceiveChart::on_mVerticalPositionLineEdit_editingFinished()
{
    int value = ui->mVerticalPositionLineEdit->text().toDouble();
    ui->mVerticalPositionDial->setValue(value);
}


void ReceiveChart::on_mHorizontalScaleLineEdit_editingFinished()
{
    int value = ui->mHorizontalScaleLineEdit->text().toDouble();
    ui->mHorizontalScaleDial->setValue(value);
}


void ReceiveChart::on_mHorizontalPositionLineEdit_editingFinished()
{
    int value = ui->mHorizontalPositionLineEdit->text().toDouble();
    ui->mHorizontalPositionDial->setValue(value);
}


void ReceiveChart::on_mRunOrStopButton_clicked()
{
    mIsRunning = !mIsRunning;

    QString style = mIsRunning ? "background-color: rgb(205, 255, 205);" : "background-color: rgb(255, 205, 205);";
    ui->mRunOrStopButton->setStyleSheet(style);
}


void ReceiveChart::on_mSingleButton_clicked()
{
    mIsSingleTriggerMode = !mIsSingleTriggerMode;

    QString style = mIsSingleTriggerMode ? "background-color: rgb(205, 255, 205);" : "";
    ui->mSingleButton->setStyleSheet(style);


    if(mIsSingleTriggerMode == true)
    {
        mLastTime = QDateTime::currentDateTime();
        SetChartHorizontalRange(ui->mHorizontalScaleLineEdit->text().toDouble(),
                                ui->mHorizontalPositionLineEdit->text().toDouble());
        // 启用单次触发时，自动开启刷新
        if(mIsRunning == false)
            on_mRunOrStopButton_clicked();
    }
}


void ReceiveChart::on_mDirectOrDecodeButton_clicked()
{
    mIsDecodeMode = !mIsDecodeMode;

    QString style = mIsDecodeMode ? "background-color: rgb(255, 238, 205);" : "";
    ui->mDirectOrDecodeButton->setStyleSheet(style);
}

