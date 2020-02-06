#include "serialterminal.h"
#include "ui_serialterminal.h"
#include <QtCore>
#include <QtWidgets>
#include <QDebug>
#include <QSerialPortInfo>
#include <QDateTime>

SerialTerminal::SerialTerminal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialTerminal)
{
    ui->setupUi(this);
    this->device = new QSerialPort(this);
    ui->pushButtonConnect->setText("Connect");
    ui->pushButtonDisconnect->setText("Disconnect");
    ui->pushButtonSearch->setText("Search");
    ui->pushButtonClean->setText("Clean");
    ui->pushButtonConnect->setDisabled(false);
    ui->pushButtonDisconnect->setDisabled(true);
    ui->labelBaudrate->setText("Baudrate: ");
    fillBaudrateComboBox();
}

SerialTerminal::~SerialTerminal()
{
    delete ui;
}

void SerialTerminal::on_pushButtonSearch_clicked()
{
    this->addToLogs("Searching for devices");
    QList<QSerialPortInfo> devices;
    devices = QSerialPortInfo::availablePorts();
    if (devices.count() > 0) {
        for (int i = 0; i < devices.count(); ++i) {
            this->addToLogs("Found device: " + devices.at(i).portName()
                            + devices.at(i).manufacturer());
            ui->comboBoxDevices->addItem(devices.at(i).portName()
                                         + " "
                                         + devices.at(i).manufacturer());
        }
    } else {
        this->addToLogs("No devices found");
    }

}

void SerialTerminal::addToLogs(QString message)
{
    QString currentDateTime = QDateTime::currentDateTime()
            .toString("yyyy.MM.dd hh:mm:ss");
    ui->textEditLogs->append(currentDateTime + " " + message);
}

void SerialTerminal::fillBaudrateComboBox()
{
    ui->comboBoxBaudrate->addItem(QString::number(9600), QVariant(9600));
    ui->comboBoxBaudrate->addItem(QString::number(19200), QVariant(19200));
    ui->comboBoxBaudrate->addItem(QString::number(38400), QVariant(38400));
    ui->comboBoxBaudrate->addItem(QString::number(57600), QVariant(57600));
    ui->comboBoxBaudrate->addItem(QString::number(115200), QVariant(115200));
}

void SerialTerminal::on_pushButtonConnect_clicked()
{
    if (ui->comboBoxDevices->count() == 0) {
        this->addToLogs("No devices found");
    }

    QString portName = ui->comboBoxDevices->currentText().split(" ").first();
    this->addToLogs("Chosen port: " + portName);
    this->device->setPortName(portName);

    if (!device->isOpen()) {
        if (device->open(QSerialPort::ReadWrite)) {
            this->device->setBaudRate(ui->comboBoxBaudrate->
                                      currentData().toInt());
            this->device->setDataBits(QSerialPort::Data8);
            this->device->setParity(QSerialPort::NoParity);
            this->device->setStopBits(QSerialPort::OneStop);
            this->device->setFlowControl(QSerialPort::NoFlowControl);
            connect(this->device, SIGNAL(readyRead()), this, SLOT(readFromPort()));
            this->addToLogs("Serial port opened");
            ui->pushButtonConnect->setDisabled(true);
            ui->comboBoxDevices->setDisabled(true);
            ui->comboBoxBaudrate->setDisabled(true);
            ui->pushButtonDisconnect->setDisabled(false);
        } else {
            this->addToLogs("Opening failed");
        }
    } else {
        this->addToLogs("Port is already open");
    }
}

void SerialTerminal::on_pushButtonDisconnect_clicked()
{
    if (device->isOpen()) {
        device->close();
        addToLogs("Closed port successfull");
        ui->pushButtonConnect->setDisabled(false);
        ui->comboBoxDevices->setDisabled(false);
        ui->comboBoxBaudrate->setDisabled(false);
        ui->pushButtonDisconnect->setDisabled(true);
    } else {
        addToLogs("Port is not opened");
    }
}

void SerialTerminal::readFromPort()
{
    while (device->canReadLine()) {
        QString line = device->readLine();
        QString terminator = "\r";
        int pos = line.lastIndexOf(terminator);
        addToLogs(line.left(pos));
    }
}

void SerialTerminal::on_pushButtonClean_clicked()
{
    ui->textEditLogs->clear();
}
