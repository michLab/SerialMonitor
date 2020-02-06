#ifndef SERIALTERMINAL_H
#define SERIALTERMINAL_H

#include <QDialog>
#include <QSerialPort>

namespace Ui {
class SerialTerminal;
}

class SerialTerminal : public QDialog
{
    Q_OBJECT

public:
    explicit SerialTerminal(QWidget *parent = nullptr);
    ~SerialTerminal();

private slots:
    void on_pushButtonSearch_clicked();

    void on_pushButtonConnect_clicked();

    void on_pushButtonDisconnect_clicked();

    void readFromPort();

    void on_pushButtonClean_clicked();

private:
    Ui::SerialTerminal *ui;
    QSerialPort *device;


    void addToLogs(QString message);
    void fillBaudrateComboBox();
};

#endif // SERIALTERMINAL_H
